/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:51:40 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/01 14:44:35 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t count;

	count = 0;
	if (!str)
		return (count);
	else
	{
		while (*str != '\0')
		{
			count++;
			str++;
		}
		return (count);
	}
}
