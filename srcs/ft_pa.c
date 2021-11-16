/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:36:52 by andrew            #+#    #+#             */
/*   Updated: 2021/11/10 20:18:15 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_pa(t_pile *p)
{
	t_liste	*tmp;

	if (p->b)
	{
		tmp = p->b->next;
		p->b->next = p->a;
		p->a = p->b;
		p->b = tmp;
	}
}