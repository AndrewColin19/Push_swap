/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:51:00 by acolin            #+#    #+#             */
/*   Updated: 2021/11/22 15:39:50 by acolin           ###   ########.fr       */
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
	int		nchunk;
	int		limit;
	int		max;
}	t_pile;

int		sizetab(char **tab);
int		check_arg(int size, char **arv);
t_liste	*ft_parse_arg(char **tab, int size);
void	ft_aff_move(int move);
void	lstclear(t_liste **lst);
t_liste	*ft_replace_nb(t_pile *p);
void	lstadd_back(t_liste **alst, t_liste *new);
t_liste	*newlst(int value);
t_liste	*lstlast(t_liste *lst);
/*sort*/
void	ft_use_rot_a(t_pile *p, int index);
void	ft_use_rot_b(t_pile *p, int index);
void	ft_rotate_inf_b(t_pile *p, int value);
int		min(t_liste *l);
int		max(t_liste *l);
int		ft_get_index(t_liste *l, int val);
void	ft_use_w(t_pile *p, int index);
int		ft_issort(t_pile *p);
void	ft_sort(t_pile *p);
void	ft_use(int move, t_pile *p);
void	ft_small_sort(t_pile *p);
void	ft_big_sort(t_pile *p);
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