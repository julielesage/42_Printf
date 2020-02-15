/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:34:31 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/15 17:02:51 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>


char		*modify_pointer(char *result)
{
	char	*address;

	address = "0x";
	address = ft_strcat(address, result);
	free (result);
	return (address);
}

void		witchbase(char c, t_format *f)
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

void		conversion_digit(const char *str, va_list ap, t_result *r,
				t_format *f)
{
	char	*result;

	result = "";
	if (f->basenb < 2 || f->basenb > 16)
		r->error = 1;
	if (f->indic == 'u')
		result = ft_itoa_base_u((unsigned int)va_arg(ap, int), f);
	else
		result = ft_itoa_base(va_arg(ap, int), f);
	if (*str == 'p')
		result = modify_pointer(result);
	if (f->flagpoint == 1 )
		result = withpoint(result, f);
	if (f->width == 0 && !result)
		result = NULL;
	else if (f->ifwidth == 1)
		result = handling_field(result, f);
	if (result)
	{
		ft_putstr_fd(result, 1);
		r->lentotal += ft_strlen(result);
		free (result);
	}
}
