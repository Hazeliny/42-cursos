/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:02:42 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:40:55 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_upper_list(t_list **a, t_list **b, int p_small)
{
	while (p_small > 1)
	{
		ft_rotate_a(a);
		p_small--;
	}
	ft_push_b(a, b);
}

void	ft_down_list(t_list **a, t_list **b, int p_small)
{
	int	max;

	max = ft_count_list(*a);
	while (p_small < max)
	{
		ft_rev_rotate_a(a);
		p_small++;
	}
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
}

void	ft_push_all(t_list **a, t_list **b)
{
	while (*b)
		ft_push_a(a, b);
}

void	ft_end_list(t_list **a, t_list **b)
{
	int	check;

	check = 0;
	ft_numbers(*a, 3);
	while (check != 2)
	{
		if (*(int *)(*a)->content == 3)
			ft_rotate_a(a);
		else if (*(int *)(*a)->content == 2 && *(int *)(*a)->next->content == 1)
			ft_swap_a(a);
		else if (*(int *)(*a)->content == 2)
			ft_rev_rotate_a(a);
		else if (*(int *)(*a)->content == 1 && *(int *)(*a)->next->content == 3)
			ft_rev_rotate_a(a);
		check++;
	}
	ft_push_all(a, b);
}
