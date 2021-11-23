/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:13:17 by acolin            #+#    #+#             */
/*   Updated: 2021/11/23 13:06:30 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	scan_up(t_pile *p, int limit)
{
	int		mi;
	int		index;
	t_liste	*lst;

	mi = limit - p->limit;
	index = 0;
	lst = p->a;
	while (lst)
	{
		if (lst->content > mi && lst->content <= limit)
			return (index);
		index++;
		lst = lst->next;
	}
	return (index);
}

int	scan_down(t_pile *p, int limit)
{
	int		mi;
	int		index;
	int		index_save;
	t_liste	*lst;

	mi = limit - p->limit;
	index = 0;
	index_save = 0;
	lst = p->a;
	while (lst)
	{
		if (lst->content > mi && lst->content <= limit)
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
		ft_rotate_inf_b(p, p->a->content);
		ft_use(PB, p);
	}
}

void	get_chunck(t_pile *p, int nb_chunk)
{
	int		size_chunk;
	int		index_d;
	int		index_u;
	int		limit;

	size_chunk = 0;
	limit = (p->limit * nb_chunk);
	while (size_chunk < p->limit && p->size_a != 0)
	{
		index_d = scan_down(p, limit);
		index_u = scan_up(p, limit);
		if (index_u == index_d)
			ft_use_rot_a(p, index_u);
		else if ((p->max - 1) - index_d < index_u)
			ft_use_rot_a(p, index_d);
		else
			ft_use_rot_a(p, index_u);
		check_pile_b(p);
		size_chunk++;
	}
}

void	ft_big_sort(t_pile *p)
{
	int		nb_chunk;

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
