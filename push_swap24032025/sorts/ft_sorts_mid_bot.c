/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_mid_bot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:58:48 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:38:41 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_prev(t_list *last, t_list *list)
{
	while (list->next != last)
		list = list->next;
	return (list);
}

static void	ft_sort_mid_bottom_four(t_list **a, t_list **b)
{
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

static void	ft_sort_bottom_three_mids(t_list **a, t_list **b, t_chunk *chunk)
{
	if (*(int *)chunk->mid->content == 3)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else if (ft_prev_list(chunk->mid, *a) == 3)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_push_b(a, b);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

static void	ft_sort_mid_bot_extension(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_prev_list(ft_prev(chunk->mid, *a), *a) == 4
		|| ft_prev_list(ft_prev(ft_prev(chunk->mid, *a), *a), *a) == 4)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_push_b(a, b);
		ft_push_b(a, b);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
		ft_sort_mid_bottom_four(a, b);
}

void	ft_sort_mid_bot(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_is_bot(chunk->min, *b) == 1)
		ft_sort_mid_min(a, b, chunk);
	else if (chunk->size_mid == 2)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else if (chunk->size_mid == 3)
		ft_sort_bottom_three_mids(a, b, chunk);
	else
		ft_sort_mid_bot_extension(a, b, chunk);
}
