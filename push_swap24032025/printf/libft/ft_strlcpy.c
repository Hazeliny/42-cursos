/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:14:37 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:31:40 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;

	s = 0;
	if (size > 0)
	{
		while (src[s] != '\0' && s < (size - 1))
		{
			dst[s] = src[s];
			s++;
		}
		dst[s] = '\0';
	}
	return (ft_strlen(src));
}

/*int     main()
{
        char    *s1 = "hola";
        char    *s2 = "adeu";

        printf("%zu\n", ft_strlcpy(s1, s2, 0));
        printf("Contenido de s1: %s\n", s1);
        return 0;
}*/
