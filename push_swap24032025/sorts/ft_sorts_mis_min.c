/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_mis_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:00:47 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:39:55 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_sort_mid_bottom_four(t_list **a, t_list **b, t_chunk *chunk)
{
	ft_rev_rotate_r(a, b);
	ft_rev_rotate_r(a, b);
	ft_rev_rotate_r(a, b);
	ft_push_b(a, b);
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, b);
	if (chunk->size_min == 4)
		ft_rev_rotate_b(b);
}

static void	ft_sorted_mid_extension(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_min == 4)
	{
		ft_rev_rotate_r(a, b);
		ft_rev_rotate_r(a, b);
		ft_rev_rotate_r(a, b);
	}
	else if (chunk->size_min == 3)
	{
		ft_rev_rotate_r(a, b);
		ft_rev_rotate_r(a, b);
		ft_rev_rotate_a(a);
	}
}

static void	ft_sorted_mid(t_list **a, t_list **b, t_chunk *chunk)
{
	ft_rev_rotate_r(a, b);
	if (chunk->size_mid == 2)
	{
		if (chunk->size_min > 1)
			ft_rev_rotate_r(a, b);
		else
			ft_rev_rotate_a(a);
	}
	else if (chunk->size_mid == 3)
	{
		if (chunk->size_min == 2)
		{
			ft_rev_rotate_r(a, b);
			ft_rev_rotate_a(a);
		}
		else if (chunk->size_min == 3)
		{
			ft_rev_rotate_r(a, b);
			ft_rev_rotate_r(a, b);
		}
	}
	else if (chunk->size_mid == 4)
		ft_sorted_mid_extension(a, b, chunk);
}

static void	ft_sort_mid_min_extension(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_prev_list(ft_prev(chunk->mid, *a), *a) == 4
		|| ft_prev_list(ft_prev(ft_prev(chunk->mid, *a), *a), *a) == 4)
	{
		ft_rev_rotate_r(a, b);
		ft_rev_rotate_r(a, b);
		ft_push_b(a, b);
		ft_push_b(a, b);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_rev_rotate_b(b);
		if (chunk->size_min == 4)
			ft_rev_rotate_b(b);
	}
	else
		ft_sort_mid_bottom_four(a, b, chunk);
}

void	ft_sort_mid_min(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_is_sorted_rev(*a, chunk->size_mid) == 1)
	{
		ft_sorted_mid(a, b, chunk);
		return ;
	}
	else if (chunk->size_mid == 2)
	{
		ft_rev_rotate_r(a, b);
		if (chunk->size_min == 2)
			ft_rev_rotate_r(a, b);
		else
			ft_rev_rotate_a(a);
		if (chunk->size_min == 2)
			ft_check_swap(a, b);
		else
			ft_check_swap(a, NULL);
	}
	else if (chunk->size_mid == 3)
		ft_sort_bottom_three_mid(a, b, chunk);
	else
		ft_sort_mid_min_extension(a, b, chunk);
}
