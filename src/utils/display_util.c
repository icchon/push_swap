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

static void	print_op(t_op op)
{
	if (op == SA)
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
}

// static void	print(t_twlist *lst)
// {
// 	t_twlist	*node;
// 	int			i;
// 	int			*arr;
// 	int			n;
// 	const int	w = 25;

// 	n = twlstsize(lst);
// 	arr = (int *)malloc(sizeof(int) * n);
// 	if (arr == NULL)
// 		return ;
// 	i = 0;
// 	node = lst;
// 	if (node == NULL)
// 		ft_printf("stack is null\n");
// 	while (node != NULL)
// 	{
// 		arr[i] = value(node);
// 		node = node->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (i % w == 0)
// 		{
// 			ft_printf("|");
// 		}
// 		ft_printf("%2d ", arr[i]);
// 		i++;
// 		if (i % w == 0)
// 		{
// 			ft_printf("|\n");
// 		}
// 	}
// 	if (i % w != 0)
// 	{
// 		ft_printf("|");
// 	}
// 	ft_printf("\n");
// 	return ;
// }

// void	print_stacks(t_twlist *a, t_twlist *b)
// {
// 	return ;
// 	ft_printf("\n-----------------[a]-----------------\n");
// 	print(a);
// 	ft_printf("-----------------[b]--------------------\n");
// 	print(b);
// 	ft_printf("---------------------------------------\n\n");
// 	return ;
// }

void	print_ops(t_list *ops)
{
	t_list	*node;
	t_op	op;
	int		cnt;

	cnt = 0;
	if (ops == NULL)
	{
		return ;
	}
	node = ops;
	while (node != NULL)
	{
		op = *(t_op *)node->content;
		print_op(op);
		cnt++;
		node = node->next;
	}
	return ;
	ft_printf("-------------------------\n");
	ft_printf("|     command :    %d     |\n", cnt);
	ft_printf("-------------------------\n");
	return ;
}
