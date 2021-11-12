/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:52:19 by andrew            #+#    #+#             */
/*   Updated: 2021/11/11 00:53:02 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_rrb(t_pile *p)
{
	t_liste	*first;
	t_liste	*tmp;

	if (p->b && p->b->next)
	{
		first = p->b;
		while (p->b->next->next)
			p->b = p->b->next;
		tmp = p->b->next;
		p->b->next = NULL;
		p->b = first;
		tmp->next = p->b;
		p->b = tmp;
	}
}
