/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:05:20 by linyao            #+#    #+#             */
/*   Updated: 2025/03/23 20:17:49 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct s_stack_node
{
	long				value;
	int					index;
	int					push_cost;
	bool				above_mid;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**swap_split(char *str, char c);
void			ft_free_array(char **arr);
void    init_stack(t_stack_node **a, char **arr);
int				error_nonint(char *s);
void			handle_errors(t_stack_node **sk);
int				error_duplicate(t_stack_node *a, long l);
void			ft_free_stack(t_stack_node **sk);
void			ft_error_msg(void);
t_stack_node	*find_last_node(t_stack_node *sk);
t_stack_node	*search_max(t_stack_node *node);
t_stack_node	*search_min(t_stack_node *node);
int				stack_len(t_stack_node *sk);
bool			stack_ordered(t_stack_node *sk);
/*
void			simple_sort(t_stack_node **a);
void			complex_sort(t_stack_node **a, t_stack_node **b);
void			config_node_a(t_stack_node *a, t_stack_node *b);
void			config_node_b(t_stack_node *a, t_stack_node *b);
void			get_index(t_stack_node *node);
void			config_cheapest(t_stack_node *node);
void			push_a_b(t_stack_node **a, t_stack_node **b);
void			push_b_a(t_stack_node **a, t_stack_node **b);
t_stack_node	*get_cheapest(t_stack_node *node);
void			prep_push(t_stack_node **sk, t_stack_node *top, char sk_name);
*/
void			sa(t_stack_node **a, bool tag);
void			sb(t_stack_node **b, bool tag);
void			ss(t_stack_node **a, t_stack_node **b, bool tag);
void			ra(t_stack_node **a, bool tag);
void			rb(t_stack_node **b, bool tag);
void			rr(t_stack_node **a, t_stack_node **b, bool tag);
void			rra(t_stack_node **a, bool tag);
void			rrb(t_stack_node **b, bool tag);
void			rrr(t_stack_node **a, t_stack_node **b, bool tag);
void			pa(t_stack_node **a, t_stack_node **b, bool tag);
void			pb(t_stack_node **b, t_stack_node **a, bool tag);


void apply_operation(t_stack_node **a, t_stack_node **b, char *op);
void read_operations(t_stack_node **a, t_stack_node **b);



#endif
