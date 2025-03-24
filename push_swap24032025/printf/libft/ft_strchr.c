/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:13:26 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:30:35 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				p;

	ch = (unsigned char)c;
	p = 0;
	while (s[p] != '\0')
	{
		if (s[p] == ch)
			return ((char *)&s[p]);
		p++;
	}
	if (ch == 0)
		return ((char *)&s[p]);
	return (NULL);
}

/*int	main()
{
	char	*o = ft_strchr("hAola Astr" + 3, 65);
	printf("%s", o);
	return (0);
}*/
