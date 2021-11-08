/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:48:18 by acolin            #+#    #+#             */
/*   Updated: 2021/11/08 13:45:17 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char *argv[])
{
	char	**tab;
	int		size;
	if (argc >= 2)
	{
		if (argc > 2)
		{
			tab = argv;
			size = argc;
		}
		else
		{
			tab = ft_split(argv[1], ' ');
			size = sizetab(tab);
		}
		if (check_arg(size, tab))
			ft_putendl_fd("ok", 1);
		else
			ft_putendl_fd("nop", 1);
	}
	else
		ft_putendl_fd("usage : ./push_swap <arg 1> <arg 2> ...", 1);
}