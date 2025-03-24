/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_min_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:00:26 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:39:40 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_lonely_min_three(t_list **a, t_list **b)
{
	if (*(int *)(*b)->next->next->content == 3)
		ft_rev_rotate_b(b);
	else if (*(int *)(*b)->next->content == 3)
		ft_rotate_b(b);
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

void	ft_min_lonely_sort(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_min == 4)
		ft_lonely_min_four(a, b);
	else if (chunk->size_min == 3)
		ft_lonely_min_three(a, b);
	else if (chunk->size_min == 2)
	{
		ft_check_swap(NULL, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else
		ft_push_a(a, b);
}

static void	ft_sorted_min_one(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (size == 3)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (size == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
}

static void	ft_min_is_top_extension(t_list **a, t_list **b)
{
	if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
		ft_min_top_4(a, b);
}

void	ft_min_is_top(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_is_revsorted(*b, chunk->size_min) == 1)
		ft_sorted_min_one(a, b, chunk->size_min);
	else if (ft_lonely(chunk->min, chunk->size_min, *b) == 1)
		ft_min_lonely_sort(a, b, chunk);
	else if (chunk->size_min == 2)
	{
		ft_check_swap(NULL, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (chunk->size_min == 3)
		ft_min_top_3(a, b);
	else
		ft_min_is_top_extension(a, b);
}
