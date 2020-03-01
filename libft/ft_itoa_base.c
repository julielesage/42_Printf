/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:02:04 by jlesage           #+#    #+#             */
/*   Updated: 2020/03/01 19:19:11 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int		ft_nb(unsigned long n, int basenb)
{
	int				count;
	unsigned long	base;

	count = 0;
	base = (unsigned long)basenb;
	if (n >= base)
	{
		n = n / base;
		count = ft_nb(n, base);
	}
	count++;
	return (count);
}

char			*ft_itoa_base(int value, t_for *f)
{
	char	*str;
	size_t	buf_size;
	size_t	negative;
	long	tmp;

	negative = (value < 0) ? 1 : 0;
	buf_size = 0;
	tmp = (long)value;
	if (negative == 1)
		tmp = -tmp;
	buf_size = negative + ft_nb(tmp, f->basenb);
	str = (char *)malloc(sizeof(char) * (buf_size + 1));
	str[buf_size] = '\0';
	if (negative == 1)
		str[0] = '-';
	if (tmp == 0)
		str[0] = '0';
	while (buf_size >= negative && tmp > 0)
	{
		str[buf_size - 1] = f->basestr[tmp % f->basenb];
		tmp = tmp / f->basenb;
		buf_size--;
	}
	return (str);
}

char			*ft_itoa_base_u(unsigned int value, t_for *f)
{
	char				*str;
	size_t				buf_size;
	unsigned long		tmp;

	buf_size = 0;
	tmp = (unsigned long)value;
	buf_size = ft_nb(tmp, f->basenb);
	str = (char *)malloc(sizeof(char) * buf_size + 1);
	str[buf_size] = '\0';
	if (value == 0)
		str[0] = '0';
	while (buf_size && value > 0)
	{
		str[buf_size - 1] = f->basestr[tmp % f->basenb];
		tmp = tmp / f->basenb;
		buf_size--;
	}
	return (str);
}

char			*ft_itoa_base_p(unsigned long value, t_for *f)
{
	char				*str;
	size_t				buf_size;
	unsigned long long	tmp;

	buf_size = 0;
	tmp = (unsigned long long)value;
	buf_size = ft_nb(tmp, f->basenb);
	str = (char *)malloc(sizeof(char) * buf_size + 1);
	str[buf_size] = '\0';
	if (value == 0)
		str[0] = '0';
	while (buf_size && value > 0)
	{
		str[buf_size - 1] = f->basestr[tmp % f->basenb];
		tmp = tmp / f->basenb;
		buf_size--;
	}
	return (str);
}
