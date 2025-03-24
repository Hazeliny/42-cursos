/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:06:36 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:34:47 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

void	ft_analisis(int *flag, char **str, char fmt)
{
	if (flag[0])
		ft_num(flag[0], str);
	if (flag[4])
		ft_hastag(str, fmt);
	if (flag[5])
		ft_space(str);
	if (flag[6])
		ft_plus(str);
	if (flag[2])
		ft_dot(flag[2], str, fmt);
	if (flag[3])
		ft_dot(flag[3], str, fmt);
	if (flag[1])
		ft_minus(flag[1], str);
}

int	ft_special_do(char fmt, int *flag, va_list *arg)
{
	char	*temp;
	char	**str;
	int		len;

	str = NULL;
	temp = ft_normal(fmt, arg);
	len = ft_strlen(temp);
	if (fmt == 'c')
		len = 1;
	len = ft_calculate(flag, fmt, len, temp);
	str = ft_malloc(&temp, flag);
	ft_analisis(flag, str, fmt);
	if (ft_special_print(str, fmt) < 0)
		return (-1);
	free(str);
	return (len);
}

void	ft_special_num(char **fmt, int *flag)
{
	int	p;

	p = 1;
	while (!ft_strchr(".0-%", *(*fmt - p)))
		p++;
	if (*(*fmt - p) == '.')
		flag[3] = ft_atoi(*fmt);
	else if (*(*fmt - p) == '0')
		flag[2] = ft_atoi(*fmt);
	else if (*(*fmt - p) == '-')
		flag[1] = ft_atoi(*fmt);
	else if (*(*fmt - p) == '%')
		flag[0] = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
}

void	ft_plus_space_hastag(int *flag, char **fmt)
{
	if (**fmt == '+')
	{
		flag[6] = 1;
		(*fmt)++;
	}
	else if (**fmt == ' ')
	{
		flag[5] = 1;
		(*fmt)++;
	}
	else if (**fmt == '#')
	{
		flag[4] = 1;
		(*fmt)++;
	}
}

int	ft_special(char **fmt, va_list *arg)
{
	int	len;
	int	flag[8];

	len = 0;
	ft_initialize(flag);
	while (**fmt != '\0')
	{
		if (**fmt == '+' || **fmt == ' ' || **fmt == '#')
			ft_plus_space_hastag(flag, fmt);
		else if (**fmt == '0')
			(*fmt)++;
		else if (ft_isdigit(**fmt))
			ft_special_num(fmt, flag);
		else if (**fmt == '-' || **fmt == '.')
		{
			if (**fmt == '.' && (*(*fmt + 1)) == 's')
				flag[7] = 1;
			(*fmt)++;
		}
		else
			break ;
	}
	len += ft_special_do(**fmt, flag, arg);
	return (len);
}
