/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calculate_falgs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:51 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:35:34 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_dot_calculate(int *flag, char fmt, int len, char *str)
{
	int	len_dot;

	len_dot = len;
	if (str[0] == '-' && (fmt == 'i' || fmt == 'd'))
		len_dot -= 1;
	if (flag[3] > len_dot && (fmt == 'i' || fmt == 'd'
			|| fmt == 'x' || fmt == 'X'
			|| fmt == 'p' || fmt == 'u'))
	{
		flag[3] = flag [3] - len;
		if ((fmt == 'd' || fmt == 'i') && str[0] == '-')
		{
			flag[3] += 2;
			len--;
		}
	}
	else
		flag[3] = 0;
	return (flag[3] + len);
}

int	ft_pmh_calculate(int *flag, char fmt, char *str)
{
	if (flag[4] && (fmt == 'x' || fmt == 'X')
		&& str[0] != '0' && str[0] != '\0')
	{
		flag[6] = 0;
		flag[5] = 0;
		return (2);
	}
	else if (flag[6] && (fmt == 'd' || fmt == 'i') && str[0] != '-')
	{
		flag[5] = 0;
		flag[4] = 0;
		return (1);
	}
	else if (flag[5] && (fmt == 'd' || fmt == 'i') && str[0] != '-')
	{
		flag[4] = 0;
		flag[6] = 0;
		return (1);
	}
	flag[4] = 0;
	flag[5] = 0;
	flag[6] = 0;
	return (0);
}

void	ft_num_calculate(int *flag, char fmt, int len)
{
	if (flag[0] > len)
		flag[0] = flag[0] - len;
	else if (flag[2] > len && (fmt == 's' || fmt == 'c'))
	{
		flag[0] = flag[2] - len;
		flag[2] = 0;
	}
	else
		flag[0] = 0;
}

void	ft_minus_calculate(int *flag, int len)
{
	if (flag[1] > len)
		flag[1] = flag[1] - len;
	else
		flag[1] = 0;
}

int	ft_zero_calculate(int *flag, char fmt, int len, char *str)
{
	if (flag[2] > len && (fmt == 'p' || fmt == 'i'
			|| fmt == 'd' || fmt == 'u' || fmt == 'x' || fmt == 'X'))
	{
		flag[2] = flag[2] - len;
		if ((fmt == 'd' || fmt == 'i') && str[0] == '-')
		{
			flag[2]++;
			return (-1);
		}
	}
	else
		flag[2] = 0;
	return (0);
}
