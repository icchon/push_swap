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
	t_twlist		*lst;
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};
	t_list			*ops;

	ops = NULL;
	lst = *a;
	if (ab == B)
		lst = *b;
	if (value(lst) <= value(lst->next))
		return (ops);
	lstadd(&ops, pipeop(a, b, 1, f[ab][SWAP]));
	return (ops);
}

t_list	*sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min)
{
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};
	t_list			*ops;
	t_twlist		*lst;

	ops = NULL;
	lst = *a;
	if (ab == B)
		lst = *b;
	if (value(lst) == min && value(lst->next) == min + 2)
		lstadd(&ops, pipeop(a, b, 2, f[ab][REV_ROTATE], f[ab][SWAP]));
	else if (value(lst) == min + 1 && value((lst)->next) == min)
		lstadd(&ops, pipeop(a, b, 1, f[ab][SWAP]));
	else if (value(lst) == min + 1 && value(lst->next) == min + 2)
		lstadd(&ops, pipeop(a, b, 1, f[ab][REV_ROTATE]));
	else if (value(lst) == min + 2 && value(lst->next) == min)
		lstadd(&ops, pipeop(a, b, 1, f[ab][ROTATE]));
	else if (value(lst) == min + 2 && value(lst->next) == min + 1)
		lstadd(&ops, pipeop(a, b, 2, f[ab][ROTATE], f[ab][SWAP]));
	return (ops);
}

t_list	*rev_sort_3(t_twlist **a, t_twlist **b, t_ab ab, int min)
{
	t_list			*ops;
	t_twlist		*lst;
	static t_opfunc	f[N_AB][N_FUNC] = {{sa, pa, ra, rra}, {sb, pb, rb, rrb}};

	ops = NULL;
	lst = *a;
	if (ab == B)
		lst = *b;
	if (value(lst) == min + 2 && value(lst->next) == min)
		lstadd(&ops, pipeop(a, b, 2, f[ab][REV_ROTATE], f[ab][SWAP]));
	else if (value(lst) == min + 1 && value(lst->next) == min + 2)
		lstadd(&ops, pipeop(a, b, 1, f[ab][SWAP]));
	else if (value(lst) == min + 1 && value(lst->next) == min)
		lstadd(&ops, pipeop(a, b, 1, f[ab][REV_ROTATE]));
	else if (value(lst) == min && value(lst->next) == min + 2)
		lstadd(&ops, pipeop(a, b, 1, f[ab][ROTATE]));
	else if (value(lst) == min && value(lst->next) == min + 1)
		lstadd(&ops, pipeop(a, b, 2, f[ab][ROTATE], f[ab][SWAP]));
	return (ops);
}
