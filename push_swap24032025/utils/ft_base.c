/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:04:13 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:42:08 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_setup(char **argv)
{
	int		p;
	int		num;
	t_list	*dest;
	t_list	*temp;

	p = 2;
	num = ft_atoi(argv[1]);
	temp = ft_lstnew((void *)malloc(sizeof(int)));
	*(int *)temp->content = num;
	dest = temp;
	temp = temp->next;
	while (argv[p])
	{
		num = ft_atoi(argv[p]);
		temp = ft_lstnew((void *)malloc(sizeof(int)));
		*(int *)(temp->content) = num;
		ft_lstadd_back(&dest, temp);
		p++;
	}
	temp->next = dest;
	temp = NULL;
	ft_lstdelone(temp, del);
	return (dest);
}

t_list	*ft_prev_tlist(t_list *last, t_list *list)
{
	while (list->next != last)
		list = list->next;
	return (list);
}

long	ft_atol(const char *nptr)
{
	int		p;
	int		sign;
	long	num;

	sign = 1;
	p = 0;
	num = 0;
	while (nptr[p] == 32 || (nptr[p] >= 9 && nptr[p] <= 13))
		p++;
	if (nptr[p] == '-' || nptr[p] == '+')
	{
		if (nptr[p] == '-')
			sign = -sign;
		p++;
	}
	while (nptr[p] >= '0' && nptr[p] <= '9')
	{
		num = num * 10 + (nptr[p] - '0');
		p++;
	}
	return (num * sign);
}
