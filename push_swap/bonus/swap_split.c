/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:30:56 by linyao            #+#    #+#             */
/*   Updated: 2024/07/30 11:57:26 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	count_substr(char *s, char c)
{
	size_t	count;
	bool	s_flag;

	count = 0;
	while (*s)
	{
		s_flag = false;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!s_flag)
			{
				count++;
				s_flag = true;
			}
			s++;
		}
	}
	return (count);
}

char	*extract_substr(char *s, char c)
{
	static int	index = 0;
	char		*substr;
	size_t		i;

	i = 0;
	while (s[index] == c)
		index++;
	while ((s[index + i] != c) && s[index + i])
		i++;
	substr = malloc((i + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while ((s[index] != c) && s[index])
		substr[i++] = s[index++];
	substr[i] = '\0';
	return (substr);
}

char	**swap_split(char *str, char c)
{
	size_t	substr_num;
	size_t	i;
	char	**splitted;

	i = 0;
	substr_num = count_substr(str, c);
	if (!substr_num)
		exit(1);
	splitted = malloc((substr_num + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	while (i < substr_num)
	{
		splitted[i] = extract_substr(str, c);
		if (!splitted[i])
		{
			ft_free_array(splitted);
			return (NULL);
		}
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}
