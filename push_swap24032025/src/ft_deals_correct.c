/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deals_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:02:30 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:40:45 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_share_split_max(t_chunk *new_chunk, t_list **c_analyze,
			t_list **c_split, t_list **a)
{
	if (new_chunk->max == NULL)
		new_chunk->max = *c_analyze;
	ft_share_max(c_analyze, c_split, a, 0);
}

static void	ft_share_split_mid(t_chunk *new_chunk, t_list **c_analyze,
			t_list **c_split, t_list **a)
{
	if (((new_chunk->p + 1) < new_chunk->division) && c_analyze
		== a && *(int *)(*c_analyze)->next->content
		> (new_chunk->size_min + new_chunk->size_mid))
		new_chunk->p += ft_rr_min(c_analyze, c_split, new_chunk);
	else
		ft_share_min(c_analyze, c_split, a, 0);
}

void	ft_share_split(t_chunk *new_chunk, t_list **c_analyze,
		t_list **c_split, t_list **a)
{
	ft_numbers(*c_analyze, new_chunk->division);
	while (new_chunk->p++ < new_chunk->division)
	{
		if (*(int *)(*c_analyze)->content <= new_chunk->size_min)
			ft_share_split_mid(new_chunk, c_analyze, c_split, a);
		else if (*(int *)(*c_analyze)->content
				<= (new_chunk->size_min + new_chunk->size_mid))
		{
			if (new_chunk->mid == NULL)
				new_chunk->mid = *c_analyze;
			if (((new_chunk->p + 1) < new_chunk->division) && c_analyze != a
				&& *(int *)(*c_analyze)->next->content <= new_chunk->size_min)
				new_chunk->p += ft_rr_mid(c_analyze, c_split);
			else
				ft_share_mid(c_analyze, c_split, a, 0);
		}
		else
			ft_share_split_max(new_chunk, c_analyze, c_split, a);
	}
}

void	ft_share_split_bot(t_chunk *new_chunk, t_list **c_analyze,
		t_list **c_split, t_list **a)
{
	int	value;

	ft_rev_numbers(*c_analyze, new_chunk->division);
	while (new_chunk->p++ < new_chunk->division)
	{
		value = *(int *)(ft_last_list(*c_analyze))->content;
		if (value <= new_chunk->size_min)
		{
			if (new_chunk->min == NULL)
				new_chunk->min = ft_last_list(*c_analyze);
			ft_share_min(c_analyze, c_split, a, 1);
		}
		else if (value <= (new_chunk->size_min + new_chunk->size_mid))
		{
			if (new_chunk->mid == NULL)
				new_chunk->mid = ft_last_list(*c_analyze);
			ft_share_mid(c_analyze, c_split, a, 1);
		}
		else
		{
			if (new_chunk->max == NULL)
				new_chunk->max = ft_last_list(*c_analyze);
			ft_share_max(c_analyze, c_split, a, 1);
		}
	}
}
