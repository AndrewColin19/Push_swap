/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:24:48 by andrew            #+#    #+#             */
/*   Updated: 2021/11/23 14:35:05 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	rot_a(t_pile *p, int index)
{
	if (index <= p->size_a / 2)
	{
		while (index)
		{
			ft_use(RA, p);
			index--;
		}
	}
	else
	{
		while (index < p->size_a)
		{
			ft_use(RRA, p);
			index++;
		}
	}
}

static int	sup_of(t_pile *p, int value)
{
	t_liste	*lst;

	lst = p->a;
	while (lst)
	{
		if (lst->content == value + 1)
			return (ft_get_index(p->a, lst->content));
		lst = lst->next;
	}
	lst = p->a;
	while (lst)
	{
		if (lst->content == value + 2)
			return (ft_get_index(p->a, lst->content));
		lst = lst->next;
	}
	return (-1);
}

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

	while (p->size_a > 3)
		ft_use(PB, p);
	simple_sort(p);
	while (p->size_b > 0)
	{
		index = sup_of(p, p->b->content);
		if (index == -1)
			rot_a(p, ft_get_index(p->a, min(p->a)));
		else
			rot_a(p, index);
		ft_use(PA, p);
	}
	rot_a(p, ft_get_index(p->a, min(p->a)));
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
