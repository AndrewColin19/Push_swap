/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:44:55 by acolin            #+#    #+#             */
/*   Updated: 2021/11/24 12:57:23 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	sizetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	check_isnum(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (ft_strlen(arg) > 9 && ft_atoi(arg) == -1)
		return (0);
	return (1);
}

int	check_arg(int size, char **arv)
{
	int		i;
	int		j;
	char	*arg;

	i = 0;
	while (i < size)
	{
		if (check_isnum(arv[i]))
		{
			arg = arv[i];
			j = 0;
			while (j < size)
			{
				if (ft_strcmp(arg, arv[j]) == 0 && j != i)
					return (0);
				j++;
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}
