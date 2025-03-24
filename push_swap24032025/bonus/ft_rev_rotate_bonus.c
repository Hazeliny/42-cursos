/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:51:18 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:20:00 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rev_rotate_a2(t_list **a)
{
	t_list	*last;

	if (!*a || (*a)->next == (*a))
		return ;
	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
}

void	ft_rev_rotate_b2(t_list **b)
{
	t_list	*last;

	if (!*b || (*b)->next == (*b))
		return ;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
}

void	ft_rev_rotate_r2(t_list **a, t_list **b)
{
	t_list	*last;

	if (!*a || (*a)->next == (*a))
		return (ft_rev_rotate_b2(b));
	if (!*b || (*b)->next == (*b))
		return (ft_rev_rotate_a2(a));
	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
}
