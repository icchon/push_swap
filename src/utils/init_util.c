/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:00:05 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 13:21:44 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_twlist **stacks[], t_twlist **a, t_twlist **b)
{
	stacks[A] = a;
	stacks[B] = b;
	return ;
}
