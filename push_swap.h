/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:57 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 18:14:11 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define N_AB 2
# define N_FUNC 4

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NONE,
}				t_op;

typedef enum e_ab
{
	A = 0,
	B = 1,
}				t_ab;

typedef enum e_op_ab
{
	SWAP = 0,
	PUSH = 1,
	ROTATE = 2,
	REV_ROTATE = 3,
}				t_op_ab;

typedef t_op	(*t_opfunc)(t_twlist **, t_twlist **);

void			push_swap(int *arr, int n);
t_op			sa(t_twlist **a, t_twlist **b);
t_op			sb(t_twlist **a, t_twlist **b);
t_op			ss(t_twlist **a, t_twlist **b);
t_op			ra(t_twlist **a, t_twlist **b);
t_op			rb(t_twlist **a, t_twlist **b);
t_op			rr(t_twlist **a, t_twlist **b);
t_op			pa(t_twlist **a, t_twlist **b);
t_op			pb(t_twlist **a, t_twlist **b);
t_op			rra(t_twlist **a, t_twlist **b);
t_op			rrb(t_twlist **a, t_twlist **b);
t_op			rrr(t_twlist **a, t_twlist **b);

t_list			*solve(int *arr, int n);

t_list			*solve_2(t_twlist **a, t_twlist **b);
t_list			*solve_3(t_twlist **a, t_twlist **b);
t_list			*solve_4(t_twlist **a, t_twlist **b);
t_list			*solve_5(t_twlist **a, t_twlist **b);
t_list			*solve_6(t_twlist **a, t_twlist **b);

void			print_ops(t_list *ops);

void			init_stacks(t_twlist **stacks[], t_twlist **a, t_twlist **b);

void			optimize(t_list *ops);
void			opsadd(t_list **ops, int argn, ...);

t_list			*sort_2(t_twlist **a, t_twlist **b, t_ab ab);
t_list			*sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min);
t_list			*rev_sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min);

void			create_stacks(t_twlist **a, t_twlist **b, int *arr, int n);
int				value(t_twlist *lst);
void			free_stacks(t_twlist *a, t_twlist *b);

int				*parse_mono_arg(char **arg);
int				*parse_mul_arg(char **arg);
t_list			*pipeop(t_twlist **a, t_twlist **b, int argn, ...);

void			lstadd(t_list **lst, t_list *new);
void			lstadd_front(t_list **lst, t_list *new);
t_list			*lstlast(t_list *lst);
size_t			lstsize(t_list *lst);

void			twlstadd(t_twlist **lst, t_twlist *new);
void			twlstadd_front(t_twlist **lst, t_twlist *new);
t_twlist		*twlstlast(t_twlist *lst);
size_t			twlstsize(t_twlist *lst);
t_twlist		*twlsthead(t_twlist *lst);
int				issorted(t_twlist *lst, int reversed);
t_twlist		*get(t_twlist *lst, int index);
int				median(t_twlist *lst);

int				twlst_any(t_twlist *lst, int start, int end);
t_twlist		*get(t_twlist *lst, int index);

t_list			*golgo_invitation_sort(t_twlist **a, t_twlist **b, int n);
int				nextnbr(t_twlist *a);
int				calc_pivot(t_twlist *a, int n);
int				check_buff(t_twlist *lst, int start, int end, int n);
int				check(t_twlist *a, t_twlist *b);

#endif