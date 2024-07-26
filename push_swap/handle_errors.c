/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:24:11 by linyao            #+#    #+#             */
/*   Updated: 2024/07/26 14:24:32 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_nonint(char *s)
{
	if (!(*s == '+' || *s == '-'
			|| (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-')
		&& (s[1] < '0' || s[1] > '9'))
		return (1);
	while (*(++s))
	{
		if (*s < '0' || *s > '9')
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *node, long l)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->value == l)
			return (1);
		node = node->next;
	}
	return (0);
}

void	ft_free_stack(t_stack_node **sk)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!sk || !(*sk))
		return ;
	current = *sk;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*sk = NULL;
}

void	handle_errors(t_stack_node **sk)
{
	ft_free_stack(sk);
	ft_error_msg();
	exit (1);
}
