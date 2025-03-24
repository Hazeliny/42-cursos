/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:12:40 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:29:53 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[10];
	int		p;
	long	num;

	p = 0;
	num = n;
	if (num == 0)
		write (fd, "0", 1);
	else if (num < 0)
	{
		write (fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		str[p] = num % 10 + '0';
		num = num / 10;
		p++;
	}
	while (p > 0)
	{
		p--;
		write (fd, &str[p], 1);
	}
}

/*int	main()
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
