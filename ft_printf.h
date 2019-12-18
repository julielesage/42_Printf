/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:36:10 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/18 20:22:51 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 256
# endif

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_printf
{
    char c;
    p_ft fonction ?;
	int flagminus = 0;
	int flag0 = 0;
	int flagpoint = 0;
	int flagstar = 0;
}				t_printf;

typedef struct	s_buff
{
	char	buff[BUFFER_SIZE + 1];
//	char	*str;
	int		error;
	int		len;
	int		j;
}				t_buff;

void	ft_putchar_fd(char c, int fd);

#endif


