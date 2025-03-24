/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:51:35 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:20:13 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rotate_a2(t_list **a)
{
	if (!*a || (*a)->next == (*a))
		return ;
	*a = (*a)->next;
}

void	ft_rotate_b2(t_list **b)
{
	if (!*b || (*b)->next == (*b))
		return ;
	*b = (*b)->next;
}

void	ft_rotate_r2(t_list **a, t_list **b)
{
	if (!*a || (*a)->next == (*a))
		return (ft_rotate_b2(b));
	if (!*b || (*b)->next == (*b))
		return (ft_rotate_a2(a));
	*a = (*a)->next;
	*b = (*b)->next;
}
