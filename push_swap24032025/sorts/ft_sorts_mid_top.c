/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_mid_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:59:07 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:38:55 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_four(t_list **a, t_list **b, t_chunk *chunk)
{
	ft_push_a(a, b);
	ft_rotate_b(b);
	ft_rotate_b(b);
	ft_push_a(a, b);
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	if (chunk->division == 1)
		return ;
}

void	ft_sort_mid_two(t_list **a, t_list **b)
{
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

void	ft_sort_mid_three(t_list **a, t_list **b)
{
	if (*(int *)(*b)->content == 3 || (*(int *)(*b)->next->content == 3))
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
		ft_rotate_b(b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

static void	ft_sort_mid_extension(t_list **a, t_list **b, t_chunk *chunk)
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
	else if (*(int *)(*b)->next->next->content == 4)
	{
		ft_push_a(a, b);
		ft_rotate_b(b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
		ft_sort_four(a, b, chunk);
}

void	ft_sort_mid(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_mid == 4)
		ft_sort_mid_extension(a, b, chunk);
	else if (chunk->size_mid == 2)
		ft_sort_mid_two(a, b);
	else
		ft_sort_mid_three(a, b);
}
