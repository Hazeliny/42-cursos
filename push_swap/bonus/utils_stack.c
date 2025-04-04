/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:31:37 by linyao            #+#    #+#             */
/*   Updated: 2025/03/23 21:53:22 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack_node	*find_last_node(t_stack_node *sk)
{
	if (!sk)
		return (NULL);
	while (sk->next)
		sk = sk->next;
	return (sk);
}

int	stack_len(t_stack_node *sk)
{
	int	len;

	if (!sk)
		return (0);
	len = 0;
	while (sk)
	{
		sk = sk->next;
		len++;
	}
	return (len);
}

bool	stack_ordered(t_stack_node *sk)
{
	if (!sk)
		return (1);
	while (sk->next)
	{
		if (sk->value > sk->next->value)
			return (false);
		sk = sk->next;
	}
	return (true);
}

t_stack_node	*search_max(t_stack_node *node)
{
	long			max;
	t_stack_node	*node_max;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			node_max = node;
		}
		node = node->next;
	}
	return (node_max);
}

t_stack_node	*search_min(t_stack_node *node)
{
	long			min;
	t_stack_node	*node_min;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			node_min = node;
		}
		node = node->next;
	}
	return (node_min);
}