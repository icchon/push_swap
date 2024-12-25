/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:57 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 16:15:09 by kaisobe          ###   ########.fr       */
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
}		t_op;

typedef enum e_ab
{
	A = 0,
	B = 1,
}		t_ab;

typedef enum e_op_ab
{
	SWAP = 0,
	PUSH = 1,
	ROTATE = 2,
	REV_ROTATE = 3,
}		t_op_ab;

void	push_swap(int *arr, int n);
t_op	sa(t_twlist **a, t_twlist **b);
t_op	sb(t_twlist **a, t_twlist **b);
t_op	ss(t_twlist **a, t_twlist **b);
t_op	ra(t_twlist **a, t_twlist **b);
t_op	rb(t_twlist **a, t_twlist **b);
t_op	rr(t_twlist **a, t_twlist **b);
t_op	pa(t_twlist **a, t_twlist **b);
t_op	pb(t_twlist **a, t_twlist **b);
t_op	rra(t_twlist **a, t_twlist **b);
t_op	rrb(t_twlist **a, t_twlist **b);
t_op	rrr(t_twlist **a, t_twlist **b);

t_list	*solve(int *arr, int n);
t_list	*solve_general(t_twlist **a, t_twlist **b);

t_list	*solve_2(t_twlist **a, t_twlist **b);
t_list	*solve_3(t_twlist **a, t_twlist **b);
t_list	*solve_4(t_twlist **a, t_twlist **b);
t_list	*solve_5(t_twlist **a, t_twlist **b);
t_list	*solve_6(t_twlist **a, t_twlist **b);

void	print_op(t_op op);
void	print_ops(t_list *ops);
void	print_twlst(t_twlist *lst);
void	print_stacks(t_twlist *a, t_twlist *b);

void	init_fs(t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b),
			t_twlist **stacks[], t_twlist **a, t_twlist **b);
void	init_f(t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b));
void	init_stacks(t_twlist **stacks[], t_twlist **a, t_twlist **b);

void	add_ops(t_list **ops, int argn, ...);
void	optimize(t_list *ops);

t_list	*sort_2(t_twlist **a, t_twlist **b, t_ab ab);
t_list	*sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min);
t_list	*rev_sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min);
void	create_stacks(t_twlist **a, t_twlist **b, int *arr, int n);
int		get_val(t_twlist *lst);
void	free_stacks(t_twlist *a, t_twlist *b);

#endif