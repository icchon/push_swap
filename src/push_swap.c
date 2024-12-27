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

void	push_swap(int *arr, int n)
{
	t_list	*ops;

	ft_compress(arr, n);
	ops = solve(arr, n);
	optimize(ops);
	print_ops(ops);
	ft_lstclear(&ops, free);
	return ;
}
