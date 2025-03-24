/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:13:39 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:30:48 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p = ft_memcpy(p, s, (len + 1));
	return (p);
}

/*int	main()
{
	printf("%s", ft_strdup("hola"));
	return (0);
}*/
