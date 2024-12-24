/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:37 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 03:51:11 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

int	main(void)
{
	int n = 6;
	int arr[6] = {2, 4, 5, 40, 53, 87};
	push_swap(arr, n);
	ft_printf("push_swap is done\n");

	return (0);
}