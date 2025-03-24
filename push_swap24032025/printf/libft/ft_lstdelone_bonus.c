/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:56 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:26:51 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free (lst);
}

/*void	del(void *content)
{
	content = NULL;
	free (content);
}

int	main()
{
	t_list	*test;

	test = ft_lstnew("hola");
	ft_lstdelone(test, del);
	printf("%s", (char *)test->content);
	return (0);
}*/
