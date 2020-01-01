/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:56:30 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/16 16:50:10 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*Function name ft_putchar_fd  
Prototype void ft_putchar_fd(char c, int fd);  
Paramètres #1. Le caractère à écrire #2. Le file descriptor sur lequel écrire.  
Valeur de retour None Fonctions externes autorisées write Description Écrit le caractère c sur le file descriptor donné. */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
