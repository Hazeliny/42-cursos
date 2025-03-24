/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:04:26 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:42:20 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <limits.h>

#include <stdlib.h>

static int	*copy_values(t_list *a, int size)
{
	int		*values;
	int		i;
	t_list	*head;

	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	head = a;
	i = 0;
	while (i < size)
	{
		values[i] = *(int *)head->content;
		head = head->next;
		i++;
	}
	return (values);
}

static void	sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_new_positions(t_list *a, int *values, int size)
{
	int		i;
	int		j;
	t_list	*head;

	head = a;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (*(int *)head->content == values[j])
			{
				*(int *)head->content = j + 1;
				break ;
			}
			j++;
		}
		head = head->next;
		i++;
	}
}

void	ft_numbers(t_list *a, int size)
{
	int	*values;

	if (!a || size <= 0)
		return ;
	values = copy_values(a, size);
	if (!values)
		return ;
	sort_values(values, size);
	assign_new_positions(a, values, size);
	free(values);
}

void	ft_rev_numbers(t_list *a, int size)
{
	t_list	*head;
	t_list	*node;
	int		current_order;
	int		min_processed;
	int		i;	

	current_order = 0;
	min_processed = -2147483648;
	while (current_order++ < size)
	{
		i = 0;
		head = ft_last_list(a);
		node = NULL;
		while (head->next != head && i++ < size)
		{
			if ((*(int *)head->content > min_processed)
				&& (!node || *(int *)head->content < *(int *)node->content))
				node = head;
			head = ft_prev_tlist(head, a);
		}
		if (!node)
			break ;
		*(int *)node->content = current_order;
		min_processed = *(int *)node->content;
	}
}
