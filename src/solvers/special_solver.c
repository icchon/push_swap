/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:40 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 12:24:23 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*solve_2(t_twlist **a, t_twlist **b)
{
	t_list	*ops;

	ops = NULL;
	print_stacks(*a, *b);
	ft_lstadd_back(&ops, sort_2(a, b, A));
	print_stacks(*a, *b);
	return (ops);
}

t_list	*solve_3(t_twlist **a, t_twlist **b)
{
	t_list	*ops;

	ops = NULL;
	ft_lstadd_back(&ops, sort_3(a, b, A, 0));
	return (ops);
}

t_list	*solve_4(t_twlist **a, t_twlist **b)
{
	t_list	*ops;
	t_list	*d;
	t_op	(*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b);

	init_f(f);
	ops = NULL;
	while (get_val(*a) != 0)
	{
		add_ops(&ops, 1, f[A][ROTATE](a, b));
	}
	add_ops(&ops, 1, f[B][PUSH](a, b));
	d = sort_3(a, b, A, 1);
	ft_lstadd_back(&ops, d);
	add_ops(&ops, 1, f[A][PUSH](a, b));
	return (ops);
}

t_list	*solve_5(t_twlist **a, t_twlist **b)
{
	t_list	*ops;
	t_op	(*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b);
	int		i;

	init_f(f);
	ops = NULL;
	i = 0;
	while (i < 2)
	{
		while (!(ft_ismatch(get_val(*a), 2, 0, 1)))
			add_ops(&ops, 1, f[A][ROTATE](a, b));
		add_ops(&ops, 1, f[B][PUSH](a, b));
		i++;
	}
	ft_lstadd_back(&ops, sort_3(a, b, A, 2));
	if (ft_issortedtwlst(*b, 0))
		add_ops(&ops, 1, f[B][SWAP](a, b));
	add_ops(&ops, 2, f[A][PUSH](a, b), f[A][PUSH](a, b));
	return (ops);
}

t_list	*solve_6(t_twlist **a, t_twlist **b)
{
	t_op	(*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b);
	int		i;
	t_list	*ops;

	init_f(f);
	ops = NULL;
	i = 0;
	while (i < 3)
	{
		while (!(ft_ismatch(get_val(*a), 3, 0, 1, 2)))
			add_ops(&ops, 1, f[A][ROTATE](a, b));
		add_ops(&ops, 1, f[B][PUSH](a, b));
		i++;
	}
	ft_lstadd_back(&ops, sort_3(a, b, A, 3));
	ft_lstadd_back(&ops, rev_sort_3(a, b, B, 0));
	while (ft_twlstsize(*b) > 0)
		add_ops(&ops, 1, f[A][PUSH](a, b));
	return (ops);
}
