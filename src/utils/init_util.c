/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:00:05 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 10:21:51 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_f(t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b))
{
	f[A][SWAP] = sa;
	f[A][PUSH] = pa;
	f[A][ROTATE] = ra;
	f[A][REV_ROTATE] = rra;
	f[B][SWAP] = sb;
	f[B][PUSH] = pb;
	f[B][ROTATE] = rb;
	f[B][REV_ROTATE] = rrb;
	return ;
}

void	init_stacks(t_twlist **stacks[], t_twlist **a, t_twlist **b)
{
	stacks[A] = a;
	stacks[B] = b;
	return ;
}

void	init_fs(t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b),
		t_twlist **stacks[], t_twlist **a, t_twlist **b)
{
	init_f(f);
	init_stacks(stacks, a, b);
	return ;
}
