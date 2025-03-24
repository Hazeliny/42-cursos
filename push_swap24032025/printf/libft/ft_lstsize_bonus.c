/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:10:22 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:28:03 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

/*int	main()
{
	t_list	*test3 = ft_lstnew("hola");
	t_list  *test2 = ft_lstnew("hola");
	t_list  *test1 = ft_lstnew("hola");

	test3->next = test2;
	test2->next = test1;
	printf("%i", ft_lstsize(test1));
	return (0);
}*/
