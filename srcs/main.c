/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:48:18 by acolin            #+#    #+#             */
/*   Updated: 2021/11/24 13:32:05 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_nb_chunk(t_pile *p)
{	
	if (p->size_a <= 100)
		p->nchunk = 5;
	else if (p->size_a >= 100 && p->size_a <= 500)
		p->nchunk = 12;
	else
		p->nchunk = p->size_a / 15;
	p->limit = p->size_a / p->nchunk;
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

t_liste	*start(t_pile *p, int argc, char *argv[])
{
	char	**tab;
	int		size;

	if (argc > 2)
	{
		tab = ++argv;
		size = argc - 1;
	}
	else
	{
		tab = ft_split(argv[1], ' ');
		size = sizetab(tab);
	}
	if (!check_arg(size, tab))
		return (0);
	p->size_a = size;
	p->size_b = 0;
	p->max = size;
	return (ft_parse_arg(tab, size));
}

int	main(int argc, char *argv[])
{
	t_pile	pile;

	if (argc >= 2)
	{
		pile.a = start(&pile, argc, argv);
		if (pile.a == NULL)
		{
			ft_putendl_fd("Error", 1);
			return (0);
		}
		pile.a = ft_replace_nb(&pile);
		set_nb_chunk(&pile);
		ft_sort(&pile);
		lstclear(&pile.a);
	}
}
