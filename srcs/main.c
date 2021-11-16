/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:48:18 by acolin            #+#    #+#             */
/*   Updated: 2021/11/16 23:51:05 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void print_pile(t_pile *p)
{
	t_liste *lst;
	int i;

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
		ft_sort(&pile);
		print_pile(&pile);
	}
	else
		ft_putendl_fd("usage : ./push_swap <num 1> <num 2> <...>", 1);
}
