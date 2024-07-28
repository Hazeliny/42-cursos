/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:42:59 by linyao            #+#    #+#             */
/*   Updated: 2024/07/28 11:43:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);

	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	prep_push(t_stack_node **sk, t_stack_node *top, char sk_name)
{
	while (*sk != top)
	{
		if (sk_name == 'a')
		{
			if (top->above_mid)
				ra(sk, false);
			else
				rra(sk, false);
		}
		else if (sk_name == 'b')
		{
			if (top->above_mid)
				rb(sk, false);
			else
				rrb(sk, false);
		}
	}
}

void	complex_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_ordered(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_ordered(*a))
		pb(b, a,false);
	while (len_a-- > 3 && !stack_ordered(*a))
	{
		config_node_a(*a, *b);
		push_a_b(a, b);
	}
	simple_sort(a);
	while (*b)
	{
		config_node_b(*a, *b);
		push_b_a(a, b);
	}
	get_index(*a);
	min_to_top(a);
}
