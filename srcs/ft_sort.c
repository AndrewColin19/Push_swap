/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:18:52 by andrew            #+#    #+#             */
/*   Updated: 2021/11/18 16:41:31 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	min(t_liste *l)
{
	t_liste	*lst;
	int		min;

	lst = l;
	min = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		if (min > lst->content)
			min = lst->content;
	}
	return (min);
}

int	max(t_liste *l)
{
	t_liste	*lst;
	int		max;

	lst = l;
	max = lst->content;
	while (lst->next)
	{
		lst = lst->next;
		if (max < lst->content)
			max = lst->content;
	}
	return (max);
}

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

int	ft_get_index(t_liste *l, int val)
{
	t_liste	*lst;
	int		i;

	i = 0;
	lst = l;
	while (lst)
	{
		if (lst->content == val)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

void	ft_sort(t_pile *p)
{
	if (!ft_issort(p))
	{
		if (p->size_a <= 5)
			ft_small_sort(p);
		else
			ft_big_sort(p);
	}
}
