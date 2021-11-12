/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:18:52 by andrew            #+#    #+#             */
/*   Updated: 2021/11/11 11:19:51 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_issort(t_pile *p)
{
	t_liste	*lst;

	if (p->size_a < 2)
		return (1);
	lst = p->a;
	while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_sort(t_pile *p)
{
	if (!ft_issort(p))
	{
		printf("passe\n");
		if (p->size_a <= 5)
			ft_small_sort(p);
		/*else
			ft_big_sort();*/
	}
}
