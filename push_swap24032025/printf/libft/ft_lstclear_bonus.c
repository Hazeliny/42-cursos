/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:37 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:26:26 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*rem;
	t_list	*mov;

	if (!del || !lst)
		return ;
	rem = *lst;
	while (rem != NULL)
	{
		mov = rem->next;
		ft_lstdelone(rem, del);
		rem = mov;
	}
	*lst = NULL;
}

/*void	del(void *content)
{
	content = NULL;
	free (content);
}

int	main()
{
	t_list	**test;
	t_list	*test2;
	t_list	*test3;

	test = (t_list **)malloc(sizeof(t_list *));
	test2 = ft_lstnew("caracola");
	test3 = ft_lstnew("adeu");
	*test = test2;
	test2->next = test3;
	test3->next = NULL;
	ft_lstclear(test, del);
	printf("%s", (char *)test2->content);
	return (0);
}*/
