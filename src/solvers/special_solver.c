/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:40 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 13:07:16 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*solve_2(t_twlist **a, t_twlist **b)
{
	t_list	*ops;

	ops = NULL;
	lstadd(&ops, sort_2(a, b, A));
	return (ops);
}

t_list	*solve_3(t_twlist **a, t_twlist **b)
{
	t_list	*ops;

	ops = NULL;
	lstadd(&ops, sort_3(a, b, A, 0));
	return (ops);
}

t_list	*solve_4(t_twlist **a, t_twlist **b)
{
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};
	t_list			*ops;

	ops = NULL;
	while (value(*a) != 0)
	{
		lstadd(&ops, pipeop(a, b, 1, f[A][ROTATE]));
	}
	lstadd(&ops, pipeop(a, b, 1, f[B][PUSH]));
	lstadd(&ops, sort_3(a, b, A, 1));
	lstadd(&ops, pipeop(a, b, 1, f[A][PUSH]));
	return (ops);
}

t_list	*solve_5(t_twlist **a, t_twlist **b)
{
	t_list			*ops;
	int				i;
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};

	ops = NULL;
	i = 0;
	while (i < 2)
	{
		while (!(ft_ismatch(value(*a), 2, 0, 1)))
			lstadd(&ops, pipeop(a, b, 1, f[A][ROTATE]));
		lstadd(&ops, pipeop(a, b, 1, f[B][PUSH]));
		i++;
	}
	lstadd(&ops, sort_3(a, b, A, 2));
	if (issorted(*b, 0))
		lstadd(&ops, pipeop(a, b, 1, f[B][SWAP]));
	lstadd(&ops, pipeop(a, b, 2, f[A][PUSH], f[A][PUSH]));
	return (ops);
}

t_list	*solve_6(t_twlist **a, t_twlist **b)
{
	int				i;
	t_list			*ops;
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};
	int				next;

	ops = NULL;
	i = 0;
	next = 2;
	while (i++ < 3)
	{
		while (!(ft_ismatch(value(*a), 3, 0, 1, 2)))
			lstadd(&ops, pipeop(a, b, 1, f[A][ROTATE]));
		lstadd(&ops, pipeop(a, b, 1, f[B][PUSH]));
	}
	lstadd(&ops, sort_3(a, b, A, 3));
	while (twlstsize(*b) > 0)
	{
		while (value(get(*b, 0)) == next)
			lstadd((next--, &ops), pipeop(a, b, 1, f[A][PUSH]));
		if (value(get(*b, -1)) == next)
			lstadd(&ops, pipeop(a, b, 1, f[B][REV_ROTATE]));
		if (value(get(*b, 1)) == next)
			lstadd(&ops, pipeop(a, b, 1, f[B][SWAP]));
	}
	return (ops);
}
