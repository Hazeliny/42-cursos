/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:03:34 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:41:28 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static	t_chunk	*ft_num_chunk(int n_chunk)
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new_chunk)
		return (NULL);
	new_chunk->division = n_chunk;
	new_chunk->size_min = n_chunk / 3;
	if (n_chunk % 3 == 2)
	{
		new_chunk->size_max = (n_chunk / 3) + 1;
		new_chunk->size_mid = (n_chunk / 3) + 1;
	}
	else if (n_chunk % 3 == 1)
	{
		new_chunk->size_mid = (n_chunk / 3);
		new_chunk->size_max = (n_chunk / 3) + 1;
	}
	else
	{
		new_chunk->size_max = (n_chunk / 3);
		new_chunk->size_mid = (n_chunk / 3);
	}
	new_chunk->p = 0;
	return (new_chunk);
}

t_chunk	*ft_split_chunk_bot(int n_chunk,
			t_list **c_analyze, t_list **c_split, t_list **a)
{
	t_chunk	*new_chunk;

	new_chunk = ft_num_chunk(n_chunk);
	ft_share_split_bot(new_chunk, c_analyze, c_split, a);
	if (c_analyze == a)
		new_chunk->min = ft_last_list(*c_split);
	if (c_analyze != a)
	{
		new_chunk->mid = NULL;
		new_chunk->mid = ft_last_list(*c_split);
	}
	return (new_chunk);
}

t_chunk	*ft_split_chunk(int n_chunk,
			t_list **c_analyze, t_list **c_split, t_list **a)
{
	t_chunk	*new_chunk;

	new_chunk = ft_num_chunk(n_chunk);
	ft_share_split(new_chunk, c_analyze, c_split, a);
	if (c_analyze != a)
	{
		new_chunk->mid = NULL;
		new_chunk->mid = ft_last_list(*c_split);
	}
	if (c_analyze != a)
		new_chunk->min = ft_last_list(*c_analyze);
	else
		new_chunk->min = ft_last_list(*c_split);
	if (c_analyze == a)
	{
		new_chunk->max = NULL;
		new_chunk->max = ft_last_list(*c_analyze);
	}
	return (new_chunk);
}
