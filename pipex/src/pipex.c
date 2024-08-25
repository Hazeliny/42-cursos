/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:30:17 by linyao            #+#    #+#             */
/*   Updated: 2024/08/25 11:30:21 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exe_cmd(char **cmd, char **env)
{
	char	**array_cmd;
	char	*path_env;

	array_cmd = ft_split(cmd, ' ');
	path_env = extract_path(array_cmd[0], env);
	if (!path_env)
	{
		free_array(array_cmd);
		handle_error();
	}
	if (execve(path_env, array_cmd, env) == -1)
	{
		free_array(array_cmd);
		free(path_env);
		handle_error();
	}
	free_array(array_cmd);
	free(path_env);
}

static void	process_son(int *p_end, char **av, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		handle_error();
	dup2(fd, STDIN_FILENO);
	dup2(p_end[1], STDOUT_FILENO);
	close(p_end[0]);
	exe_cmd(av[2], env);
}

static void	process_father(int *p_end, char **av, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		handle_error();
	dup2(p_end[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(p_end[1]);
	exe_cmd(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	p_end[2];
	pid_t	np;

	if (ac != 5)
		handle_exit();
	else
	{
		if (pipe(p_end) == -1)
			handle_error();
		np = fork();
		if (np == -1)
			handle_error();
		if (!np)
			process_son(p_end, av, env);
		waitpid(np, NULL, 0);
		process_father(p_end, av, env);
	}
}
