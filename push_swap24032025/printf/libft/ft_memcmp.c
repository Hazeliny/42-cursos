/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:10:59 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:28:29 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			p;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	p = 0;
	if (n == 0)
		return (0);
	while (p < n - 1)
	{
		if (str1[p] != str2[p])
			return (str1[p] - str2[p]);
		p++;
	}
	return (str1[p] - str2[p]);
}

/*int	main()
{
	printf("%i", ft_memcmp("hola", "hol0", 4));
	return (0);
}*/
