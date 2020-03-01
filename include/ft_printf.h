/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:36:10 by jlesage           #+#    #+#             */
/*   Updated: 2020/03/01 19:07:04 by jlesage          ###   ########.fr       */
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
	int			flagminus;
	char		indic;
	int			flagzero;
	int			flagpoint;
	int			flagstar;
	char		*basestr;
	long		basenb;
	int			width;
	int			ifwidth;
	int			precision;
	char		flag;
}				t_for;

typedef struct	s_result
{
	int			error;
	int			lentotal;
	int			j;
	char		*buf;
}				t_res;

void			ft_bzero(void *str, size_t n);
int				ischar(char c, char *set);
void			ft_putstr_fd(char *str, int fd);
size_t			ft_strlen(char *str);
void			ft_putnbr_fd(int nb, int fd);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_itoa_base(int value, t_for *f);
char			*ft_itoa_base_u(unsigned int value, t_for *f);
char			*ft_itoa_base_p(unsigned long value, t_for *f);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strcat(char *dst, char *src);
char			*ft_strdup(const char *s1);
int				ft_atoi(char *str);
void			*ft_memchr(void *str, int c);
char			*ft_strndup(char *str, int n);

int				ft_printf(const char *str, ...);
void			readstring(const char *str, t_res *r, va_list ap);
void			checkflags(const char *str, va_list ap, t_res *r, t_for *f);
void			direction(const char *str, va_list ap, t_res *r, t_for *f);
void			conversionchar(va_list ap, t_res *r, t_for *f);
void			witchbase(char c, t_for *f);
void			conversion_digit(const char *str, va_list ap, t_res *r,
				t_for *f);
char			*widthprecision(char *res, t_for *f);
char			*handling_field(char *res, t_for *f);
char			*ft_strdupiplus(char *res, t_for *f);
char			*ft_strdupiminus(char *res, int len, t_for *f);
int				strchiffres(const char *sr, int len);
char			*withpoint(char *res, t_for *f);
char			*s_withpoint(char *res, t_for *f);
char			*large_precision(char *res, t_for *f);
char			*large_precision_minus(char *res, int buf, t_for *f);
int				checkflags_bis(const char *str, va_list ap, t_for *f);
int				flagpoint(const char *str, va_list ap, t_for *f);
void			re_direction(const char *str, va_list ap, t_res *r, t_for *f);
void			conversionstr(va_list ap, t_res *r, t_for *f);
char			*modify_pointer(char *result);
char			*minussuite(char *result, char *copy, int len, t_for *f);
char			*plussuite(char *result, char *copy, t_for *f, int len);
void			lentotal_for_c(char *s, t_res *r, t_for *f);
void			percentchar(char c, t_res *r, t_for *f);

#endif
