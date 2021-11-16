/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:44:19 by andrew            #+#    #+#             */
/*   Updated: 2021/11/16 22:28:13 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_rb(t_pile *p)
{
	t_liste	*tmp;
	t_liste	*first;

	if (p->b && p->b->next)
	{
		tmp = p->b;
		p->b = p->b->next;
		first = p->b;
		while (p->b->next)
			p->b = p->b->next;
		p->b->next = tmp;
		tmp->next = NULL;
		p->b = first;
	}
}
