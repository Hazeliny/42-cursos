/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:04:55 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:42:44 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_count_list(t_list *a)
{
	t_list	*temp;
	int		count;

	temp = a;
	count = 1;
	if (!a)
		return (0);
	while (temp->next != a)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_mid_list(int n_list)
{
	int	mid;

	if (n_list % 2 != 0)
		n_list++;
	mid = n_list / 2;
	return (mid);
}

int	ft_find_small(t_list *a)
{
	t_list	*temp;
	t_list	*small;
	int		n_small;
	int		count;

	count = 1;
	n_small = *(int *)a->content;
	small = a;
	temp = a->next;
	while (temp != a)
	{
		if (n_small > *(int *)temp->content)
		{
			n_small = *(int *)temp->content;
			small = temp;
		}
		temp = temp->next;
	}
	while (a != small)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	ft_is_bot(t_list *check, t_list *list)
{
	if (ft_last_list(list) == check)
		return (1);
	return (0);
}

t_list	*ft_last_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next != list)
		temp = temp->next;
	return (temp);
}
