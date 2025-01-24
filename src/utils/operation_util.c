/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:03:13 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/24 09:18:27 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opsadd(t_list **ops, int argn, ...)
{
	va_list	ap;
	int		i;
	t_op	*op;
	t_list	*new;

	i = 0;
	va_start(ap, argn);
	while (i < argn)
	{
		op = (t_op *)malloc(sizeof(t_op));
		if (op == NULL)
		{
			va_end(ap);
			return ;
		}
		*op = va_arg(ap, t_op);
		new = ft_lstnew((void *)op);
		lstadd(ops, new);
		i++;
	}
	va_end(ap);
	return ;
}

t_list	*pipeop(t_twlist **a, t_twlist **b, int argn, ...)
{
	va_list		ap;
	t_list		*ops;
	t_opfunc	f;
	t_op		op;
	int			i;

	va_start(ap, argn);
	i = 0;
	ops = NULL;
	while (i < argn)
	{
		f = va_arg(ap, t_opfunc);
		op = f(a, b);
		opsadd(&ops, 1, op);
		i++;
	}
	va_end(ap);
	return (ops);
}

t_opfunc	to_func(t_op op)
{
	if (op == PA)
		return (pa);
	if (op == SA)
		return (sa);
	if (op == RA)
		return (ra);
	if (op == RRA)
		return (rra);
	if (op == PB)
		return (pb);
	if (op == SB)
		return (sb);
	if (op == RB)
		return (rb);
	if (op == RRB)
		return (rrb);
	if (op == RR)
		return (rr);
	if (op == RRR)
		return (rrr);
	if (op == SS)
		return (ss);
	return (NULL);
}

t_op	to_op(char *s)
{
	if (ft_isequal(s, "sa"))
		return (SA);
	if (ft_isequal(s, "sb"))
		return (SB);
	if (ft_isequal(s, "pa"))
		return (PA);
	if (ft_isequal(s, "pb"))
		return (PB);
	if (ft_isequal(s, "ss"))
		return (SS);
	if (ft_isequal(s, "ra"))
		return (RA);
	if (ft_isequal(s, "rb"))
		return (RB);
	if (ft_isequal(s, "rra"))
		return (RRA);
	if (ft_isequal(s, "rrb"))
		return (RRB);
	if (ft_isequal(s, "rrr"))
		return (RRR);
	if (ft_isequal(s, "rr"))
		return (RR);
	return (NONE);
}
