/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:11:06 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/12 01:49:38 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long			n;
	int				a;

	n = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n < 10)
	{
		a = n + 48;
		write(fd, &a, 1);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
