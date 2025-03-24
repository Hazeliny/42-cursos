/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:56:31 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:37:38 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_small_sort_extension(t_chunk *chunk,
				t_list **a, t_list **b, int flag)
{
	if (flag == 2)
	{
		if (chunk->size_mid == 1)
			ft_rev_rotate_a(a);
		else
		{
			ft_rev_numbers(*a, chunk->size_mid);
			ft_sort_mid_bot(a, b, chunk);
		}
	}
	else
	{
		if (chunk->size_min == 1 && chunk->min == *b)
			ft_push_a(a, b);
		else if (chunk->size_min == 1)
		{
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
		}
		else
			ft_sort_min(b, a, chunk);
	}
}

void	ft_small_sort(t_chunk *chunk, t_list **a, t_list **b, int flag)
{
	if (flag == 3 && chunk->size_max != 1)
		ft_sort_max(a, b, chunk);
	else if (ft_mid_a(chunk->mid, *a) == 0)
	{
		if (flag == 2)
		{
			if (chunk->size_mid == 1)
				ft_push_a(a, b);
			else
			{
				ft_numbers(*b, chunk->size_mid);
				ft_sort_mid(a, b, chunk);
			}
		}
		else
		{
			if (chunk->size_min == 1)
				return (ft_rev_rotate_b(b), ft_push_a(a, b));
			ft_sort_min(b, a, chunk);
		}
	}
	else
		ft_small_sort_extension(chunk, a, b, flag);
}

void	ft_check_swap(t_list **a, t_list **b)
{
	if (a && b && *(int *)(*a)->next->content < *(int *)(*a)->content
			&& *(int *)(*b)->next->content > *(int *)(*b)->content)
		ft_swap_s(a, b);
	else if (a && *(int *)(*a)->next->content < *(int *)(*a)->content)
		ft_swap_a(a);
	else if (b && *(int *)(*b)->next->content > *(int *)(*b)->content)
		ft_swap_b(b);
}

int	ft_prev_list(t_list *last, t_list *list)
{
	while (list->next != last)
		list = list->next;
	return (*(int *)list->content);
}

void	ft_sort_max(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_check_max(*a, chunk->max))
	{
		ft_numbers(*a, chunk->size_max);
		ft_sort_max_top(a, b, chunk);
	}
	else
	{
		ft_rev_numbers(*a, chunk->size_max);
		ft_sort_max_bot(a, b, chunk);
	}
}
