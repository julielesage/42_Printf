/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:39:57 by jlesage           #+#    #+#             */
/*   Updated: 2020/02/04 21:52:24 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

char *s_withpoint(char *result, t_format *f)
{
	char	*hopprecis;

	hopprecis = NULL;
	//printf("precision = %d\n", f->precision);
	//printf("result = %s\n", result);
	if (f->precision == 0)
		return (hopprecis);
	if (f->precision < 0 && f->flagpoint == 1)
		return (result);
	else
		hopprecis = strndup(result, f->precision);
	//free (result);
	return (hopprecis);
}

char *withpoint(char *result, t_format *f)
{
	char	*hopprecis;

	hopprecis = NULL;
	//printf("precision = %d\n", f->precision);//0
	//printf("result = %s\n", result);//0
	if (f->precision < 0 && f->flag != 's')
		f->precision = 1;
	if (f->precision < 1  && (result[0] == '0' && result[1] == '\0'))
		return (hopprecis);
	else if ((f->precision < 1 && f->flagpoint == 1)
				|| (f->precision < (int)ft_strlen(result)))
		return (result);
	else if (result[0] == '-')
		hopprecis = large_precision_minus(result, f->precision, f);
	else
		hopprecis = large_precision(result, f);
	if (f->flag != 's')
		free (result);
	return (hopprecis);
}

char	*ft_strdupiplus(char *result, t_format *f)
{
	int		i;
	char	*copy;
	int		len;

	if (result)
		i = (int)ft_strlen(result) - 1; //0
	len = f->width;
	if (len < 0)
		len = -len;
	copy = (char *)malloc(sizeof(char) * len + 1);//3
	if (copy == NULL)
		return (NULL);
	//printf(" i = %d et len = %d\n", i, len);
	copy[len] = '\0';
	while (result && i > -1)
	{
		copy[len - 1] = result[i];
		len--;
		i--;
	}
	while (len-- >= 0)
	{
		//printf("coucou, zero = %d\n", f->flagzero);
		if (f->flagzero == 1)
			copy[len] = '0';
		else
			copy[len] = ' ';
	}
	//printf("flag = %c\n", f->flag);
	if (f->flag != 's')
		free (result);
	return (copy);
}

char	*ft_strdupiminus(char *result, int len, t_format *f)
{
	char		*copy;
	int			j;
	int			i;

	i = 0;
	if (len < 0)
		len = -len;
	j = 0;
	/*if (result)
		j = (int)strlen(result);*/
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	copy[len] = '\0';

	while (result && result[i])
	{
		copy[i] = result[i];
		i++;
	}
	//printf("coucou\n");
	//printf("j = %d et len = %d\n", j, len);	len++;
	while (i < len)
	{
		copy[i] = ' ';
		i++;
	}
	if (f->flag != 's')
		free (result);
	//printf("free result de l itoa\n");
	return (copy);
}

int		strchiffres(const char *str, int len)
{
	char	*width;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!(width = (char *)malloc(sizeof (char) * len + 1)))
		return (0);
	//printf("malloc width en str\n");
	while (ischar(str[i], "cspdiouxX%") == 0)
	{
		width[i] = str[i];
		i++;
	}
	width[i] = '\0';
	//printf("width : %s\n", width);
	result = ft_atoi(width);
	free (width);
	//printf("free widthstr\n");
	return (result);
}

char		*handling_field(char *result, t_format *f)
{
	char	*str;
	int		i;
	int		swap;

	i = 0;
	str = NULL;
	swap = f->width;
	if (f->width < 0)
		swap = -swap;//dprintf(1, "coucou\n");
	//printf( "result : %s\n", result);
	//printf("swap ; %d\n", swap);
	if ((result && swap <= ((int)strlen(result))))
	{
		//printf("width qui sert a rien, result garde son malloc\n");
		return (result);
	}
	else
	{
		//printf("ZERO = %D\n", f->flagzero);
		if (result && f->flagzero == 1 && result[0] == '-')
		{
			//printf("coucouzero\n");
			str = large_precision_minus(result, f->width, f);
		}
		else if(f->flagminus == 1 || (f->flagminus == 0 && f->width < 0))
		{
			str = ft_strdupiminus(result, f->width, f);
			//printf("coucouminus\n");
		}

		else
		{
			//printf("coucouplus\n");
			str = ft_strdupiplus(result, f);
		}
		//printf("coucourien\n");
		//printf("si width > strlen, free result et malloc str apres width :  %s\n", str);
	}
	return (str);
}

/*Si la spécification de la largeur est un astérisque (*), un argument int issu de la liste d’arguments fournit la valeur. L’argument width doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant :
printf("%0*d", 5, 3);  00003 is output */
