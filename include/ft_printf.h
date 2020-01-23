/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:36:10 by jlesage           #+#    #+#             */
/*   Updated: 2020/01/23 23:25:13 by jlesage          ###   ########.fr       */
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
	int		flagminus;
	char	indic;
	int		flagzero;
	int		flagpoint;
	int		flagstar;
	int		flaglen;
	char	*basestr;
	long	basenb;
	char	*precisi;
}				t_format;

typedef struct	s_result
{
	int		error;
	int		lentotal;
	int		j;
	char	*buf;
}				t_result;

void		ft_bzero(void *str, size_t n);
int			ischar(char c, char *set);
void		ft_putstr_fd(char *str, int fd);
size_t		ft_strlen(char *str);
void		ft_putnbr_fd(int nb, int fd);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_itoa_base(int value, t_format *f);
char		*ft_itoa_base_u(unsigned int value, t_format *f);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strcat(char *dst, char *src);
char		*ft_strdup(const char *s1);
int			ft_atoi(char *str);
char		*ft_strndup(char *str, size_t n);

int			ft_printf(const char *str, ...);
void		readstring(const char *str, t_result *r, va_list ap);
void		checkflags(const char *str, va_list ap, t_result *r, t_format *f);
void		direction(const char *str, va_list ap, t_result *r, t_format *f);
void		conversionchar(const char *str, va_list ap, t_result *r,
				t_format *f);
void		witchbase(char c, t_format *f);
void		conversion_digit(const char *str, va_list ap, t_result *r, t_format *);
char		*widthprecision(char *result, t_format *f);
char		*handling_field(char *result, t_format *f, size_t len);
char		*ft_strdupiplus(char *result, t_format *f, size_t len);
char		*ft_strdupiminus(char *result, size_t len);
char		*strchiffres(const char *sr, int len);

#endif
