/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:17 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:33:15 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	p;
	size_t	sp;

	if (!s)
		return (NULL);
	p = (size_t)start;
	sp = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - p))
		len = ft_strlen(s) - p;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (p < len + start)
	{
		str[sp] = s[p];
		p++;
		sp++;
	}
	str[sp] = '\0';
	return (str);
}

/*int	main()
{
	printf("%s", ft_substr("hola", 6, 4));
	return (0);
}*/
