/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:12 by linyao            #+#    #+#             */
/*   Updated: 2024/08/02 16:22:47 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "checker.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdib.h>

char	**create_arr(int arc, char **arv)
{
	int		i;
	int		j;
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
	char			**splitted_args;
	int				len;
	char			*str;

	a = NULL;
	b = NULL;
	splitted_args = format_arr(argc, argv);
	if (!splitted_args)
		return (1);
	init_stack(&a, splitted_args);
	ft_free_array(splitted_args);
	len = stack_len(a);
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		handle_operations(&a, &b, str);
		str = get_next_line(STDIN_FILENO);
	}
	if (stack_ordered(a) && len == stack_len(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
	return (0);
}
