/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:44 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/12 22:39:13 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	conversionchar(const char *str, va_list ap, t_result r, t_format *f)
{
	char c;

// parce que va-arg est une macro qui est remplacee a la compilation
// donc elle n a pas d adresse au prealable, alors que c oui
	if (str[0] == 'c')
	{
		c = (char)(va_arg(ap, int));
		write(1, &c, 1);
		f->flaglen += 1;
	}
	else if (str[0] == 's')
	{
		ft_putstr_fd(va_arg(ap, char *), 1);
		f->flaglen += 1;
	}
	else
		r.error = 1;
}

void	direction(const char *str, va_list ap, t_result r, t_format *f)
{
	int	i;

	i = 0;
	if (ischar(str[i], "cs") == 1)
		conversionchar(str, ap, r, f);
	else if (ischar(str[i], "pdiouxX") == 1)
	{
		witchbase(str[i], f);
		conversion_digit(str, ap, &r, f);
	}
	else if (str[i] == '%')
		write(1, "%", 1);
	else
		r.error = 1;
}

//si on envoie une struct avec &
//alors les modification  ne sont plus des points mais des -> va savoir pourquoi
void	checkflags(const char *str, va_list ap, t_result r, t_format *f)
{
	int	i;
	int	count;

	i = -1;
	count = -1;
	if (!str)
		r.error = 1;
	while (ischar(str[i++], "-0.*") == 1 || ischar(str[i], "0123456789") == 1)
	{
		if (str[i] == '-')
			f->flagminus = 1;
		if (str[i] == '0')
			f->flagzero = 1;
		if (str[i] == '.')
			f->flagpoint = 1;
		if (str[i] == '*')
			f->flagstar = 1;
		f->flaglen++;
	}
	direction(&str[i], ap, r, f);
}

void	readstring(const char *str, t_result *r, va_list ap)
{
	t_format	f;
	int			i;

	i = 0;
	while (str[i] && r->error == 0)
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_bzero(&f, sizeof(t_format));
			checkflags(&str[i + 1], ap, *r, &f);
			i = i + f.flaglen;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_result	r;

	va_start(ap, str);
	if (!str)
		return (-1);
	ft_bzero(&r, sizeof(t_result));
	readstring(str, &r, ap);
	if (r.error == 1)
		return (-1);
	va_end(ap);
	return (r.lentotal);
}
