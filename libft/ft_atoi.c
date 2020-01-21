/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:58:15 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/17 22:38:59 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_checkmin(int negative, long j, int rslt)
{
	if (negative == 1)
		rslt = rslt * -1;
	if (rslt < -2147483648 || (j > 10 && negative == 1))
		return (0);
	if (rslt > 2147483647 || (j > 10 && negative == 0))
		return (-1);
	return (rslt);
}

int				ft_atoi(char *str)
{
	int		i;
	int		rslt;
	int		negative;
	long	j;

	i = 0;
	rslt = 0;
	negative = 0;
	j = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt = (rslt * 10) + (str[i] - 48);
		i++;
		j++;
	}
	return (ft_checkmin(negative, j, rslt));
}
