/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:27:12 by andrew            #+#    #+#             */
/*   Updated: 2021/11/16 13:11:49 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_aff_move(int move)
{
	if (move == SA)
		ft_putendl_fd("sa", 1);
	else if (move == SB)
		ft_putendl_fd("sb", 1);
	else if (move == SS)
		ft_putendl_fd("ss", 1);
	else if (move == PA)
		ft_putendl_fd("pa", 1);
	else if (move == PB)
		ft_putendl_fd("pb", 1);
	else if (move == RA)
		ft_putendl_fd("ra", 1);
	else if (move == RB)
		ft_putendl_fd("rb", 1);
	else if (move == RR)
		ft_putendl_fd("rr", 1);
	else if (move == RRA)
		ft_putendl_fd("rra", 1);
	else if (move == RRB)
		ft_putendl_fd("rrb", 1);
	else if (move == RRR)
		ft_putendl_fd("rrr", 1);
}

void	ft_move_one(int move, t_pile *p)
{
	if (move == SA)
	{
		ft_sa(p);
		ft_aff_move(SA);
	}
	else if (move == SB)
	{
		ft_sb(p);
		ft_aff_move(SB);
	}
	else if (move == SS)
	{
		ft_ss(p);
		ft_aff_move(SS);	
	}
	else if (move == PA)
	{
		ft_pa(p);
		ft_aff_move(PA);
	}
}

void	ft_move_two(int move, t_pile *p)
{
	if (move == PB)
	{
		ft_pb(p);
		ft_aff_move(PB);
	}
	else if (move == RA)
	{
		ft_ra(p);
		ft_aff_move(RA);
	}
	else if (move == RB)
	{
		ft_rb(p);
		ft_aff_move(RB);	
	}
	else if (move == RR)
	{
		ft_rr(p);
		ft_aff_move(RR);
	}
}

void	ft_move_three(int move, t_pile *p)
{
	if (move == RRA)
	{
		ft_rra(p);
		ft_aff_move(RRA);
	}
	else if (move == RRB)
	{
		ft_rrb(p);
		ft_aff_move(RRB);
	}
	else if (move == RRR)
	{
		ft_rrr(p);
		ft_aff_move(RRR);	
	}
}

void	ft_use(int move, t_pile *p)
{
	if (move <= 4)
		ft_move_one(move, p);
	else if (move >= 5 && move < 9)
		ft_move_two(move, p);
	else
		ft_move_three(move, p);
}
