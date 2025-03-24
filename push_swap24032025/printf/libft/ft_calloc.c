/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:06:01 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:24:18 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	array = (char *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

/*int	main()
{
	char	*s = (char *)ft_calloc(5, 0);
	printf("%s", s);
	return (0);
}*/
