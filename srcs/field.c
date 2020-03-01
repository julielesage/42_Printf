/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:39:57 by jlesage           #+#    #+#             */
/*   Updated: 2020/03/01 19:22:04 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*handling_field(char *result, t_for *f)
{
	char	*str;
	int		i;
	int		swap;

	i = 0;
	str = NULL;
	swap = f->width;
	if (f->width < 0)
		swap = -swap;
	if ((result && swap <= ((int)strlen(result))))
		return (result);
	else
	{
		if (result && f->flagzero == 1 && result[0] == '-')
			str = large_precision_minus(result, f->width, f);
		else if (f->flagminus == 1 || (f->flagminus == 0 && f->width < 0))
			str = ft_strdupiminus(result, f->width, f);
		else
			str = ft_strdupiplus(result, f);
		if (f->flag != 's')
			free(result);
	}
	return (str);
}

void	conversion_digit(const char *str, va_list ap, t_res *r, t_for *f)
{
	char	*result;

	result = "";
	if (f->indic == 'u')
		result = ft_itoa_base_u(va_arg(ap, unsigned int), f);
	else if (*str == 'p')
	{
		result = ft_itoa_base_p(va_arg(ap, unsigned long), f);
		result = modify_pointer(result);
	}
	else
		result = ft_itoa_base(va_arg(ap, int), f);
	if (f->flagpoint == 1)
		result = withpoint(result, f);
	if (f->width == 0 && !result)
		result = NULL;
	else if (f->ifwidth == 1)
		result = handling_field(result, f);
	if (result)
	{
		ft_putstr_fd(result, 1);
		r->lentotal += ft_strlen(result);
		free(result);
	}
}

void	lentotal_for_c(char *s, t_res *r, t_for *f)
{
	if (f->width == 0)
		r->lentotal++;
	else
		r->lentotal += f->width;
	free(s);
}

void	conversionchar(va_list ap, t_res *r, t_for *f)
{
	char	c;
	char	*s;

	c = (char)(va_arg(ap, int));
	if (f->ifwidth == 1 && !(c == 0 && (f->width == 0)))
	{
		s = malloc(2 * sizeof(char));
		s[0] = c;
		s[1] = '\0';
		s = handling_field(s, f);
		if (f->width < 0)
			f->width = -f->width;
		if (c == 0)
			write(1, s, f->width);
		else
			write(1, s, ft_strlen(s));
		lentotal_for_c(s, r, f);
	}
	else
	{
		write(1, &c, 1);
		r->lentotal++;
	}
}

void	percentchar(char c, t_res *r, t_for *f)
{
	char	*s;

	if (f->ifwidth == 1)
	{
		s = malloc(2 * sizeof(char));
		s[0] = c;
		s[1] = '\0';
		s = handling_field(s, f);
		if (f->width < 0)
			f->width = -f->width;
		if (c == 0)
			write(1, s, f->width);
		else
			write(1, s, ft_strlen(s));
		lentotal_for_c(s, r, f);
	}
	else
	{
		write(1, &c, 1);
		r->lentotal++;
	}
}
