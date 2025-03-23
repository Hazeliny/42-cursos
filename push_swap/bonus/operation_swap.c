/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:08:35 by linyao            #+#    #+#             */
/*   Updated: 2024/07/30 11:41:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_sk_swap(t_stack_node **top)
{
	if (!(*top) || !(*top)->next)
		return ;
	*top = (*top)->next;
	(*top)->prev->prev = (*top);
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

void	sa(t_stack_node **a, bool tag)
{
	ft_sk_swap(a);
	if (!tag)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool tag)
{
	ft_sk_swap(b);
	if (!tag)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool tag)
{
	ft_sk_swap(a);
	ft_sk_swap(b);
	if (!tag)
		write(1, "ss\n", 3);
}
