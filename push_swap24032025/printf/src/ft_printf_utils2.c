/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:17:45 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:36:38 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

void	ft_initialize(int num[])
{
	int	len;

	len = 0;
	while (len < 8)
	{
		num[len] = 0;
		len++;
	}
}
