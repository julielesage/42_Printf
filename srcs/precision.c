/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:42:59 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/02 17:30:05 by jlesage          ###   ########.fr       */
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

char	*large_precision_minus(char *result, int buf, t_format *f)
{
	char	*copy;
	int		len;

	//printf("result : %s\n", result);
	len = (int)ft_strlen(result) -1;
	if (buf == f->width && f->flagzero == 1)
		buf--;
	if (!(copy = (char *)malloc((buf + 2) * sizeof(char))))
		return (NULL);
	copy[buf + 1] = '\0';
	copy[0] = '-';

	while (len > 0)
	{
		copy[buf] = result[len];
		//printf("result len = %d : %c et copy[buf = %d = %c\n", len, result[len], buf, copy[buf]);
		buf--;
		len--;
	}
	//printf("buf ; %d len : %d et copy[2] = %c\n", buf, len, copy, copy[2]);
	//printf("&copy[2] : %s\n", &copy[2]);
	while (buf > 0)
	{
		copy[buf] = '0';
		//printf("&copy[0] : %s mais copy : %s\n", &copy[0], copy);

		buf--;
	}
	return (copy);
}

