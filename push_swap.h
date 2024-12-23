/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:57 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 01:12:05 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

t_list	*push_swap(int *arr, int n);
t_op	*exec_sa(t_twlist **a, t_twlist **b);
t_op	*exec_sb(t_twlist **a, t_twlist **b);
t_op	*exec_ss(t_twlist **a, t_twlist **b);
t_op	*exec_ra(t_twlist **a, t_twlist **b);
t_op	*exec_rb(t_twlist **a, t_twlist **b);
t_op	*exec_rr(t_twlist **a, t_twlist **b);
t_op	*exec_pa(t_twlist **a, t_twlist **b);
t_op	*exec_pb(t_twlist **a, t_twlist **b);
t_op	*exec_rra(t_twlist **a, t_twlist **b);
t_op	*exec_rrb(t_twlist **a, t_twlist **b);
t_op	*exec_rrr(t_twlist **a, t_twlist **b);

#endif