/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:52:41 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:21:11 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# include "../printf/libft/libft.h"

char	*get_next_line(int fd);
//size_t	ft_strlen(const char *str);
//void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
//char	*ft_strjoin(char *s1, char const *s2);
//char	*ft_strdup(char *s);
//size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_read_join(char **rest, char *str_final, int fd);
char	*ft_rest(char **rest, int fd);
char	*free_and_nullify(char **s1, char **s2);

#endif
