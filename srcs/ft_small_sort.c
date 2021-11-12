/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:24:48 by andrew            #+#    #+#             */
/*   Updated: 2021/11/11 11:31:15 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	simple_sort(t_pile *p)
{
	int a[3];

	a[0] = p->a->content;
	a[1] = p->a->next->content;
	a[2] = p->a->next->next->content;
	if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		ft_use(SA, p);
	else if (a[0] < a[1] && a[1] < a[2] && a[2] > a[0])
	{
		ft_use(SA, p);
		ft_use(RRA, p);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		ft_use(RA, p);
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		ft_use(SA, p);
		ft_use(RA, p);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
		ft_use(RRA, p);
}

void	ft_small_sort(t_pile *p)
{
	if (p->size_a == 2)
		ft_use(SA, p);
	else if (p->size_a == 3)
		simple_sort(p);
	else
		return ;
}