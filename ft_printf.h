/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:36:10 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/01 23:38:22 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 256
# endif

# include <unistd.h>
# include <stdarg.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_printf
{
//    int		j;
//	char	c;
//    p_ft fonction ?;
	int		flagminus;
	int		flagzero;
	int		flagpoint;
	int		flagstar;
	int		flaglen;
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


