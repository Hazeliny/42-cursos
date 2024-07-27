/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:05:50 by linyao            #+#    #+#             */
/*   Updated: 2024/07/27 13:05:51 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sk_rotate(t_stack_node **top)
{
	t_stack_node	*last_node;

	if (!(*top) || !(*top)->next)
		return ;
	last_node = find_last_node(*top);
	last_node->next = *top;
	*top = (*top)->next;
	last_node->next->prev = last_node;
	(*top)->prev = NULL;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool tag)
{
	ft_sk_rotate(a);
	if (!tag)
		write(1, "ra\n", 3);
}
