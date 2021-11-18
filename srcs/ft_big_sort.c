/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:13:17 by acolin            #+#    #+#             */
/*   Updated: 2021/11/18 17:38:59 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int scan_up(t_pile *p, int limit)
{
	int		mi;
	int		index;
	t_liste	*lst;

	mi = min(p->a);
	index = 0;
	lst = p->a;
	while (lst)
	{
		if (lst->content >= mi && lst->content <= limit)
			return (index);
		index++;
		lst = lst->next;
	}
	return (index);
}

int scan_down(t_pile *p, int limit)
{
	int		mi;
	int		index;
	int		index_save;
	t_liste	*lst;

	mi = min(p->a);
	index = 0;
	index_save = 0;
	lst = p->a;
	while (lst)
	{
		if (lst->content >= mi && lst->content <= limit)
			index_save = index;
		index++;
		lst = lst->next;
	}
	return (index_save);
}

void	check_pile_b(t_pile *p)
{
	if (p->size_b == 0)
		ft_use(PB, p);
	else if (p->size_b == 1)
	{
		ft_use(PB, p);
		if (p->b->content < p->b->next->content)
			ft_use(SB, p);
	}
	else
	{
		if (p->a->content > max(p->b))
			ft_use_rot_b(p, ft_get_index(p->b, min(p->b)));
		else if (p->a->content < min(p->b))
			ft_use_rot_b(p, ft_get_index(p->b, max(p->b)));
		ft_use(PB, p);
	}
}

void	get_chunck(t_pile *p, int nb_chunk)
{
	int		size_chunk;
	int		index_d;
	int		index_u;
	int		limit;
	t_liste	*lst;

	size_chunk = 0;
	limit = (20 * nb_chunk);
	lst = p->a;
	while (size_chunk < 21 && p->size_a != 0)
	{
		index_d = scan_down(p, limit);
		index_u = scan_up(p, limit);
		if ((p->size_a - index_d - 1) < index_u)
			ft_use_rot_a(p, index_d);
		else if (index_u > (p->size_a - index_d - 1))
			ft_use_rot_a(p, index_u);
		check_pile_b(p);
	}
}

void	ft_big_sort(t_pile *p)
{
	t_liste	*lst;
	int		nb_chunk;

	lst = p->a;
	nb_chunk = 1;
	while (p->size_a != 0)
	{
		get_chunck(p, nb_chunk);
		nb_chunk++;
	}
	while (p->size_b != 0)
	{
		ft_use_rot_b(p, ft_get_index(p->b, max(p->b)));
		ft_use(PA, p);
	}
		
}
