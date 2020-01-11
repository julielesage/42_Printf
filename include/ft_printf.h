/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:36:10 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/11 19:18:41 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>


typedef struct	s_format
{
//    int		j;
//	char	c;
//    p_ft fonction ?;
	int		flagminus;
	int		flagzero;
	int		flagpoint;
	int		flagstar;
	int		flaglen;
	char	*result;
	char	*base;
}				t_format;

typedef struct	s_result
{
	int		error;
	int		lentotal;
	int		j;
}				t_result;

void	ft_bzero(void *str, size_t n);
int		ischar(char c, char *set);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);

int		ft_printf(const char *str,  ...);
void	readstring(const char *str, t_result *r, va_list ap);
void	checkflags(const char *str, va_list ap, t_result r,
		t_format *f);
void	direction(const char *str, va_list ap, t_result r,
		t_format *f);
void	conversionchar(const char *str, va_list ap, t_result r);


#endif
