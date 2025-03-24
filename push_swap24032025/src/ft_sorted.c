/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:03:17 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:41:18 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_is_revsorted(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
	if (ft_count_list(list) < 3)
		return (0);
	temp = list->next;
	prev = list;
	while (p < size && temp)
	{
		if (*(int *)temp->content > *(int *)prev->content)
			return (0);
		temp = temp->next;
		prev = prev->next;
		p++;
	}
	return (1);
}

int	ft_is_sorted(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
	if (ft_count_list(list) < 2)
		return (0);
	temp = list->next;
	prev = list;
	while (p < size && (temp != list))
	{
		if (*(int *)prev->content > *(int *)temp->content)
			return (0);
		temp = temp->next;
		prev = prev->next;
		p++;
	}
	return (1);
}

int	ft_mid_a(t_list *mid, t_list *a)
{
	t_list	*temp;

	if (a == mid)
		return (1);
	temp = a->next;
	while (temp != a)
	{
		if (temp == mid)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_is_revsorted_rev(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
	if (ft_count_list(list) < 3)
		return (0);
	temp = ft_last_list(list);
	prev = ft_prev(temp, list);
	while (p < size && temp != list)
	{
		if (*(int *)temp->content > *(int *)prev->content)
			return (0);
		temp = ft_prev(temp, list);
		prev = ft_prev(prev, list);
		p++;
	}
	return (1);
}

int	ft_is_sorted_rev(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
	if (ft_count_list(list) < 3)
		return (0);
	temp = ft_last_list(list);
	prev = ft_prev(temp, list);
	while (p < size && (temp != list))
	{
		if (*(int *)prev->content > *(int *)temp->content)
			return (0);
		temp = ft_prev(temp, list);
		prev = ft_prev(prev, list);
		p++;
	}
	return (1);
}
