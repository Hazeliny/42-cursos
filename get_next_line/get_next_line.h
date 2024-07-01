/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:04:44 by linyao            #+#    #+#             */
/*   Updated: 2024/07/01 16:27:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
static int	ft_read_file(int fd, char **storage);
static char	*ft_extract_line(char **storage);
static void	ft_free(char **storage);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_strndup(char *s, size_t n);

#endif
