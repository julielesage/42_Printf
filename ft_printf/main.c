/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:43:58 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/11 19:09:18 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>

int		main (void)
{
	char	*str = "premier test string";
	char	c = 'x'; 
/*	int		p = 
	int		d = 42;*/



	printf("test c : %c\n", c);
	ft_printf("test c : %c\n", c);
	write(1, ".\n", 2);

	printf("test str : %s\n", str);
	ft_printf("test str : %s\n", str);
	write(1, ".\n", 2);



}