/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:41:00 by andrew            #+#    #+#             */
/*   Updated: 2021/11/11 11:09:01 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_ra(t_pile *p)
{
	t_liste	*tmp;
	t_liste	*first;

	if (p->a && p->a->next)
	{
		tmp = p->a;
		p->a = p->a->next;
		first = p->a;
		while (p->a->next)
			p->a = p->a->next;
		p->a->next = tmp;
		p->a = first;
	}
}
