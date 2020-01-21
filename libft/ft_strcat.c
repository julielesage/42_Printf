/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:11:55 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/14 22:45:30 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	char *new_dest;

	i = 0;
	j = 0;
	if (!(new_dest = (char *)malloc(17 * sizeof(char))))
		return NULL;
	while (dest[i])
	{
		new_dest[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		new_dest[i + j] = src[j];
		j++;
	}
	new_dest[i + j] = '\0';
	return (new_dest);
}
