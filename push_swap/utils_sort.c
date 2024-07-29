/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:15:26 by linyao            #+#    #+#             */
/*   Updated: 2024/07/28 16:15:31 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	both_rr(t_stack_node *cheapest_n, 
							t_stack_node **a, 
							t_stack_node **b)
{
	while (*a != cheapest_n && *b != cheapest_n->target_node)
		rr(a, b, false);
	get_index(*a);
	get_index(*b);
}

static void	both_rrr(t_stack_node *cheapest_n,
							t_stack_node **a,
							t_stack_node **b)
{
	while (*a != cheapest_n && *b != cheapest_n->target-node)
		rrr(a, b, false);
	get_index(*a);
	get_index(*b);
}

void	push_a_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_mid
		&& cheapest_node->target_node->above_mid)
		both_rr(cheapest_node, a, b);
	else if (!(cheapest_node->above_mid)
		&& !(cheapest_node->target_node->above_mid))
		both_rrr(cheapest_node, a, b);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}
void	push_b_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}
