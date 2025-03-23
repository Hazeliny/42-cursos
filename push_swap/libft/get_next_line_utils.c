/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:46:30 by linyao            #+#    #+#             */
/*   Updated: 2025/03/23 17:28:43 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str != '\0' && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	j = 0;
	while (j < len2)
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup_gnl(char *s)
{
	char	*d;
	size_t	i;

	if (!s)
		return (NULL);
	d = (char *)malloc(ft_strlen_gnl(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < ft_strlen_gnl(s) && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*d;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	if (n < ft_strlen_gnl(s))
		len = n;
	else
		len = ft_strlen_gnl(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	i = -1;
	while (++i < len)
		d[i] = s[i];
	d[len] = '\0';
	return (d);
}
