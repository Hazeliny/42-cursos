/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:59:10 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 13:59:17 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap_a(t_list **a)
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
	ft_printf("sa\n");
}

void	ft_swap_b(t_list **b)
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
	ft_printf("sb\n");
}

void	ft_swap_s(t_list **a, t_list **b)
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
	ft_printf("ss\n");
}
