/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:24:48 by andrew            #+#    #+#             */
/*   Updated: 2021/11/16 23:37:48 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void use_duo(int move, int move2, t_pile *p)
{
	ft_use(move, p);
	ft_use(move2, p);
}

static void	simple_sort(t_pile *p)
{
	int a[3];

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

static void set_pile_sort(t_pile *p)
{
	if (p->size_a == 4)
		ft_use(PB, p);
	else
		use_duo(PB, PB, p);
	simple_sort(p);
}

static void	complex_sort(t_pile *p)
{
	set_pile_sort(p);
	while (p->b)
	{
		if (p->b->content > max(p->a))
			use_duo(PA, RA, p);
		else if (p->b->content < min(p->a))
		{
			if (p->b->content != max(p->b) && max(p->b) < p->a->content)
				use_duo(RB, PA, p);
			else if (max(p->b) > p->b->content)
			{
				use_duo(RB, PA, p);
				ft_use(SA, p);
			}
			else
				ft_use(PA, p);
		}
		else
			use_duo(PA, SA, p);
	}
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