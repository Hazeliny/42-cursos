/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_node_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:57:34 by linyao            #+#    #+#             */
/*   Updated: 2024/07/29 19:57:38 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target;
	long		match_index;

	while (b)
	{
		match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < match_index)
			{
				match_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == LONG_MAX)
			b->target_node = search_max(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	config_node_b(t_stack_node *a, t_stack_node *b)
{
	get_index(a);
	get_index(b);
	get_target_b(a, b);
}
