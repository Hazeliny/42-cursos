/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:58:42 by linyao            #+#    #+#             */
/*   Updated: 2024/07/30 11:33:50 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(char *s)
{
	long	result;
	int		mark;

	result = 0;
	mark = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			mark = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (mark * result);
}

int	add_node(t_stack_node **sk, long l)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!sk)
		return (-1);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (-1);
	new_node->next = NULL;
	new_node->value = l;
	if (!(*sk))
	{
		*sk = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*sk);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);
}

void	init_stack(t_stack_node **a, char **arr)
{
	long	l;
	int		i;

	i = 0;
	while (arr[i])
	{
		if (error_nonint(arr[i]))
			handle_errors(a);
		l = ft_atol(arr[i]);
		if (l > INT_MAX || l < INT_MIN)
			handle_errors(a);
		if (error_duplicate(*a, l))
			handle_errors(a);
		if (add_node(a, l) == -1)
			handle_errors(a);
		i++;
	}
}
