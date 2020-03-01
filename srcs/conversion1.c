/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:34:31 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/18 23:29:06 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	conversionstr(va_list ap, t_res *r, t_for *f)
{
	char *s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	if (f->flagpoint == 1 && f->precision == 0)
		s = NULL;
	else if (f->flagpoint == 1)
		s = s_withpoint(s, f);
	if (f->ifwidth == 1)
		s = handling_field(s, f);
	r->lentotal += ft_strlen(s);
	write(1, s, ft_strlen(s));
}

void	witchbase(char c, t_for *f)
{
	if (c == 'd' || c == 'u' || c == 'i')
		f->basestr = "0123456789";
	if (c == 'p' || c == 'x')
		f->basestr = "0123456789abcdef";
	if (c == 'x' || c == 'u' || c == 'X')
		f->indic = 'u';
	if (c == 'X')
		f->basestr = "0123456789ABCDEF";
	if (c == 'o')
		f->basestr = "01234567";
	f->basenb = (long)ft_strlen(f->basestr);
}

void	re_direction(const char *str, va_list ap, t_res *r, t_for *f)
{
	int i;

	i = 0;
	if (ischar(str[i], "cspdiouxX") == 1)
		f->flag = str[i];
	if (str[i] == 'c')
		conversionchar(ap, r, f);
	else if (str[i] == '%')
		percentchar('%', r, f);
	else if (str[i] == 's')
		conversionstr(ap, r, f);
	else if (ischar(str[i], "pdiouxX") == 1)
	{
		witchbase(str[i], f);
		conversion_digit(&str[i], ap, r, f);
	}
	else
		r->error = 1;
}

int		strchiffres(const char *str, int len)
{
	char	*width;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!(width = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (ischar(str[i], "cspdiouxX%") == 0)
	{
		width[i] = str[i];
		i++;
	}
	width[i] = '\0';
	result = ft_atoi(width);
	free(width);
	return (result);
}

int		flagpoint(const char *str, va_list ap, t_for *f)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (str[i] == '*')
	{
		f->precision = va_arg(ap, int);
		i++;
	}
	else if (ischar(str[i], "0123456789") == 1)
	{
		while (ischar(str[i], "0123456789") == 1)
		{
			i++;
			j++;
		}
		k = i - j;
		f->precision = strchiffres(&str[k], j);
	}
	return (i);
}
