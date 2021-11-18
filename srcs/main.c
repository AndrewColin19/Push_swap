/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:48:18 by acolin            #+#    #+#             */
/*   Updated: 2021/11/18 14:40:01 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void	print_pile(t_pile *p)
{
	t_liste	*lst;
	int		i;

	lst = p->a;
	i = 0;
	while (lst)
	{
		printf("%i\n", lst->content);
		lst = lst->next;
		i++;
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
		ft_sort(&pile);
		lstclear(&pile.a);
	}
	else
		ft_putendl_fd("usage : ./push_swap <num 1> <num 2> <...>", 1);
}
