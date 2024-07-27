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

static char	**format_arr(int ac, char **av)
{
	char	**arr;

	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (NULL);
	else if (ac == 2)
		arr = swap_split(av[1], ' ');
	else
		arr = create_arr(ac, av);
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;	
	char	**splitted_args;

	a = NULL;
	b = NULL;
	splitted_args = format_arr(argc, argv);
	if (!splitted_args)
		return(1);
	init_stack(&a, splitted_args);
//	ra(&a, false); //test
//	for (t_stack_node *u = a; u; u = u->next) //test
//		printf("stacks reversed: %ld\n", u->value); //test
	ft_free_array(splitted_args);
	if (!stack_ordered(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			simple_sort(&a);
		else
			complex_sort(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
