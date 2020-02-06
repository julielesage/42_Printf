/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:34:31 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/04 22:05:02 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>


char		*modify_pointer(char *result)
{
	//char	*strtrim;
	char	*address;

	//strtrim = ft_substr(result, 8, 8);
	address = "0x";
	address = ft_strcat(address, result);
	//free (strtrim);
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
	if (c == 'o') // a voir si c est pas en unsigned aussi
		f->basestr = "01234567";
	f->basenb = (long)ft_strlen(f->basestr);
}

void		conversion_digit(const char *str, va_list ap, t_result *r,
				t_format *f)
{
	char	*result;

	result = "";

	//printf("str conversion digit : %s\n", str);
	if (f->basenb < 2 || f->basenb > 16)
		r->error = 1;
	if (f->indic == 'u')
		result = ft_itoa_base_u((unsigned int)va_arg(ap, int), f);
	else
		result = ft_itoa_base(va_arg(ap, int), f);
	//printf("malloc result dans itoa-base, result =  %s\n", result);
	if (*str == 'p')
		result = modify_pointer(result);
	//printf("result apres conversion : %s\n", result);
	//printf("flagpoint : %d\n", f->flagpoint);
	//printf("precision : %d\n", f->precision);
	if (f->flagpoint == 1 )
		result = withpoint(result, f);
	//printf("result = %s la d'une strlen de %zu\n", result, f->precision, (int)ft_strlen(result));
	//printf("f->ifwidth = %d\n", f->ifwidth);
	if (f->width == 0 && !result)
		result = NULL;
	else if (f->ifwidth == 1)
	{
		//printf("coucou\n");
		result = handling_field(result, f);
	}
	//printf("result : %s la apres width = %d dune strlen de %zu\n", result, f->width, ft_strlen(result));
	if (result)
	{
		ft_putstr_fd(result, 1);
		r->lentotal += ft_strlen(result);
		free (result);
	}

	//f->flaglen += 1;
	//printf("flaglen ; %d\n", f->flaglen);
	//printf("lentotal : %d\n", r->lentotal);
	//printf("free resultat final\n");
}




//verifier si p est toujours unsigned et quelle memoire max il a ?
// pb avec p a gerer :
//
// test void *p: 0x7ffee65c0960
//test perso void *p : ffffffffe65c0960
//substr special pour p
