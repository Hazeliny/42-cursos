/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:04 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:33:01 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(const char *s1, unsigned char *set)
{
	size_t	start;
	int		p;

	start = 0;
	while (s1[start] != '\0')
	{
		p = 0;
		while (set[p] != '\0')
		{
			if (s1[start] == set[p])
			{
				start++;
				p = 0;
			}
			else
				p++;
		}
		if (set[p] == '\0')
			break ;
	}
	return (start);
}

static size_t	ft_end(const char *s1, unsigned char *set)
{
	size_t	end;
	int		p;

	end = ft_strlen(s1) - 1;
	while (end > 0)
	{
		p = 0;
		while (set[p] != '\0')
		{
			if (s1[end] == set[p])
			{
				end--;
				break ;
			}
			else
				p++;
		}
		if (set[p] == '\0')
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		p;
	size_t	start;
	size_t	end;

	p = 0;
	if (!s1)
		return (NULL);
	else if (!set || s1[0] == '\0')
		return (ft_strdup(s1));
	start = ft_start(s1, (unsigned char *)set);
	end = ft_end(s1, (unsigned char *)set);
	if (end < start)
		return (ft_strdup(""));
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[p] = s1[start];
		p++;
		start++;
	}
	str[p] = '\0';
	return (str);
}

/*int	main()
{
	printf("%s", ft_strtrim("\t ", "\t "));
	return (0);
}*/
