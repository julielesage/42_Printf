/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:17:39 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/27 21:46:03 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*d;
	int		swap;

	i = ft_strlen(str);
	swap = i;
	d = (char *)str;
	while (i > -1)
	{
		if (str[i] == c)
			return (&d[i]);
		i--;
	}
	if (c == '\0')
		return (&d[swap]);
	return (NULL);
}
