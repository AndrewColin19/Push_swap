/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:50:46 by andrew            #+#    #+#             */
/*   Updated: 2021/11/11 00:52:58 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_rra(t_pile *p)
{
	t_liste	*first;
	t_liste	*tmp;

	if (p->a && p->a->next)
	{
		first = p->a;
		while (p->a->next->next)
			p->a = p->a->next;
		tmp = p->a->next;
		p->a->next = NULL;
		p->a = first;
		tmp->next = p->a;
		p->a = tmp;
	}
}
