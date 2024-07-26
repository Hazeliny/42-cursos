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

void	ft_error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_array(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}
char	**create_arr(int arc, char **arv)
{
	int	i;
	int	j;
	char	**new_arr;

	new_arr = malloc(arc * sizeof(char *));
	if (!new_arr)
		return (NULL);
	i = 1;
	j = 0;
	while (i < arc)
	{
		new_arr[j] = ft_strdup(arv[i]);
		if (!new_arr[j])
		{
			ft_free_array(new_arr);
			return (NULL);
		}
		i++;
		j++;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
//	t_stack_node	*b;	
//	int		i;
	int		j;
	char	**splitted_args;
//	int		splitted_argc;

//	i = 1;
	a = NULL;
//	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		splitted_args = swap_split(argv[1], ' ');
	else
		splitted_args = create_arr(argc, argv);
	if (!splitted_args)
		return(1);
	for (j = 0; splitted_args[j] != NULL; j++) //test
		printf("%s\n", splitted_args[j]); //test
	init_stack(&a, splitted_args);
	for (t_stack_node *cu = a; cu; cu = cu->next) //test
		printf("stacks: %ld\n", cu->value); //test
	ft_free_array(splitted_args);
	ft_free_stack(&a);
	return (0);
}
