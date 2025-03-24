/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:13:14 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:30:20 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *w, char c)
{
	int	count;
	int	in_word;
	int	p;

	p = 0;
	count = 0;
	in_word = 0;
	while (w[p] != '\0')
	{
		if (w[p] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (w[p] == c)
			in_word = 0;
		p++;
	}
	return (count);
}

static void	ft_free_todo(int p, char **word)
{
	while (p >= 0)
	{
		free (word[p]);
		p--;
	}
	free (word);
	return ;
}

static char	**ft_cpy(char const *s, char **word, char c, int count)
{
	size_t	start;
	size_t	end;
	int		p;

	p = 0;
	start = 0;
	while (p < count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while ((s[end] != c) && (s[end] != '\0'))
			end++;
		word[p] = ft_substr(s, start, (end - start));
		if (!word[p])
		{
			ft_free_todo(p, word);
			return (NULL);
		}
		start = end;
		p++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		count;

	count = ft_word_count(s, c);
	word = (char **)malloc((count + 1) * sizeof(char *));
	if (!word)
		return (NULL);
	word = ft_cpy(s, word, c, count);
	word[count] = NULL;
	return (word);
}

/*int	main()
{
	int	p = 0;
	char	**h = (ft_split(" hola    buenas   como estas   ? ", ' '));
	
	while (h[p])
	{
		printf("%s", h[p]);
		printf("%c", '\n');
		p++;
	}
	printf("%s", h[p]);
	return (0);
}*/
