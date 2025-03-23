/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:00:15 by linyao            #+#    #+#             */
/*   Updated: 2025/03/23 21:51:41 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

	a = NULL;
	b = NULL;
	splitted_args = format_arr(argc, argv);
	if (!splitted_args)
		return (1);
	init_stack(&a, splitted_args);
	ft_free_array(splitted_args);
    read_operations(&a, &b);
	if (stack_ordered(a) && stack_len(b) == 0)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}