/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:48:34 by acolin            #+#    #+#             */
/*   Updated: 2021/11/24 12:55:16 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_get_index_min(int *tab, int size)
{
	int	index;
	int	index_save;
	int	min;

	index = 0;
	index_save = 0;
	min = tab[0];
	while (index < size)
	{
		if (min > tab[index])
		{
			min = tab[index];
			index_save = index;
		}
		index++;
	}
	return (index_save);
}

int	ft_is_all_max(int *tab, int size, int max)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (max != tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	*ft_nb_in_tab(t_pile *p)
{
	int		*tab;
	int		i;
	t_liste	*lst;

	tab = ft_calloc(sizeof(int), p->size_a);
	i = 0;
	lst = p->a;
	while (i < p->size_a)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
	return (tab);
}

int	*ft_tab_replace(t_pile *p, int *tab)
{
	int	*lst;
	int	m;
	int	i;
	int	i_max;
	int	num;

	lst = ft_calloc(sizeof(int), p->size_a);
	num = 1;
	m = max(p->a);
	i_max = ft_get_index(p->a, m);
	while (num <= p->size_a)
	{
		i = ft_get_index_min(tab, p->size_a);
		if (ft_is_all_max(tab, p->size_a, m))
			lst[i_max] = num;
		else
			lst[i] = num;
		tab[i] = m;
		num++;
	}
	free(tab);
	return (lst);
}

t_liste	*ft_replace_nb(t_pile *p)
{
	t_liste	*start;
	int		i;
	int		*tab;

	tab = ft_tab_replace(p, ft_nb_in_tab(p));
	i = 0;
	lstclear(&p->a);
	start = newlst(tab[i]);
	i++;
	while (i < p->size_a)
	{
		lstadd_back(&start, newlst(tab[i]));
		i++;
	}
	free(tab);
	return (start);
}
