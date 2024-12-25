/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:41:23 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 13:19:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_2(t_twlist **a, t_twlist **b, t_ab ab)
{
	t_op		op;
	t_twlist	*lst;
	static	t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b) = {{sa, pa,
		ra}, {sb, pb, rb}};
	t_list		*ops;

	ops = NULL;
	lst = *a;
	if (ab == B)
		lst = *b;
	if (get_val(lst) <= get_val(lst->next))
		return (ops);
	op = f[ab][SWAP](a, b);
	add_ops(&ops, 1, op);
	return (ops);
}

t_list	*sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min)
{
	static	t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b) = {{sa, pa,
		ra}, {sb, pb, rb}};
	t_list	*ops;
	t_twlist	*lst;

	ops = NULL;
	lst = *a;
	if (ab == B)
		lst = *b;
	if (get_val(lst) == min && get_val(lst->next) == min + 2)
		add_ops(&ops, 2, f[ab][REV_ROTATE](a, b), f[ab][SWAP](a, b));
	else if (get_val(lst) == min + 1 && get_val((lst)->next) == min)
		add_ops(&ops, 1, f[ab][SWAP](a, b));
	else if (get_val(lst) == min + 1 && get_val(lst->next) == min + 2)
		add_ops(&ops, 1, f[ab][REV_ROTATE](a, b));
	else if (get_val(lst) == min + 2 && get_val(lst->next) == min)
		add_ops(&ops, 1, f[ab][ROTATE](a, b));
	else if (get_val(lst) == min + 2 && get_val(lst->next) == min + 1)
		add_ops(&ops, 2, f[ab][ROTATE](a, b), f[ab][SWAP](a, b));
	return (ops);
}

t_list	*rev_sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min)
{
	t_list		*ops;
	t_twlist	*lst;
	static	t_op (*f[N_AB][N_FUNC])(t_twlist **a, t_twlist **b) = {{sa, pa,
		ra}, {sb, pb, rb}};

	ops = NULL;
	lst = *a;
	if (ab == B)
		lst = *b;
	if (get_val(lst) == min + 2 && get_val(lst->next) == min)
		add_ops(&ops, 2, f[ab][REV_ROTATE](a, b), f[ab][SWAP](a, b));
	else if (get_val(lst) == min + 1 && get_val(lst->next) == min + 2)
		add_ops(&ops, 1, f[ab][SWAP](a, b));
	else if (get_val(lst) == min + 1 && get_val(lst->next) == min)
		add_ops(&ops, 1, f[ab][REV_ROTATE](a, b));
	else if (get_val(lst) == min && get_val(lst->next) == min + 2)
		add_ops(&ops, 1, f[ab][ROTATE](a, b));
	else if (get_val(lst) == min && get_val(lst->next) == min + 1)
		add_ops(&ops, 2, f[ab][ROTATE](a, b), f[ab][SWAP](a, b));
	return (ops);
}
