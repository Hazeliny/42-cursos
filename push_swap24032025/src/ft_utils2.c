/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:03:45 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:41:39 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_lonely(t_list *check, int size, t_list *list)
{
	t_list	*temp;
	int		p;

	temp = list;
	p = 0;
	while (p < size && temp->next != list)
	{
		temp = temp->next;
		p++;
	}
	if (check == temp)
		return (1);
	return (0);
}

int	ft_check_max(t_list *a, t_list *max)
{
	int	p;

	p = 0;
	while (p < 4)
	{
		if (a == max)
			return (1);
		a = a->next;
		p++;
	}
	return (0);
}

void	ft_rem_chunk(t_chunk **chunk)
{
	(*chunk)->size_min = 0;
	(*chunk)->size_max = 0;
	(*chunk)->size_mid = 0;
	(*chunk)->max = NULL;
	(*chunk)->mid = NULL;
	(*chunk)->min = NULL;
	free (*chunk);
}

int	ft_rr_min(t_list **c_analyze, t_list **c_split, t_chunk *chunk)
{
	ft_push_b(c_analyze, c_split);
	if (chunk->max == NULL)
		chunk->max = *c_analyze;
	ft_rotate_r(c_analyze, c_split);
	return (1);
}

int	ft_rr_mid(t_list **c_analyze, t_list **c_split)
{
	ft_push_a(c_split, c_analyze);
	ft_rotate_r(c_split, c_analyze);
	return (1);
}
