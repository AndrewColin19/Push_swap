/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:24:48 by andrew            #+#    #+#             */
/*   Updated: 2021/11/18 16:42:08 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	simple_sort(t_pile *p)
{
	int	a[3];

	a[0] = p->a->content;
	a[1] = p->a->next->content;
	a[2] = p->a->next->next->content;
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		ft_use(SA, p);
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		ft_use(SA, p);
		ft_use(RRA, p);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		ft_use(RA, p);
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		ft_use(SA, p);
		ft_use(RA, p);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		ft_use(RRA, p);
}

static void	complex_sort(t_pile *p)
{
	int	index;
	int	i;
	int	t;

	if (p->size_a == 4)
		i = 1;
	else
		i = 0;
	t = i;
	while (i < 2)
	{
		index = ft_get_index(p->a, min(p->a));
		ft_use_rot_a(p, index);
		if (ft_issort(p))
			return ;
		ft_use(PB, p);
		i++;
	}
	simple_sort(p);
	ft_use(PA, p);
	if (t == 0)
		ft_use(PA, p);
}

void	ft_small_sort(t_pile *p)
{
	if (p->size_a == 2)
		ft_use(SA, p);
	else if (p->size_a == 3)
		simple_sort(p);
	else
		complex_sort(p);
}
