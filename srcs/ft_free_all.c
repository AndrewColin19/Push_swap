/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:20:15 by acolin            #+#    #+#             */
/*   Updated: 2021/11/25 17:53:22 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_liste *ft_free_tab(char **tab, int size)
{
	int	i;

	if (size < 2)
	{
		i = 0;
		while (tab[i] != '\0')
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

void	lstclear(t_liste **lst)
{
	t_liste	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			free(*lst);
			(*lst) = next;
		}
		*lst = NULL;
	}
}
