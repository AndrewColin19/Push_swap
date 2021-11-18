/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:03:02 by acolin            #+#    #+#             */
/*   Updated: 2021/11/18 17:05:24 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
