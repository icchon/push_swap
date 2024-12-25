/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:49:41 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 16:16:12 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*solve_special(t_twlist **a, t_twlist **b, int n)
{
	t_list	*ops;

	ops = NULL;
	if (ft_issortedtwlst(*a, 0))
		ft_printf("already sorted\n");
	else if (n == 2)
		ops = solve_2(a, b);
	else if (n == 3)
		ops = solve_3(a, b);
	else if (n == 4)
		ops = solve_4(a, b);
	else if (n == 5)
		ops = solve_5(a, b);
	else if (n == 6)
		ops = solve_6(a, b);
	else
	{
		ft_printf("Un Hundled Error\nsize is over 6, but use special solver\n");
	}
	return (ops);
}

t_list	*solve(int *arr, int n)
{
	t_twlist	*a;
	t_twlist	*b;
	t_list		*ops;

	ops = NULL;
	create_stacks(&a, &b, arr, n);
	print_stacks(a, b);
	if (n < 7)
		ops = solve_special(&a, &b, n);
	else
		ops = solve_general(&a, &b);
	print_stacks(a, b);
	free_stacks(a, b);
	return (ops);
}
