/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:10:45 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:28:16 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			p;

	str = (unsigned char *)s;
	p = 0;
	while (p < n)
	{
		if (str[p] == (unsigned char)c)
			return (&str[p]);
		p++;
	}
	return (NULL);
}

/*int	main()
{
	printf("%s", (char *)ft_memchr("0x7ffd88caf0a0", '0', 42));
	return (0);
}*/
