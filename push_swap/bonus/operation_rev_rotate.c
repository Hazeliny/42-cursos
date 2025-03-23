/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:36:51 by linyao            #+#    #+#             */
/*   Updated: 2024/07/30 11:38:06 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_sk_rev_rotate(t_stack_node **top)
{
	t_stack_node	*last_node;

	if (!(*top) || !(*top)->next)
		return ;
	last_node = find_last_node(*top);
	last_node->prev->next = NULL;
	last_node->next = *top;
	last_node->prev = NULL;
	*top = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool tag)
{
	ft_sk_rev_rotate(a);
	if (!tag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool tag)
{
	ft_sk_rev_rotate(b);
	if (!tag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool tag)
{
	ft_sk_rev_rotate(a);
	ft_sk_rev_rotate(b);
	if (!tag)
		write(1, "rrr\n", 4);
}
