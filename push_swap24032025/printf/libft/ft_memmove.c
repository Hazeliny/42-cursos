/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:26 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:28:57 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			p;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	p = 0;
	if (!src && !dest)
		return (NULL);
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (p < n)
		{
			d[p] = s[p];
			p++;
		}
	}
	return (dest);
}

/*int	main()
{
	char	a[5] = "hola";
	char	b[5] = "adeu";
	printf("%s", a);
	printf("%s", b);
	ft_memmove(b + 2, a, 2);
	printf("%s", a);
	printf("%s", b);
}*/
