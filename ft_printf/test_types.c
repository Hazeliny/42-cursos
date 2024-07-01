/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:08:15 by linyao            #+#    #+#             */
/*   Updated: 2024/06/24 12:54:13 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void	c_type(char c)
{
	int	n1;
	int	n2;

	write(1, "Ft function with type char: ", 28);
	n1 = ft_printf("%c\n", c) - 1;
	write(1, "Std function with type char: ", 29);
	n2 = printf("%c\n", c) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}

void	per_type(char c)
{
	int	n1;
	int	n2;

	write(1, "Ft function with only %: ", 23);
	n1 = ft_printf("%c\n", c) - 1;
	write(1, "Std function with only %: ", 24);
	n2 = printf("%c\n", c) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}

void	str_type(char *s)
{
	int	n1;
	int	n2;

	write(1, "Ft function with type str: ", 27);
	n1 = ft_printf("%s\n", s) - 1;
	write(1, "Std function with type str: ", 28);
	n2 = printf("%s\n", s) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}

void	int_type(int d)
{
	int	n1;
	int	n2;

	write(1, "Ft function with type d/i: ", 27);
	n1 = ft_printf("%d\n", d) - 1;
	write(1, "Std function with type d/i: ", 28);
	n2 = printf("%d\n", d) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}

void	uint_type(unsigned int n)
{
	int	n1;
	int	n2;

	write(1, "Ft function with type u: ", 25);
	n1 = ft_printf("%u\n", n) - 1;
	write(1, "Std function with type u: ", 26);
	n2 = printf("%u\n", n) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}

void	hex_type(unsigned int n)
{
	int	n1;
	int	n2;

	write(1, "Ft function with type hex x: ", 29);
	n1 = ft_printf("%x\n", n) - 1;
	write(1, "Std function with type hex x: ", 30);
	n2 = printf("%x\n", n) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}

void	ptr_type(void *p)
{
	int	n1;
	int	n2;

	write(1, "Ft function with type ptr: ", 27);
	n1 = ft_printf("%p\n", p) - 1;
	write(1, "Std function with type ptr: ", 28);
	n2 = printf("%p\n", p) - 1;
	printf("FT: %d\tStd: %d\n", n1, n2);
}
