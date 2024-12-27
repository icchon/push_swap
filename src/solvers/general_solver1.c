/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:40 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 18:22:22 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	invite(t_twlist **a, t_twlist **b, t_list **ops)
{
	int				next;
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};
	int				i;

	while (check(*a, *b))
	{
		next = nextnbr(*a);
		i = 10;
		while (i >= 2)
			if (value(get(*a, i--)) == next)
				lstadd(ops, pipeop(a, b, 1, f[B][PUSH]));
		if (value(get(*a, 1)) == next)
			lstadd(ops, pipeop(a, b, 1, f[A][SWAP]));
		if (value(get(*a, 0)) == next)
			lstadd(ops, pipeop(a, b, 1, f[A][ROTATE]));
		next = nextnbr(*a);
		i = -3;
		while (i <= -1)
			if (value(get(*b, i++)) == next)
				lstadd(ops, pipeop(a, b, 1, f[B][REV_ROTATE]));
		if (value(get(*b, 0)) == next)
			lstadd(ops, pipeop(a, b, 2, f[A][PUSH], f[A][ROTATE]));
	}
	return ;
}

static void	split_first(t_twlist **a, t_twlist **b, int pivot, t_list **ops)
{
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};

	while (twlst_any(*a, 0, pivot - 1) && !(issorted(*a, 0)
			&& (twlstsize(*b) == 0)))
	{
		if (value(*a) < pivot)
		{
			lstadd(ops, pipeop(a, b, 1, f[B][PUSH]));
		}
		else
		{
			lstadd(ops, pipeop(a, b, 1, f[A][ROTATE]));
		}
	}
	return ;
}

static void	binary_send(t_twlist **a, t_twlist **b, int n, t_list **ops)
{
	int				pivot;
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};

	pivot = median(*b);
	while (twlstsize(*b) > 0)
	{
		while (twlst_any(*b, pivot, n) || (check(*a, *b)))
		{
			invite(a, b, ops);
			if (value(*b) < pivot)
				lstadd(ops, pipeop(a, b, 1, f[B][ROTATE]));
			else
				lstadd(ops, pipeop(a, b, 1, f[A][PUSH]));
		}
		pivot = (nextnbr(*a) + pivot - 1) / 2;
	}
	return ;
}

static void	store_buff(t_twlist **a, t_twlist **b, int n, t_list **ops)
{
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};

	while (!check_buff(*b, nextnbr(*a), nextnbr(*a) + 12, n) && !(issorted(*a,
				0) && (twlstsize(*b) == 0)))
	{
		lstadd(ops, pipeop(a, b, 1, f[B][PUSH]));
	}
	return ;
}

t_list	*golgo_invitation_sort(t_twlist **a, t_twlist **b, int n)
{
	t_list	*ops;

	ops = NULL;
	split_first(a, b, (2 * n) / 3, &ops);
	while (!(issorted(*a, 0) && (twlstsize(*b) == 0)))
	{
		binary_send(a, b, n, &ops);
		store_buff(a, b, n, &ops);
	}
	return (ops);
}
