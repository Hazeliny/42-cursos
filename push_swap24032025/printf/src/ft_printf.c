/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:06:58 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:35:01 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	int		plus;
	int		len;
	va_list	args;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		plus = -1;
		if (*fmt != '%')
			plus = ft_putchar(*fmt++);
		else
		{
			if (++fmt && *fmt != '\0')
			{
				plus = ft_special((char **)&fmt, &args);
				fmt++;
			}
		}
		if (plus == -1)
			len = 0;
		len += plus;
	}
	va_end (args);
	return (len);
}

int	ft_putchar(char c)
{
	if (write (1, &c, 1))
		return (1);
	return (-1);
}

char	*ft_normal(int c, va_list *arg)
{
	char	*str;

	str = "%";
	if (c == 'c')
		str = ft_chardup(str, va_arg(*arg, int));
	else if (c == 's')
		str = (ft_prints(va_arg(*arg, char *)));
	else if (c == 'p')
		str = (ft_printp(va_arg(*arg, unsigned long)));
	else if (c == 'd' || c == 'i')
		str = (ft_printd(va_arg(*arg, int)));
	else if (c == 'u')
		str = (ft_printu(va_arg(*arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		str = (ft_printx(c, va_arg(*arg, unsigned int)));
	else if (c == '%')
		str = ft_strdup("%");
	else
	{
		str = ft_strdup("%");
		if (!str)
			return (NULL);
	}
	return (str);
}
