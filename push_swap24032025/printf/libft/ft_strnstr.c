/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:15:36 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:32:34 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	p;
	size_t	calculo;

	p = 0;
	calculo = ft_strlen(little);
	if (calculo == 0)
		return ((char *)&big[p]);
	else if (len == 0)
		return (NULL);
	while (big[p] != '\0' && p < len)
	{
		count = 0;
		while (little[count] == big[p + count] && (p + count) < len)
		{
			count++;
			if (count == calculo)
				return ((char *)&big[p]);
		}
		p++;
	}
	return (NULL);
}

/*int	main()
{
	printf("%s", ft_strnstr("hola buenas", "b", 6));
	return (0);
}*/
