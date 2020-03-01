/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:17:19 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/16 00:50:10 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*modify_pointer(char *result)
{
	char	*address;

	address = "0x";
	address = ft_strcat(address, result);
	free(result);
	return (address);
}

char	*large_precision(char *result, t_for *f)
{
	char	*copy;
	int		len;

	len = (int)ft_strlen(result) - 1;
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

char	*large_precision_minus(char *result, int buf, t_for *f)
{
	char	*copy;
	int		len;

	len = (int)ft_strlen(result) - 1;
	if (buf == f->width && f->flagzero == 1)
		buf--;
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

char	*withpoint(char *result, t_for *f)
{
	char	*hopprecis;

	hopprecis = NULL;
	if (f->precision < 0 && f->flag != 's')
		f->precision = 1;
	if (f->precision < 1 && (result[0] == '0' && result[1] == '\0'))
		return (hopprecis);
	else if ((f->precision < 1 && f->flagpoint == 1)
				|| (f->precision < (int)ft_strlen(result)))
		return (result);
	else if (result[0] == '-')
		hopprecis = large_precision_minus(result, f->precision, f);
	else
		hopprecis = large_precision(result, f);
	if (f->flag != 's')
		free(result);
	return (hopprecis);
}
