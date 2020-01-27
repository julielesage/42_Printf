/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:39:57 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/27 18:06:09 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

char	*ft_strdupiplus(char *result, t_format *f, int len)
{
	int		i;
	char	*copy;

	i = (int)ft_strlen(result) - 1; //0
	copy = (char *)malloc(sizeof(char) * len + 1);//3
	if (copy == NULL)
		return (NULL);
	//printf(" i = %d et len = %d\n", i, len);
	copy[len] = '\0';
	while (i > -1)
	{
		copy[len - 1] = result[i];
		len--;
		i--;
		//printf(" i = %d et len = %d\n", i, len);
	}
	while (len-- >= 0)
	{
		if (f->flagzero == 1)
			copy[len] = '0';
		else copy[len] = ' ';
		//printf(" i = %d et len = %d\n", i, len);
	}
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
	//printf("precision : %s\n", precision);
	return (precision);
}

/*Si la spécification de la largeur est un astérisque (*), un argument int issu de la liste d’arguments fournit la valeur. L’argument width doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant :
printf("%0*d", 5, 3);  00003 is output */
