/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:37:48 by linyao            #+#    #+#             */
/*   Updated: 2024/08/26 17:46:26 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_exit(void)
{
	ft_putstr_fd("Error: Incorrect numbers of arguments\n", 2);
	ft_putstr_fd("Pls Input: ./pipex infile cmd1 cmd2 outfile\n", 1);
	exit(0);
}

void	handle_error(void)
{
	perror("Error");
	exit(-1);
}

void	free_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

char	*extract_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**allpaths;
	char	*fullpath;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	allpaths = ft_split(env[i] + 5, ':');
	i = 0;
	while (allpaths[i])
	{
		path = ft_strjoin(allpaths[i], "/");
		fullpath = ft_strjoin(path, cmd);
		free(path);
		if (access(fullpath, F_OK | X_OK) == 0)
		{
			free_array(allpaths);
			return (fullpath);
		}
		free(fullpath);
		i++;
	}
	free_array(allpaths);
	return (NULL);
}
