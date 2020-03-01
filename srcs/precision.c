/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:42:59 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/18 23:04:41 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*minussuite(char *result, char *copy, int len, t_for *f)
{
	int i;

	i = 0;
	copy[len] = '\0';
	while (result && result[i])
	{
		copy[i] = result[i];
		i++;
	}
	if (f->flag == 'c' && result[0] == '\0')
	{
		copy[i] = 0;
		i++;
	}
	while (i < len)
	{
		copy[i] = ' ';
		i++;
	}
	return (copy);
}

char	*s_withpoint(char *result, t_for *f)
{
	char	*hopprecis;

	hopprecis = NULL;
	if (f->precision == 0)
		return (hopprecis);
	if (f->precision < 0 && f->flagpoint == 1)
		return (result);
	else
		hopprecis = ft_strndup(result, f->precision);
	return (hopprecis);
}

char	*plussuite(char *result, char *copy, t_for *f, int len)
{
	int i;

	if (result)
		i = (int)ft_strlen(result) - 1;
	copy[len] = '\0';
	while (result && i > -1)
	{
		copy[len - 1] = result[i];
		len--;
		i--;
	}
	while (len-- >= 0)
	{
		if (f->flagzero == 1)
			copy[len] = '0';
		else
			copy[len] = ' ';
	}
	return (copy);
}

char	*ft_strdupiplus(char *result, t_for *f)
{
	char	*copy;
	int		len;

	len = f->width;
	if (len < 0)
		len = -len;
	if (f->flag == 'c' && result[0] == '\0')
		len--;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	copy = plussuite(result, copy, f, len);
	return (copy);
}

char	*ft_strdupiminus(char *result, int len, t_for *f)
{
	char		*copy;
	int			i;

	i = 0;
	if (len < 0)
		len = -len;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	copy = minussuite(result, copy, len, f);
	return (copy);
}
