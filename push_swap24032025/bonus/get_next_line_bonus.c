/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:52:27 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:21:01 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_and_nullify(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX + 1];
	char		*str_final;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (rest[fd] && rest[fd][0] != '\0')
		str_final = ft_rest(rest, fd);
	else
		str_final = ft_strdup("");
	if (!str_final)
		return (NULL);
	if (!ft_strchr(str_final, '\n'))
		str_final = ft_read_join(rest, str_final, fd);
	if (!str_final || str_final[0] == '\0')
	{
		free_and_nullify(&str_final, &rest[fd]);
		return (NULL);
	}
	if (rest[fd] && rest[fd][0] == '\0')
		free_and_nullify(&rest[fd], NULL);
	return (str_final);
}

char	*ft_read_join(char **rest, char *str_final, int fd)
{
	char	*str_join;

	str_join = malloc(BUFFER_SIZE + 1);
	if (!str_join)
		return (free_and_nullify(&str_final, NULL));
	ft_bzero(str_join, BUFFER_SIZE + 1);
	while (read(fd, str_join, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(str_join, '\n'))
		{
			rest[fd] = ft_strdup(ft_strchr(str_join, '\n') + 1);
			if (!rest[fd])
				return (free_and_nullify(&str_final, &str_join));
			ft_bzero(ft_strchr(str_join, '\n') + 1, BUFFER_SIZE
				- (ft_strchr(str_join, '\n') - str_join) - 1);
			str_final = ft_strjoin(str_final, str_join);
			break ;
		}
		str_final = ft_strjoin(str_final, str_join);
		if (!str_final)
			return (free_and_nullify(NULL, &str_join));
		ft_bzero(str_join, BUFFER_SIZE);
	}
	return (free(str_join), str_final);
}

char	*ft_rest(char **rest, int fd)
{
	char	*str;

	if (rest[fd][0] == '\n')
	{
		str = ft_strdup("\n");
		if (rest[fd][1] == '\0')
			free_and_nullify(&rest[fd], NULL);
		else
			ft_strlcpy(rest[fd], rest[fd] + 1, ft_strlen(rest[fd]));
		return (str);
	}
	str = ft_strdup(rest[fd]);
	if (str && ft_strchr(str, '\n'))
	{
		ft_bzero(ft_strchr(str, '\n') + 1, ft_strlen(str)
			- (ft_strchr(str, '\n') - str) - 1);
		ft_strlcpy(rest[fd], ft_strchr(rest[fd], '\n') + 1, BUFFER_SIZE);
	}
	else
		free_and_nullify(&rest[fd], NULL);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			p;

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

/*int	main(int argc, char *argv[])
{
	int	fd = open(argv[1], O_RDONLY);
	//int	fd2 = open(argv[2], O_RDONLY);
	char *word = get_next_line(fd);
	//char *word2 = get_next_line(fd2);
	while (word)
	{
		printf("%s", word);
		//printf("%s", word2);
		free(word);
		//free(word2);
		word = get_next_line(fd);
		//word2 = get_next_line(fd2);
	}
	printf("%s", word);
	//printf("%s", word2);
	close(fd);
	//close (fd2);
	printf("%i", argc);
	return (0);
}*/
