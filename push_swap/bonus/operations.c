/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:25:01 by linyao            #+#    #+#             */
/*   Updated: 2025/03/23 21:50:10 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void apply_operation(t_stack_node **a, t_stack_node **b, char *op)
{
    if (!ft_strncmp(op, "sa\n", 3))
        sa(a, true);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(a, b, true);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(a, b, true);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void read_operations(t_stack_node **a, t_stack_node **b)
{
    char *line;
    
    line = get_next_line(0);
    while (line)
    {
        apply_operation(a, b, line);
        free(line);
        line = get_next_line(0);
    }
}
