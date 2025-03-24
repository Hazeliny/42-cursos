/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:50:43 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:19:28 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../header/push_swap.h"

void	del(void *content)
{
	free(content);
	content = NULL;
}

void	ft_end_stack(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst)
		return ;
	if ((*lst)->content == NULL)
	{
		free(lst);
		return ;
	}
	temp = *lst;
	while (temp->next != *lst)
		temp = temp->next;
	temp->next = NULL;
	ft_lstclear(lst, del);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		check;

	b = NULL;
	if (argc < 2 || ft_error(argv) == -1)
	{
		ft_printf("ERROR");
		return (0);
	}
	if (argc == 2)
		return (0);
	a = ft_setup(argv);
	check = ft_moves(&a, &b);
	if (check == 0)
		check = ft_check(&a, &b);
	ft_end_stack(&a, del);
	ft_end_stack(&b, del);
	if (check == -2)
		ft_printf("Error");
	else if (check == -1)
		ft_printf("KO");
	else
		ft_printf("OK");
	return (0);
}
