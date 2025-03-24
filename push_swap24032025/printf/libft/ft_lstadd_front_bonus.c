/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:23 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:26:12 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main()
{
	t_list	*test = ft_lstnew("hola");
	t_list	*test2 = ft_lstnew("adeu");
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
	ft_lstadd_front(&test, test2);
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
}*/
