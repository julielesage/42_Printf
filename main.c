/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:43:58 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/12 22:41:43 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main (void)
{
	char	*str = "premier test string";
	char	c = 'x';
	int		d = -23242;
	int		i = 23242;

	unsigned int	u = 32;
	unsigned int	x = 32;
	unsigned int	o = 32;
	unsigned int	X = 32;

	void *p = &d;




	printf("test c : %c\n", c);
	ft_printf("test perso c : %c\n", c);
	write(1, ".\n", 2);

	printf("test str : %s\n", str);
	ft_printf("test perso str : %s\n", str);
	write(1, ".\n", 2);

	printf("test signed int d: %d\n", d);
	ft_printf("test perso signed int d : %d\n", d);
	write(1, ".\n", 2);

	printf("test unsigned int u en decimal : %u\n", u);
	ft_printf("test perso unsigned int u en decimal: %u\n", u);
	write(1, ".\n", 2);

	printf("test signed int i en decimal: %u\n", i);
	ft_printf("test perso signed int i en decimal : %u\n", i);
	write(1, ".\n", 2);

	printf("test unsigned int x en hexa: %x\n", x);
	ft_printf("test perso unsigned int x en hexa: %x\n", x);
	write(1, ".\n", 2);

	printf("test unsigned int o en octal: %x\n", o);
	ft_printf("test perso unsigned int o en octal : %x\n", o);
	write(1, ".\n", 2);


	printf("test unsigned int X en hexa maj: %X\n", X);
	ft_printf("test perso unsigned int X en hexa maj: %X\n", X);
	write(1, ".\n", 2);

	printf("test void *p: %p\n", p);
	ft_printf("test perso void *p : %p\n", p);
	write(1, ".\n", 2);

}
