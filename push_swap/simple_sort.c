/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:33:46 by linyao            #+#    #+#             */
/*   Updated: 2024/07/27 12:33:50 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack_node **a)
{
	t_stack_node	*max;

	max = search_max(*a);
	if (max == *a)
		ra(a, false);
	else if (max == (*a)->next)
		rra(a, false);
	if ((*a)->next->value < (*a)->value)
		sa(a, false);
}
