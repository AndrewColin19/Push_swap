/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:42:08 by andrew            #+#    #+#             */
/*   Updated: 2021/11/25 17:55:29 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_liste	*lstlast(t_liste *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_liste	*newlst(int value)
{
	t_liste	*lst;

	lst = malloc(sizeof(t_liste));
	lst->content = value;
	lst->next = NULL;
	return (lst);
}

void	lstadd_back(t_liste **alst, t_liste *new)
{
	t_liste	*lst;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	lst = lstlast(*(alst));
	lst->next = new;
}

t_liste	*ft_parse_arg(char **tab, int size, int argc)
{
	t_liste	*start;
	int		i;

	i = 0;
	start = newlst(ft_atoi(tab[i]));
	i++;
	while (i < size)
	{
		lstadd_back(&start, newlst(ft_atoi(tab[i])));
		i++;
	}
	ft_free_tab(tab, argc);
	return (start);
}
