/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:25:08 by linyao            #+#    #+#             */
/*   Updated: 2024/06/24 13:54:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void    int_type(int d);
void    uint_type(unsigned int n);
void	str_type(char *s);
void	hex_type(unsigned int n);
void    ptr_type(void *p);
void	c_type(char c);
void    per_type(char c);

void	c_test(void)
{
	c_type('y');
	c_type('~');
	c_type('\0');
}

void	string_test(void)
{
	str_type("Just for test!");
	str_type("");
	str_type(" ");
	str_type(NULL);
}

void	decimal_int_test(void)
{
	int_type(INT_MIN);
	int_type(INT_MAX);
	int_type(0);
	int_type(123456);
	int_type(-98765);
	int_type(+678);
}

void	unsigned_int_test(void)
{
	uint_type(789456123);
    	uint_type(UINT_MAX);
    	uint_type(0);
    	uint_type(981256);
}

void	hex_test(void)
{
	hex_type(0);
	hex_type(18);
	hex_type(12345678);
	hex_type(UINT_MAX);
}

void	ptr_test(void)
{
	ptr_type("address of string");
	ptr_type("");
	ptr_type(" ");
}

void	per_test(void)
{
//	per_type('');
	per_type(' ');
	per_type('r');
	per_type('%');
}
/*
	unsigned int	n1 = 789456123;
	unsigned int	n2 = UINT_MAX;
	unsigned int	n3 = 0;
	unsigned int	n4 = 981256;
	int			    n5 = -98256;
	int				len = 0;

	len = ft_putnbr_unsigned_suf(n1);
	printf("\n%d\n", len);
	len = ft_putnbr_unsigned_suf(n2);
	printf("\n%d\n", len);
	len = ft_putnbr_unsigned_suf(n3);
	printf("\n%d\n", len);
    len = ft_putnbr_unsigned_suf(n4);
	printf("\n%d\n", len);
	len = ft_putnbr_suf(n5);
    printf("\n%d\n", len);
	len = ft_puthex_suf(n1, 'x');
    printf("\n%d\n", len);
	len = ft_putptr_suf("hello");
	printf("\nI am standard pointer dispaly: %p\n","hello");
    printf("\n%d\n", len);
	return (0);
}
*/
int	main(void)
{
	c_test();
	string_test();
	decimal_int_test();
	unsigned_int_test();
	hex_test();
	ptr_test();
	per_test();
	return (0);
}
