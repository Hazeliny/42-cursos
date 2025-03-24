/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:15:02 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:32:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	p;

	p = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	while (p < len)
	{
		str[p] = f(p, s[p]);
		p++;
	}
	str[p] = '\0';
	return (str);
}

/*char	f(unsigned int n, char c)
{
	c = c + n;
	return c;
}

int	main()
{
	printf("%s", ft_strmapi("hola", f));
}*/
