/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:02 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:25:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

/*int	main()
{
	t_list	*test;
	t_list	test2;
	t_list	test3;
	t_list	*anadir;

	anadir = ft_lstnew("hola");
	test = &test2;
	test2.next = &test3;
	test3.next = NULL;
	test3.content = "adeu";
	ft_lstadd_back(&test, anadir);
	printf("%s", (char *)ft_lstlast(test)->content);
	return (0);
}*/
