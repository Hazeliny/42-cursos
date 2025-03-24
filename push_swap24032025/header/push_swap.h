/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:55:08 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 13:55:30 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/header/ft_printf.h"
# include "../printf/libft/libft.h"

typedef struct s_chunk
{
	int				p;
	int				division;
	struct s_list	*max;
	int				size_max;
	struct s_list	*mid;
	int				size_mid;
	struct s_list	*min;
	int				size_min;
}	t_chunk;

void	ft_status(t_list *a, t_list *b);
long	ft_atol(const char *nptr);
t_list	*ft_prev_tlist(t_list *last, t_list *list);
t_list	*ft_setup(char **argv);
void	del(void *content);
void	ft_swap_a(t_list **a);
void	ft_swap_b(t_list **b);
void	ft_swap_s(t_list **a, t_list **b);
void	ft_push_a(t_list **a, t_list **b);
void	ft_push_b(t_list **a, t_list **b);
void	ft_rotate_a(t_list **a);
void	ft_rotate_b(t_list **b);
void	ft_rotate_r(t_list **a, t_list **b);
void	ft_rev_rotate_a(t_list **a);
void	ft_rev_rotate_b(t_list **b);
void	ft_rev_rotate_r(t_list **a, t_list **b);
int		ft_count_list(t_list *a);
int		ft_find_small(t_list *a);
void	ft_analisis_push(t_list **a, t_list **b);
void	ft_upper_list(t_list **a, t_list **b, int p_small);
void	ft_down_list(t_list **a, t_list **b, int p_small);
void	ft_push_all(t_list **a, t_list **b);
void	ft_end_list(t_list **a, t_list **b);
int		ft_error(char **args);
int		ft_error_num(char *arg);
void	ft_analisis_five(t_list **a, t_list **b);
int		ft_mid_list(int n_list);
int		ft_find_small(t_list *a);
//coreano
void	ft_rem_chunk(t_chunk **chunk);
void	ft_share_min(t_list **c_analyze, t_list **c_split, t_list **a, int bot);
void	ft_share_mid(t_list **c_analyze, t_list **c_split, t_list **a, int bot);
void	ft_share_max(t_list **c_analyze, t_list **c_split, t_list **a, int bot);
void	ft_share_split(t_chunk *new_chunk, t_list **c_analyze, t_list **c_split,
			t_list **a);
void	ft_share_split_bot(t_chunk *new_chunk, t_list **c_analyze,
			t_list **c_split, t_list **a);
t_list	*ft_last_list(t_list *list);
t_chunk	*ft_split_chunk(int n_chunk, t_list **c_analyze,
			t_list **c_split, t_list **a);
t_chunk	*ft_split_chunk_bot(int n_chunk, t_list **c_analyze, t_list **c_split,
			t_list **a);
t_chunk	*ft_decide_chunk(int flag, t_list **a, t_list **b, t_chunk *chunk);
void	ft_recursive_chunk_sort(t_chunk *chunk, t_list **a, t_list **b,
			int flag);
void	ft_analisis_push(t_list **a, t_list **b);
int		ft_check_max(t_list *a, t_list *max);
int		ft_rr_min(t_list **c_analyze, t_list **c_split, t_chunk *chunk);
int		ft_rr_mid(t_list **c_analyze, t_list **c_split);
t_list	*ft_find_midchunk(t_list *c_analyze, t_chunk *new_chunk);
void	ft_numbers(t_list *a, int n_max);
void	ft_rev_numbers(t_list *a, int n_max);
void	ft_small_sort(t_chunk *chunk, t_list **a, t_list **b, int flag);
void	ft_check_swap(t_list **a, t_list **b);
int		ft_prev_list(t_list *last, t_list *list);
void	ft_sort_mid_bot(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_bot_a_two(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_min_2(t_list **b, t_list **a, t_chunk *chunk);
void	ft_sort_min(t_list **b, t_list **a, t_chunk *chunk);
void	ft_sort_mid_two(t_list **a, t_list **b);
void	ft_sort_mid_three(t_list **a, t_list **b);
void	ft_sort_mid(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max_top(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max_bot(t_list **a, t_list **b, t_chunk *chunk);
int		ft_is_bot(t_list *check, t_list *list);
void	ft_sort_bot_a_mid(t_list **a, t_list **b, t_chunk *chunk);
int		ft_mid_a(t_list *mid, t_list *a);
void	ft_min_is_top(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_three_top(t_list **a);
int		ft_lonely(t_list *check, int size, t_list *list);
t_list	*ft_prev(t_list *last, t_list *list);
int		ft_is_revsorted_rev(t_list *list, int size);
int		ft_is_revsorted(t_list *list, int size);
int		ft_is_sorted(t_list *list, int size);
void	ft_sort_mid_min(t_list **a, t_list **b, t_chunk *chunk);
int		ft_is_sorted_rev(t_list *list, int size);
void	ft_min_top_4_extension(t_list **a, t_list **b);
void	ft_min_top_4(t_list **a, t_list **b);
void	ft_min_top_3(t_list **a, t_list **b);
void	ft_lonely_min_four(t_list **a, t_list **b);
void	ft_sort_bottom_three_mid(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_four_max_top(t_list **a, t_list **b);
int		ft_min_on_top(t_list **b, t_chunk *chunk);

#endif
