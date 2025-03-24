/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:05:32 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:23:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	p;
	int	sign;
	int	num;

	sign = 1;
	p = 0;
	num = 0;
	while (nptr[p] == 32 || (nptr[p] >= 9 && nptr[p] <= 13))
		p++;
	if (nptr[p] == '-' || nptr[p] == '+')
	{
		if (nptr[p] == '-')
			sign = -sign;
		p++;
	}
	while (nptr[p] >= '0' && nptr[p] <= '9')
	{
		num = num * 10 + (nptr[p] - '0');
		p++;
	}
	return (num * sign);
}

/*int	main()
{
	printf("%i", ft_atoi("-2147483648"));
	return (0);
}*/
