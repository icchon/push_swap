/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:03:46 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 09:03:52 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_optimize(t_list *node, t_list *next)
{
	t_op	now_op;
	t_op	next_op;

	if (next == NULL)
		return ;
	now_op = *(t_op *)node->content;
	next_op = *(t_op *)next->content;
	if ((now_op == RA && next_op == RB) || (now_op == RB && next_op == RA))
	{
		*(t_op *)(node->content) = RR;
		*(t_op *)(next->content) = NONE;
	}
	if ((now_op == RRA && next_op == RRB) || (now_op == RRB && next_op == RRA))
	{
		*(t_op *)(node->content) = RRR;
		*(t_op *)(next->content) = NONE;
	}
	if ((now_op == SA && next_op == SB) || (now_op == SB && next_op == SA))
	{
		*(t_op *)(node->content) = SS;
		*(t_op *)(next->content) = NONE;
	}
	return ;
}

void	optimize(t_list *ops)
{
	t_list	*node;
	t_list	*next;

	node = ops;
	if (node == NULL)
		return ;
	while (node)
	{
		next = node->next;
		try_optimize(node, next);
		node = node->next;
	}
	return ;
}
