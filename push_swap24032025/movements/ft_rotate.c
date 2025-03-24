/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:58:39 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 13:58:46 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rotate_a(t_list **a)
{
	*a = (*a)->next;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_list **b)
{
	*b = (*b)->next;
	ft_printf("rb\n");
}

void	ft_rotate_r(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_printf("rr\n");
}
