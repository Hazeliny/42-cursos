/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:39:52 by linyao            #+#    #+#             */
/*   Updated: 2024/07/25 17:38:01 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
*/
int	main(int argc, char **argv)
{
//	int		num;
	int		i;
	int		j;
	char	**splitted_args;
//	int		splitted_argc;

	i = 1;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		splitted_args = swap_split(argv[1], ' ');
	else
	{
		splitted_args = malloc(argc * sizeof(char *));
		if (!splitted_args)
			return(1);
		j = 0;
		while (i < argc)
			splitted_args[j++] = argv[i++];
		splitted_args[j] = NULL; 
	}
	for (j = 0; splitted_args[j] != NULL; j++)
		printf("%s\n", splitted_args[j]);
	for (i = 0; splitted_args[i] != NULL; i++)
		free(splitted_args[i]);
	free(splitted_args);
	return (0);
}
/*
			num = check_argvs(splitted_argc, splitted_args);
			if (num == -1)
			{
				free(splitted_args);
				ft_error();
			}
	}
}
*/
