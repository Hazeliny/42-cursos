/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_min_top2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:00:08 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:39:27 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_min_top_4_extension(t_list **a, t_list **b)
{
	ft_push_a(a, b);
	ft_rotate_b(b);
	if (*(int *)(*b)->content == 4)
		ft_push_a(a, b);
	else
	{
		ft_rotate_b(b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
	}
	ft_rev_rotate_b(b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

void	ft_min_top_4(t_list **a, t_list **b)
{
	if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
	}
	else
		ft_min_top_4_extension(a, b);
}

void	ft_min_top_3(t_list **a, t_list **b)
{
	if (*(int *)(*b)->content == 3)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else if (*(int *)(*b)->next->content == 3)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_push_a(a, b);
		ft_check_swap(NULL, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

void	ft_lonely_min_four(t_list **a, t_list **b)
{
	if (*(int *)(*b)->next->next->next->content == 4)
		ft_rev_rotate_b(b);
	else if (*(int *)(*b)->next->next->content == 4)
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
	}
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}
