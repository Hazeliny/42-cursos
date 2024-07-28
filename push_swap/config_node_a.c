/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_node_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:39:42 by linyao            #+#    #+#             */
/*   Updated: 2024/07/28 14:39:45 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack_node *node)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= mid)
			node->above_mid = true;
		else
			node->above_mid = false;
		node = node->next;
		i++;
	}
}

static void	get_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target;
	long		match_index;

	while (a)
	{
		match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > match_index)
			{
				match_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == LONG_MIN)
			a->target_node = search_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	get_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_mid))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_mid)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	get_cheapest(t_stack_node *node)
{
	long		cheapest_price;
	t_stack_node	*cheapest_node;

	if (!node)
		return ;
	cheapest_price = LONG_MAX;
	while (node)
	{
		if (node->push_cost < cheapest_price)
		{
			cheapest_price = node->push_cost;
			cheapest_node = node;
		}
		node = node->next;
	}
	cheapest_node->cheapest = true;
}

void	config_node_a(t_stack_node *a, t_stack_node *b)
{
	get_index(a);
	get_index(b);
	get_target_a(a, b);
	get_cost_a(a, b);
	get_cheapest(a);
}
