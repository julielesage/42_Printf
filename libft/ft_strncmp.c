/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:36:47 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/12 02:08:09 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)s2;
	s = (unsigned char *)s1;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s && d) && s[i] == d[i])
	{
		i++;
		if (s[i] == '\0' || d[i] == '\0')
			break ;
	}
	return ((unsigned char)s[i] - (unsigned char)d[i]);
}
