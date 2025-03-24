/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:09:35 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:27:19 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

/*int	main()
{
	t_list	*test;
	t_list	test2;
	t_list	test3;
	t_list	test4;

	test4.content = "hola";
	test3.content = "adeu";
	test2.content = "adeu";
	test = &test2;
	test2.next = &test3;
	test3.next = &test4;
	test4.next = NULL;
	printf("%s", (char *)ft_lstlast(test)->content);
	return (0);
}*/
