/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:34:31 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/23 23:25:50 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

char		*handling_field(char *result, t_format *f, size_t len)
{
	char *str;
	int i;
	//gerer la precision apres la virgule avant le champs
//	result = //precisefunction
	i = 0;
	str = NULL;
	if (len > strlen(result))
	{
		if (f->flagminus == 1)
			str = ft_strdupiminus(result, len);
		else 
			str = ft_strdupiplus(result, f, len);
		return (str);
	}
	else return (result);
}

char		*widthprecision(char *result, t_format *f)
{
	char	*new_str;
	char	*width;
	size_t		i;

	new_str = NULL;
	width = NULL;
	i = 0;
	if (result && f)
	{
		while (ischar(f->precisi[i], "0123456789") == 1)
			i++;
		width = ft_strndup(f->precisi, i);
	}
	i = ft_atoi(width);
	new_str = handling_field(result, f, i);//faire un malloc pour newstr du nombre i + 1
	//modifier le field avec 0 - . et * 
	return (new_str);
}

char		*modify_pointer(char *result)
{
	char	*strtrim;
	char	*address;

	strtrim = ft_substr(result, 8, 8);
	address = "0x7ffe";
	address = ft_strcat(address, strtrim);
	free (strtrim);
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
	if (f->basenb < 2 || f->basenb > 16)
		r->error = 1;
	if (f->indic == 'u')
		result = ft_itoa_base_u((unsigned int)va_arg(ap, int), f);
	else
		result = ft_itoa_base(va_arg(ap, int), f);
	if (*str == 'p')
		result = modify_pointer(result);
	//result = widthprecision(result, f);
	ft_putstr_fd(result, 1);
	f->flaglen += 1;
	r->lentotal += ft_strlen(result);
	printf("lentotal : %d\n", r->lentotal);
	free (result);
}




//verifier si p est toujours unsigned et quelle memoire max il a ?
// pb avec p a gerer :
//
// test void *p: 0x7ffee65c0960
//test perso void *p : ffffffffe65c0960
//substr special pour p
//
