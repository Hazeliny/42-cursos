/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_min_bot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:59:46 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:39:07 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_sort_min_4_extension(t_list **a, t_list **b)
{
	ft_push_a(a, b);
	ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 4)
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

static void	ft_sort_min_4(t_list **b, t_list **a)
{
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
		ft_sort_min_4_extension(a, b);
}

void	ft_sorted_bot_min(t_list **a, t_list **b, int size)
{
	ft_rev_rotate_b(b);
	if (size == 2)
	{
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (size == 3)
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (size == 4)
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
}

static void	ft_sort_min_extension(t_list **a, t_list **b)
{
	ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 3)
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		return (ft_check_swap(a, NULL));
	}
	ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 3)
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_check_swap(NULL, b);
		return (ft_push_a(a, b), ft_push_a(a, b));
	}
	else if (*(int *)(*b)->content != 3)
	{
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_check_swap(NULL, b);
		return (ft_push_a(a, b), ft_push_a(a, b));
	}
}

void	ft_sort_min(t_list **b, t_list **a, t_chunk *chunk)
{
	if (ft_min_on_top(b, chunk) == 1)
	{
		ft_min_is_top(a, b, chunk);
		return ;
	}
	else if (ft_is_revsorted_rev(*b, chunk->size_min) == 1)
		ft_sorted_bot_min(a, b, chunk->size_min);
	else if (chunk->size_min == 4)
	{
		ft_sort_min_4(b, a);
		return ;
	}
	else if (chunk->size_min == 3)
		ft_sort_min_extension(a, b);
	else
		ft_sort_min_2(b, a, chunk);
}
