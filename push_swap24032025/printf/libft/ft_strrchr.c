/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:15:50 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:32:45 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			len;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == ch)
			return ((char *)&s[len]);
		len--;
	}
	if (s[0] == ch)
		return ((char *)&s[0]);
	return (NULL);
}

/*int	main()
{
	char	*a = ft_strrchr("hola AsuAuTVUAu8A5", 'h');
	printf("%s", a);
	return (0);
}*/
