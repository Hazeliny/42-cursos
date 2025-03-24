/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:14:06 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:31:11 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		p;

	p = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	if (len <= 0)
		return (NULL);
	while (s1[p] != '\0')
	{
		str[p] = s1[p];
		p++;
	}
	ft_memmove((str + p), s2, (len - (size_t)p + 1));
	return (str);
}

/*int	main()
{
	printf("%s", ft_strjoin("hola", " buenas"));
	return (0);
}*/
