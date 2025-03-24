/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:21 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:35:47 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_hastag(char **str, char fmt)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	if (fmt == 'X')
		str[p] = ft_strdup("0X");
	else
		str[p] = ft_strdup("0x");
	if (!str[p])
		return (-1);
	ft_swap(&str[p], &str[p - 1]);
	return (1);
}
