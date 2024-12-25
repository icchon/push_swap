/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:41:23 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 12:25:57 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_2(t_twlist **a, t_twlist **b, t_ab ab)
{
	t_op		op;
	t_twlist	**s[N_AB];
	t_op		(*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b);
	t_list		*ops;

	ops = NULL;
	init_fs(f, s, a, b);
	if (get_val(*s[ab]) <= get_val((*s[ab])->next))
		return (ops);
	op = f[ab][SWAP](a, b);
	add_ops(&ops, 1, op);
	return (ops);
}

t_list	*sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min)
{
	t_op		(*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b);
	t_list		*ops;
	t_twlist	**s[N_AB];
	t_op		op;

	ops = NULL;
	init_fs(f, s, a, b);
	if (get_val(*s[ab]) == min && get_val((*s[ab])->next) == min + 2)
		add_ops(&ops, 2, f[ab][REV_ROTATE](a, b), f[ab][SWAP](a, b));
	else if (get_val(*s[ab]) == min + 1)
	{
		if (get_val((*s[ab])->next) == min)
			add_ops(&ops, 1, f[ab][SWAP](a, b));
		else if (get_val((*s[ab])->next) == min + 2)
			add_ops(&ops, 1, f[ab][REV_ROTATE](a, b));
	}
	else if (get_val(*s[ab]) == min + 2)
	{
		if (get_val((*s[ab])->next) == min)
		{
			add_ops(&ops, 1, f[ab][ROTATE](a, b));
		}
		else if (get_val((*s[ab])->next) == min + 1)
		{
			op = f[ab][ROTATE](a, b);
			add_ops(&ops, 2, op, f[ab][SWAP](a, b));
		}
	}
	else
	{
		print_stacks(*a, *b);
		ft_printf("kdkdkdkdkd\n");
	}
	return (ops);
}

t_list	*rev_sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min)
{
	t_op		(*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b);
	t_list		*ops;
	t_twlist	**s[N_AB];

	ops = NULL;
	init_fs(f, s, a, b);
	if (get_val(*s[ab]) == min + 2 && get_val((*s[ab])->next) == min)
		add_ops(&ops, 2, f[ab][REV_ROTATE](a, b), f[ab][SWAP](a, b));
	else if (get_val(*s[ab]) == min + 1)
	{
		if (get_val((*s[ab])->next) == min + 2)
			add_ops(&ops, 1, f[ab][SWAP](a, b));
		else if (get_val((*s[ab])->next) == min)
			add_ops(&ops, 1, f[ab][REV_ROTATE](a, b));
	}
	else if (get_val(*s[ab]) == min)
	{
		if (get_val((*s[ab])->next) == min + 2)
			add_ops(&ops, 1, f[ab][ROTATE](a, b));
		else if (get_val((*s[ab])->next) == min + 1)
			add_ops(&ops, 2, f[ab][ROTATE](a, b), f[ab][SWAP](a, b));
	}
	return (ops);
}
