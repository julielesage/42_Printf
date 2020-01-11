/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:15:28 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/11 19:03:39 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n--)
	{
		str[i] = 0;
		i++;
	}
}
