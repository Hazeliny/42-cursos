/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:57:05 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:38:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_sort_bottom_three_mid_extension(t_list **a,
				t_list **b, t_chunk *chunk)
{
	ft_rev_rotate_r(a, b);
	ft_rev_rotate_r(a, b);
	ft_push_b(a, b);
	ft_rev_rotate_a(a);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	if (chunk->size_min == 3)
	{
		ft_rev_rotate_b(b);
		ft_check_swap(a, b);
	}
	ft_check_swap(a, NULL);
}

static void	ft_sort_bottom_three_mid_extension2(t_list **a,
				t_list **b, t_chunk *chunk)
{
	ft_rev_rotate_r(a, b);
	ft_rev_rotate_r(a, b);
	ft_check_swap(a, b);
	if (chunk->size_min == 3)
	{
		ft_rev_rotate_r(a, b);
		ft_check_swap(a, b);
	}
	else
	{
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
}

void	ft_sort_bottom_three_mid(t_list **a, t_list **b, t_chunk *chunk)
{
	if (*(int *)chunk->mid->content == 3)
	{
		ft_rev_rotate_r(a, b);
		ft_rev_rotate_r(a, b);
		if (chunk->size_min == 3)
			ft_rev_rotate_r(a, b);
		else
			ft_rev_rotate_a(a);
		ft_check_swap(a, b);
	}
	else if (ft_prev_list(chunk->mid, *a) == 3)
		ft_sort_bottom_three_mid_extension2(a, b, chunk);
	else
		ft_sort_bottom_three_mid_extension(a, b, chunk);
}

void	ft_sort_four_max_top(t_list **a, t_list **b)
{
	if (*(int *)(*a)->next->content == 4)
	{
		ft_push_b(a, b);
		ft_swap_a(a);
		ft_push_b(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_swap_a(a);
		ft_push_b(a, b);
		ft_swap_a(a);
		ft_push_b(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

int	ft_min_on_top(t_list **b, t_chunk *chunk)
{
	int		i;
	int		res;
	t_list	*head;

	i = 0;
	res = 0;
	head = *b;
	while (chunk->size_min >= i)
	{
		if (chunk->min == head)
		{
			res = 1;
			break ;
		}
		i++;
		if (!(head->next))
			break ;
		head = head->next;
	}
	return (res);
}
