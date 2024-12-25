/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:43:08 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 13:21:16 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_op op)
{
	if (op == NONE)
		ft_printf("none\n");
	else if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	else if (op == SS)
		ft_printf("ss\n");
	else if (op == RA)
		ft_printf("ra\n");
	else if (op == RB)
		ft_printf("rb\n");
	else if (op == RR)
		ft_printf("rr\n");
	else if (op == PA)
		ft_printf("pa\n");
	else if (op == PB)
		ft_printf("pb\n");
	else if (op == RRA)
		ft_printf("rra\n");
	else if (op == RRB)
		ft_printf("rrb\n");
	else if (op == RRR)
		ft_printf("rrr\n");
	else
		ft_printf("op is invalid : %d\n", op);
	return ;
}

void	print_ops(t_list *ops)
{
	t_list	*node;
	t_op	op;

	if (ops == NULL)
	{
		ft_printf("ops is null\n");
		return ;
	}
	node = ops;
	while (node != NULL)
	{
		op = *(t_op *)node->content;
		print_op(op);
		node = node->next;
	}
	return ;
}

void	print_twlst(t_twlist *lst)
{
	t_twlist	*node;

	node = lst;
	if (node == NULL)
		ft_printf("stack is null\n");
	while (node != NULL)
	{
		if (node->prev != NULL && node->next != NULL)
		{
			ft_printf("prev : %4d, contnt : %d, next : %4d\n",
				*(int *)(node->prev->content), *(int *)node->content,
				*(int *)node->next->content);
		}
		else
		{
			if (node->next != NULL)
			{
				ft_printf("prev : NULL, contnt : %d, next : %4d\n",
					*(int *)node->content, *(int *)node->next->content);
			}
			else if (node->prev != NULL)
			{
				ft_printf("prev : %4d, contnt : %d, next : NULL\n",
					*(int *)node->prev->content, *(int *)node->content);
			}
			else
			{
				ft_printf("prev : NULL, contnt : %d, next : NULL\n",
					*(int *)node->content);
			}
		}
		node = node->next;
	}
	return ;
}

void	print_stacks(t_twlist *a, t_twlist *b)
{
	ft_printf("[a]\n");
	print_twlst(a);
	ft_printf("[b]\n");
	print_twlst(b);
	ft_printf("-----------------------------------------------\n");
	return ;
}
