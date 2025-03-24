/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:51:58 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:20:26 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap_a2(t_list **a)
{
	t_list	*last;
	t_list	*second;

	if ((*a) == NULL || (*a)->next == *a)
		return ;
	second = (*a)->next;
	last = *a;
	while (last->next != *a)
		last = last->next;
	last->next = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
}

void	ft_swap_b2(t_list **b)
{
	t_list	*last;
	t_list	*second;

	if (*b == NULL || (*b)->next == *b)
		return ;
	second = (*b)->next;
	last = *b;
	while (last->next != *b)
		last = last->next;
	last->next = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
}

void	ft_swap_s2(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*second;

	if ((*b == NULL || (*b)->next == *b) || (*a == NULL || (*a)->next == *b))
		return ;
	second = (*b)->next;
	last = *b;
	while (last->next != *b)
		last = last->next;
	last->next = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	second = (*a)->next;
	last = *a;
	while (last->next != *a)
		last = last->next;
	last->next = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
}
