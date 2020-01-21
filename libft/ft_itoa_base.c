/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:02:04 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/21 20:27:32 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

static	int		ft_nb(unsigned int n, int f)
{
	int				count;
	unsigned int	base;

	count = 0;
	base = (unsigned int)f;
	if (n >= base)
	{
		n = n / base;
		count = ft_nb(n, base);
	}
	count++;
	return (count);
}

char	*ft_itoa_base(int value, t_format *f) //value -12 en x
{
	char	*str;
	size_t	buf_size;
	size_t	negative;
	long	tmp;

	negative = (value < 0) ? 1 : 0; // que en decimal ou pas ?
	buf_size = 0;
	tmp = (long)value;
	if (negative == 1) tmp = -tmp;
	buf_size = ft_nb(tmp, f->basenb) + negative;
	str = (char *)malloc(sizeof(char) * (buf_size  + 1));
	str[buf_size] = '\0';
	//printf("value %d, buf-size : %zu\n", value, buf_size);
	if (negative == 1)
		str[0] = '-';
	if (tmp == 0) str[0] = '0';
	while (buf_size >= negative && tmp > 0)
	{
		str[buf_size - 1] = f->basestr[tmp % f->basenb];
		tmp = tmp / f->basenb;
		buf_size--;
	}
	return (str);
}

char	*ft_itoa_base_u(unsigned int value, t_format *f)
{
	char	*str;
	size_t	buf_size;

	buf_size = 0;
	buf_size = ft_nb(value, f->basenb);
	str = (char *)malloc(sizeof(char) * buf_size  + 1);
	str[buf_size] = '\0';
	if (value == 0) str[0] = '0';
	while (buf_size && value > 0)
	{
		str[buf_size - 1] = f->basestr[value % f->basenb];
		value = value / f->basenb;
		buf_size--;
	}
	return (str);
}
