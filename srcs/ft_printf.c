/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:44 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/18 21:14:11 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	direction(const char *str, va_list ap, t_res *r, t_for *f)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (ischar(str[i], ".cspdiouxX%") == 0)
		i++;
	if (i > 0)
	{
		f->ifwidth = 1;
		f->width = strchiffres(str, i);
	}
	if (str[i] == '.')
		i = i + 1 + (flagpoint(&str[i + 1], ap, f));
	if (f->flagzero == 1 && (f->flagminus == 1 || (f->flagpoint == 1
				&& f->precision > -1) || f->width < 0))
		f->flagzero = 0;
	re_direction(&str[i], ap, r, f);
}

int		checkflags_bis(const char *str, va_list ap, t_for *f)
{
	int i;

	i = 0;
	while (ischar(str[i], "-0*") == 1)
	{
		if (str[i] == '-')
			f->flagminus = 1;
		else if (str[i] == '0')
			f->flagzero = 1;
		else if (str[i] == '*')
		{
			f->width = va_arg(ap, int);
			f->ifwidth = 1;
		}
		i++;
	}
	return (i);
}

void	checkflags(const char *str, va_list ap, t_res *r, t_for *f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		r->error = 1;
	while (ischar(str[i], "pdcsiouxX%") == 0)
	{
		if (str[i] == '.')
			f->flagpoint = 1;
		i++;
	}
	i = 0;
	if (ischar(str[i], "-0*") == 1)
		i += checkflags_bis(&str[i], ap, f);
	direction(&str[i], ap, r, f);
}

void	readstring(const char *str, t_res *r, va_list ap)
{
	t_for		f;
	int			i;
	int			j;

	i = 0;
	while (str[i] != '\0' && r->error == 0)
	{
		if (str[i] == '%' && str[i + 1])
		{
			j = 1;
			ft_bzero(&f, sizeof(t_for));
			while (ischar(str[i + j], "cspdiouxX%") == 0)
				j++;
			checkflags(&str[i + 1], ap, r, &f);
			i = i + j;
		}
		else
		{
			write(1, &str[i], 1);
			r->lentotal++;
		}
		i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_res		r;

	va_start(ap, str);
	if (!str)
		return (-1);
	ft_bzero(&r, sizeof(t_res));
	readstring(str, &r, ap);
	if (r.error == 1)
		return (-1);
	va_end(ap);
	return (r.lentotal);
}
