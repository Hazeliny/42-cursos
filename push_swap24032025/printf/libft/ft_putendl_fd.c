/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:12:20 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:29:40 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	p;

	p = 0;
	while (s[p] != '\0')
	{
		ft_putchar_fd(s[p], fd);
		p++;
	}
	write (fd, "\n", 1);
	return ;
}

/*int	main()
{
	ft_putendl_fd("hola", 1);
	return (0);
}*/
