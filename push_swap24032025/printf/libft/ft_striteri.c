/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:13:52 by linyao            #+#    #+#             */
/*   Updated: 2025/03/24 15:31:01 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	p;

	p = 0;
	if (!s || !f)
		return ;
	while (s[p] != '\0')
	{
		f(p, &s[p]);
		p++;
	}
	s[p] = '\0';
}

/*void	f(unsigned int n, char *s)
{
	*s = *s - 32;
}

int	main()
{
	char a[] = "hola";
	ft_striteri(a, f);
	printf("%s", a);
	return (0);
}*/
