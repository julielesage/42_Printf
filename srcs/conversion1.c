/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:34:31 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/12 22:44:40 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void		witchbase(char c, t_format *f)
{
	if (c == 'd' || c == 'u' || c == 'i')
		f->basestr = "0123456789";
	else if (c == 'p' || c == 'x')
		f->basestr = "0123456789abcdef";
	else if (c == 'X')
		f->basestr = "0123456789ABCDEF";
	else if (c == 'o')
		f->basestr = "01234567";
	f->basenb = ft_strlen(f->basestr);
}

void		conversion_digit(const char *str, va_list ap, t_result *r,
				t_format *f)
{
	(void)str;
	char *result;

	result = "";
	if (f->basenb < 2 || f->basenb > 16)
		r->error = 1;
	result = ft_itoa_base(va_arg(ap, int), f);
	f->flaglen += 1;
	ft_putstr_fd(result, 1);
	free (result);
}

//verifier si p est toujours unsigned et quelle memoire max il a ?
// pb avec p a gerer :
//
// test void *p: 0x7ffee65c0960
//test perso void *p : ffffffffe65c0960
