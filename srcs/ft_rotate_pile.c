/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:03:02 by acolin            #+#    #+#             */
/*   Updated: 2021/11/22 15:56:08 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_rotate_inf_b(t_pile *p, int value)
{
	int		inf;
	int		diff;
	int		val;
	t_liste	*lst;

	lst = p->b;
	val = 0;
	inf = 0;
	while (lst)
	{
		diff = lst->content - value;
		if (diff < 0)
		{
			if (diff > inf || inf == 0)
			{
				inf = diff;
				val = lst->content;
			}
		}
		lst = lst->next;
	}
	if (val == 0)
		ft_use_rot_b(p, ft_get_index(p->b, max(p->b)));
	else
		ft_use_rot_b(p, ft_get_index(p->b, val));
}

void	ft_use_rot_a(t_pile *p, int index)
{
	if (index == 1)
	{
		ft_use(SA, p);
		return ;
	}
	if (index < p->size_a / 2)
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

void	ft_use_rot_b(t_pile *p, int index)
{
	if (index < p->size_b / 2)
	{
		while (index)
		{
			ft_use(RB, p);
			index--;
		}
	}
	else
	{
		while (index < p->size_b)
		{
			ft_use(RRB, p);
			index++;
		}
	}
}
