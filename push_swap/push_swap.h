/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:24 by linyao            #+#    #+#             */
/*   Updated: 2024/07/25 17:20:21 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h> //test

typedef struct	s_stack_node
{
	long			value;
	int			index;
	int			push_cost;
	bool			above_midline;
	bool			cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char	**swap_split(char *str, char c);
void    ft_free_array(char **arr);
void    ft_error_msg(void);
void    init_stack(t_stack_node **a, char **arr);
int     error_nonint(char *s);
int	error_duplicate(t_stack_node *a, long l);
void    handle_errors(t_stack_node **sk);
void    ft_free_stack(t_stack_node **sk);
t_stack_node    *find_last_node(t_stack_node *sk);
t_stack_node    *search_max(t_stack_node *node);
int     stack_len(t_stack_node *sk);
bool    stack_ordered(t_stack_node *sk);
void    simple_sort(t_stack_node **a);


void    sa(t_stack_node **a, bool tag);
void    ra(t_stack_node **a, bool tag);
void    rra(t_stack_node **a, bool tag);


#endif
