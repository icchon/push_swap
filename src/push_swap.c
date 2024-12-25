/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:22:24 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 16:17:16 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	test(t_twlist **a, t_twlist **b)
// {
// 	print_stacks(*a, *b);
// 	pb(a, b);
// 	print_stacks(*a, *b);
// 	pb(a, b);
// 	print_stacks(*a, *b);
// 	pb(a, b);
// 	print_stacks(*a, *b);
// 	pa(a, b);
// 	print_stacks(*a, *b);
// 	pa(a, b);
// 	print_stacks(*a, *b);
// 	pa(a, b);
// 	print_stacks(*a, *b);
// }

void	push_swap(int *arr, int n)
{
	t_list	*ops;

	ft_compress(arr, n);
	ft_printf("compressed args : ");
	ft_print_arr(arr, n);
	ops = solve(arr, n);
	optimize(ops);
	print_ops(ops);
	ft_lstclear(&ops, free);
	return ;
}
