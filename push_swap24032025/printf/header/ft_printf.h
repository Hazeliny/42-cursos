/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:00:17 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:23:18 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* BONUS */
int		ft_malloc_count(int *flag);
void	ft_initialize(int num[]);
void	ft_plus_space_hastag(int *flag, char **fmt);
void	ft_analisis(int *flag, char **str, char fmt);
char	**ft_malloc(char **str, int *flag);
int		ft_dot_calculate(int *flag, char fmt, int len, char *str);
int		ft_pmh_calculate(int *flag, char fmt, char *str);
void	ft_num_calculate(int *flag, char fmt, int len);
void	ft_minus_calculate(int *flag, int len);
int		ft_zero_calculate(int *flag, char fmt, int len, char *str);
int		ft_calculate(int *flag, char fmt, int len, char *str);
void	ft_do_free(char **str);
int		ft_printf(const char *fmt, ...);
char	*ft_normal(int c, va_list *arg);
char	*ft_prints(char *s);
char	*ft_printp(unsigned long n);
char	*ft_printd(int n);
char	*ft_printu(unsigned int n);
char	*ft_printx(char x, unsigned int n);
int		ft_mputchar(char *s, int fmt);
int		ft_special_do(char fmt, int *flag, va_list *arg);
void	ft_special_num(char **fmt, int *flag);
int		ft_special(char **fmt, va_list *arg);
int		ft_putchar(char c);
char	*ft_chardup(char *dst, int src);
int		ft_hastag(char **str, char fmt);
int		ft_plus(char **str);
int		ft_space(char **str);
int		ft_dot(int len, char **str, char fmt);
int		ft_num(int len, char **str);
int		ft_minus(int len, char **str);
int		ft_special_print(char **str, int fmt);
char	*ft_reverse(char *reverse);
void	ft_swap(char **a, char **b);

#endif
