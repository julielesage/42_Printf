/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:02:04 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/12 22:35:55 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		static ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(int value, t_format *f)
{
	char	*str;
	size_t	buf_size;
	size_t	negative;
	long	tmp;

	negative = 0;
	buf_size = 0;
	if (value < 0 && f->basenb == 10)
		negative = 1;
	tmp = (long)value;
	while (tmp /= f->basenb)
		buf_size++;
	buf_size += negative + 1;
	str = (char *)malloc(sizeof(char) * buf_size  + 1);
	str[buf_size] = '\0';
	if (negative == 1)
		str[0] = '-';
	while (buf_size > negative)
	{
		str[buf_size - 1] = f->basestr[ft_abs(value % f->basenb)];
		buf_size--;
		value /= f->basenb;
	}
	return (str);
}
