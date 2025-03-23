/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:35:23 by linyao            #+#    #+#             */
/*   Updated: 2024/07/30 11:36:18 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_sk_push(t_stack_node **dst, t_stack_node **org)
{
	t_stack_node	*to_push;

	if (!(*org))
		return ;
	to_push = *org;
	*org = (*org)->next;
	if (*org)
		(*org)->prev = NULL;
	to_push->prev = NULL;
	if (!(*dst))
	{
		*dst = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dst;
		to_push->next->prev = to_push;
		*dst = to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool tag)
{
	ft_sk_push(a, b);
	if (!tag)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool tag)
{
	ft_sk_push(b, a);
	if (!tag)
		write(1, "pb\n", 3);
}
