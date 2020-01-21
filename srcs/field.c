/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:39:57 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/21 18:11:44 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

char	*ft_strdupiplus(char *result, t_format *f, size_t len)
{
	size_t		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (result[i])
	{
		copy[i] = result[i];
		i++;
	}
	i -= 1;
	while (i++ < len)
	{
		if (f->flagzero == 1)
			copy[i] = '0';
		else copy[i] = ' ';
	}
	copy[i] = '\0';
	free (result);
	return (copy);
}

char	*ft_strdupiminus(char *result, size_t len)
{
	size_t		i;
	char	*copy;
	int		j;

	i = 0;
	j = strlen(result);//5
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	copy[len] = '\0';
	while (j-- && result[j] && len--)
		copy[len] = result[j];
	while (len-- && len > 0)
		copy[len] = ' ';
	free (result);
	return (copy);
}

char	*strchiffres(const char *str, int len)
{
	char	*precision;
	int		i;

	i = 0;
	if (!(precision = (char *)malloc(sizeof (char) * len + 1)))
		return NULL;
	while (ischar(str[i], "cspdiouxX%") == 0)
	{
		precision[i] = str[i];
		i++;
	}
	precision[i] = '\0';
	return (precision);
}

/*Si la spécification de la largeur est un astérisque (*), un argument int issu de la liste d’arguments fournit la valeur. L’argument width doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant :
printf("%0*d", 5, 3);  00003 is output */
