/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:13:17 by acolin            #+#    #+#             */
/*   Updated: 2021/11/17 15:24:52 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_use_w(t_pile *p, int index)
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

void	ft_big_sort(t_pile *p)
{
	t_liste	*lst;
	int		index;

	lst = p->a;
	while (p->size_a != 0)
	{
		index = ft_get_index(p, min(p->a));
		if (index > 0)
			ft_use_w(p, index);
		ft_use(PB, p);	
	}
	while (p->size_b != 0)
		ft_use(PA, p);	
}
