/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:37:08 by linyao            #+#    #+#             */
/*   Updated: 2024/08/26 17:49:23 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_exit(void)
{
	ft_putstr_fd("Error: Incorrect numbers of arguments\n", 2);
	ft_putstr_fd("Pls Input: ./pipex infile cmd1 cmd2 ... outfile\n", 1);
	ft_putstr_fd("Or Input: ./pipex here_doc LIMITER  cmd cmd1 file\n", 1);
	exit(0);
}

void	handle_error(void)
{
	perror("Error");
	exit(-1);
}

int	open_file(char *file, int flag)
{
	int	fd;

	if (flag == 0)
		fd = open(file, O_RDONLY);
	if (flag == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (flag == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		handle_error();
	return (fd);
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
