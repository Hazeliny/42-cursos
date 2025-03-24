/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:58:01 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 13:58:06 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rev_rotate_a(t_list **a)
{
	t_list	*last;

	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
	ft_printf("rra\n");
}

void	ft_rev_rotate_b(t_list **b)
{
	t_list	*last;

	if (!*b || (*b)->next == (*b))
		return ;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
	ft_printf("rrb\n");
}

void	ft_rev_rotate_r(t_list **a, t_list **b)
{
	t_list	*last;

	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
	ft_printf("rrr\n");
}
