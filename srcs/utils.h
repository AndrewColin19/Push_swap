/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:51:00 by acolin            #+#    #+#             */
/*   Updated: 2021/11/16 13:25:28 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include <stdio.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_liste
{
	int				content;
	struct s_liste	*next;
}	t_liste;

typedef struct s_pile
{
	t_liste	*a;
	int		size_a;
	t_liste	*b;
	int		size_b;
}	t_pile;

int		sizetab(char **tab);
int		check_arg(int size, char **arv);
t_liste	*ft_parse_arg(char **tab, int size);
void	ft_aff_move(int move);
/*sort*/
int		min(t_liste *l);
int		max(t_liste *l);
int		ft_issort(t_pile *p);
void	ft_sort(t_pile *p);
void	ft_use(int move, t_pile *p);
void	ft_small_sort(t_pile *p);
/*fct tri*/
void	ft_sa(t_pile *p);
void	ft_sb(t_pile *p);
void	ft_ss(t_pile *p);
void	ft_pa(t_pile *p);
void	ft_pb(t_pile *p);
void	ft_ra(t_pile *p);
void	ft_rb(t_pile *p);
void	ft_rr(t_pile *p);
void	ft_rra(t_pile *p);
void	ft_rrb(t_pile *p);
void	ft_rrr(t_pile *p);

#endif