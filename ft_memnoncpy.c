/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnoncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:46:38 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/19 14:48:03 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memnoncpy(void *dst, const void *src)
{
	size_t i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while ((const char *)src[i] != '\0')
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}
