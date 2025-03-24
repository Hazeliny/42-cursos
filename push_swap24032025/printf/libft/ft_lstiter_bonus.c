/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:09:21 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:27:06 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst || !f)
		return ;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/*void	f(void *content)
{
	t_list	*str;
	str = (t_list *)content;
	str->content = "hola";
	return ;
}

int	main()
{
	t_list	*test;
	t_list	*test2;
	t_list	*test3;

	test = ft_lstnew("adeu");
	test2 = ft_lstnew("adeu");
	test3 = ft_lstnew("adeu");
	test->next = test2;
	test2->next = test3;
	test3->next = NULL;
	ft_lstiter(test, f);
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
	printf("%s", (char *)test3->content);
	return (0);
}*/
