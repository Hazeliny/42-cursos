/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analisis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:01:54 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:40:20 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_analisis_five(t_list **a, t_list **b)
{
	int	smallest;
	int	n_list;
	int	m_list;

	n_list = ft_count_list(*a);
	while (n_list > 3)
	{
		m_list = ft_mid_list(n_list);
		smallest = ft_find_small(*a);
		if (smallest <= m_list)
			ft_upper_list(a, b, smallest);
		else
			ft_down_list(a, b, smallest);
		n_list = ft_count_list(*a);
	}
	ft_end_list(a, b);
}

t_chunk	*ft_decide_chunk(int flag, t_list **a, t_list **b, t_chunk *chunk)
{
	if (flag == 1)
	{
		if (ft_is_bot(chunk->min, *b) == 0
			|| ft_lonely(chunk->min, chunk->size_min, *b))
			return (ft_split_chunk(chunk->size_min, b, a, a));
		else
			return (ft_split_chunk_bot(chunk->size_min, b, a, a));
	}
	if (flag == 3 && (ft_is_bot(chunk->max, *a) == 0
			|| ft_lonely(chunk->max, chunk->size_max, *a)))
		return (ft_split_chunk(chunk->size_max, a, b, a));
	else if (flag == 3)
		return (ft_split_chunk_bot(chunk->size_max, a, b, a));
	else if (ft_mid_a(chunk->mid, *a) == 0)
	{
		if (ft_is_bot(chunk->mid, *b) == 0)
			return (ft_split_chunk(chunk->size_mid, b, a, a));
		else
			return (ft_split_chunk_bot(chunk->size_mid, b, a, a));
	}
	if (ft_is_bot(chunk->mid, *a) == 0)
		return (ft_split_chunk(chunk->size_mid, a, b, a));
	else
		return (ft_split_chunk_bot(chunk->size_mid, a, b, a));
}

void	ft_recursive_chunk_sort(t_chunk *chunk,
		t_list **a, t_list **b, int flag)
{
	t_chunk	*new;

	if (chunk->division < 13)
	{
		ft_small_sort(chunk, a, b, flag);
		return ;
	}
	new = ft_decide_chunk(flag, a, b, chunk);
	ft_recursive_chunk_sort(new, a, b, 3);
	ft_recursive_chunk_sort(new, a, b, 2);
	ft_recursive_chunk_sort(new, a, b, 1);
	ft_rem_chunk(&new);
}

void	ft_analisis_push(t_list **a, t_list **b)
{
	t_chunk	*cien;

	cien = ft_split_chunk(ft_count_list(*a), a, b, a);
	ft_recursive_chunk_sort(cien, a, b, 3);
	ft_recursive_chunk_sort(cien, a, b, 2);
	ft_recursive_chunk_sort(cien, a, b, 1);
	ft_rem_chunk(&cien);
	return ;
}
