/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:44 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/02 01:28:33 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	conversionchar(const char *str, va_list ap, t_result *r, t_format *f)
{
	char	c;
	char	*s;

// parce que va-arg est une macro qui est remplacee a la compilation
// donc elle n a pas d adresse au prealable, alors que c oui
	if (str[0] == 'c')
	{
		c = (char)(va_arg(ap, int));
		write(1, &c, 1);
		r->lentotal++;
	}
	else if (str[0] == 's')
	{
		if (f->precision > -1 && f->flag == 's')
			f->ifwidth = 0;
		s = va_arg(ap, char *);
		r->lentotal += ft_strlen(s);
		if (f->ifwidth == 1)
			s = handling_field(s, f);
		if (f->precision > -1)
			s = s_withpoint(s, f);
		ft_putstr_fd(s, 1);
	}
	else
		r->error = 1;
}

void	direction(const char *str, va_list ap, t_result *r, t_format *f)
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
		//printf("f->ifwidth = %d\n", f->ifwidth);
	}
	//printf("str : %s et i = %d\n", str, i);

	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*') 
		{
			f->precision = va_arg(ap, int);
			if (f->precision < 0)
				f->precision = 1;
			i++;
			//printf("precision *  = %d\n", f->width);
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
	}
	//printf("f->precision = %d\n, i = %d et str : %s\n", f->precision, i, str);
	if (ischar(str[i], "cs") == 1)
	{
		conversionchar(str, ap, r, f);
		f->flag = str[i];
	}
	else if (ischar(str[i], "pdiouxX") == 1)
	{
		f->flag = str[i];
		witchbase(str[i], f);
		conversion_digit(&str[i], ap, r, f);
	}
	else if (str[i] == '%')
		write(1, "%", 1);
	else
		r->error = 1;

}

void	checkflags(const char *str, va_list ap, t_result *r, t_format *f)
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
	//printf("flagpoint : %d\n", f->flagpoint);
	i = 0;
	if (ischar(str[i], "-0*") == 1)
	{
		while (ischar(str[i], "-0*") == 1)
		{
			if (str[i] == '-')
				f->flagminus = 1;
			else if (str[i] == '0')
				f->flagzero = 1;
			else if (str[i] == '*')
			{
				f->width = va_arg(ap, int);
				//printf("width = %d\n", f->width);
				f->ifwidth = 1;
			}
			i++;
		}
	}
	if (f->flagzero == 1 && (f->flagminus == 1 || f->flagpoint == 1
		|| f->width < 0))
		f->flagzero = 0;
	//printf("&str[i] : %s\n", &str[i]);
	direction(&str[i], ap, r, f);
}


void	readstring(const char *str, t_result *r, va_list ap)
{
	t_format	f;
	int			i;
	int			j;

	i = 0;
	while (str[i] != '\0' && r->error == 0)
	{
		if (str[i] == '%' && str[i + 1])
		{
			j = 1;
			ft_bzero(&f, sizeof(t_format));
			//f.width = -1;
			f.precision = -1;
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
		//printf("i = %d et j = %d\n", i, j);
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
