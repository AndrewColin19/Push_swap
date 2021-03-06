/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:32:39 by andrew            #+#    #+#             */
/*   Updated: 2021/11/11 00:53:14 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_sb(t_pile *p)
{
	t_liste	*tmp;

	if (p->b && p->b->next)
	{
		tmp = p->b->next;
		p->b->next = p->b->next->next;
		tmp->next = p->b;
		p->b = tmp;
	}
}
