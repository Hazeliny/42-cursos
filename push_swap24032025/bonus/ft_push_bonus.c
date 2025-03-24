/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:51:05 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:19:42 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_last_push(t_list **add, t_list **rem)
{
	t_list	*last;

	(*rem)->next = *add;
	last = *add;
	while (last->next != *add)
		last = last->next;
	last->next = *rem;
	*add = *rem;
	*rem = NULL;
}

static void	ft_first_push(t_list **add, t_list **push)
{
	t_list	*last;

	*add = *push;
	*push = (*push)->next;
	last = *push;
	while (last->next != *add)
		last = last->next;
	last->next = *push;
	(*add)->next = *add;
}

static int	ft_check_push(t_list **analyze, t_list **other)
{
	if (!*analyze)
	{
		ft_first_push(analyze, other);
		return (1);
	}
	if ((*other)->next == *other)
	{
		ft_last_push(analyze, other);
		return (1);
	}
	return (0);
}

void	ft_push_a2(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	second = *a;
	last = *b;
	if (!*b)
		return ;
	if (ft_check_push(a, b) == 1)
		return ;
	while (last->next != *b)
		last = last->next;
	last->next = (*b)->next;
	*a = *b;
	*b = last->next;
	(*a)->next = second;
	while (second->next != (*a)->next)
		second = second->next;
	second->next = *a;
}

void	ft_push_b2(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	second = *b;
	last = *a;
	if (!*a)
		return ;
	if (ft_check_push(b, a) == 1)
		return ;
	while (last->next != *a)
		last = last->next;
	last->next = (*a)->next;
	*b = *a;
	*a = last->next;
	(*b)->next = second;
	while (second->next != (*b)->next)
		second = second->next;
	second->next = *b;
}
