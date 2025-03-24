/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:12:58 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:30:07 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	p;

	p = 0;
	while (s[p] != '\0')
	{
		ft_putchar_fd(s[p], fd);
		p++;
	}
	return ;
}

/*int	main()
{
	ft_putstr_fd("hola", 1);
	return (0);
}*/
