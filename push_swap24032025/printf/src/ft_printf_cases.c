/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:09:02 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:36:12 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

char	*ft_prints(char	*s)
{
	char	*str;

	if (!s)
	{
		str = (char *)malloc(7 * sizeof(char));
		if (!str)
			return (NULL);
		ft_memcpy(str, "(null)", 6);
		str[6] = '\0';
		return (str);
	}
	else
		str = ft_strdup(s);
	return (str);
}

char	*ft_printp(unsigned long n)
{
	int		p;
	char	*base;
	char	s[16];
	char	*str;

	base = "0123456789abcdef";
	if (n == 0)
	{
		str = ft_strdup("(nil)");
		if (!str)
			return (NULL);
		return (str);
	}
	p = 0;
	while (n > 0)
	{
		s[p] = base[n % 16];
		n = n / 16;
		p++;
	}
	s[p] = '\0';
	str = ft_strdup(s);
	str = ft_reverse(str);
	return (str);
}

char	*ft_printd(int n)
{
	char	s[11];
	char	*str;
	int		p;
	long	num;

	p = 0;
	num = n;
	if (num == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else if (num < 0)
		num = -num;
	while (num > 0)
	{
		s[p++] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		s[p++] = '-';
	s[p] = '\0';
	str = ft_strdup(s);
	str = ft_reverse(str);
	return (str);
}

char	*ft_printu(unsigned int n)
{
	char	s[10];
	char	*str;
	int		p;

	p = 0;
	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (n > 0)
	{
		s[p] = n % 10 + '0';
		n = n / 10;
		p++;
	}
	s[p] = '\0';
	str = ft_strdup(s);
	str = ft_reverse(str);
	return (str);
}

char	*ft_printx(char x, unsigned int n)
{
	int		p;
	char	*base;
	char	s[8];
	char	*str;

	p = 0;
	base = "0123456789ABCDEF";
	if (x == 'x')
		base = "0123456789abcdef";
	p = 0;
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (n > 0)
	{
		s[p++] = base[n % 16];
		n = n / 16;
	}
	s[p] = '\0';
	str = ft_strdup(s);
	str = ft_reverse(str);
	return (str);
}
