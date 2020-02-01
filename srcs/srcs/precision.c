/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:42:59 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/02 00:36:04 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

char	*large_precision(char *result, t_format *f)
{
	char	*copy;
	int		len;

	len = (int)ft_strlen(result) -1;
	if (!(copy = (char *)malloc((f->precision + 1) * sizeof(char))))
		return (NULL);
	copy[f->precision] = '\0';
	f->precision--;
	while (len >= 0)
	{
		copy[f->precision] = result[len];
		f->precision--;
		len--;
	}
	while (f->precision > -1)
	{
		copy[f->precision] = '0';
		f->precision--;
	}
	return (copy);
}

char	*large_precision_minus(char *result, int buf)
{
	char	*copy;
	int		len;

	len = (int)ft_strlen(result) -1;
	if (!(copy = (char *)malloc((buf + 2) * sizeof(char))))
		return (NULL);
	copy[buf + 1] = '\0';
	copy[0] = '-';
	while (len > 0)
	{
		copy[buf] = result[len];
		buf--;
		len--;
	}
	while (buf > 0)
	{
		copy[buf] = '0';
		buf--;
	}
	return (copy);
}

