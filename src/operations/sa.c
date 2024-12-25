/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:55 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 12:24:07 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_twlist **lst)
{
	t_twlist	*top;
	t_twlist	*second;

	if (ft_twlstsize(*lst) <= 1)
	{
		return (0);
	}
	top = ft_twlsthead(*lst);
	second = top->next;
	top->prev = second;
	top->next = second->next;
	second->prev = NULL;
	if (second->next != NULL)
		second->next->prev = top;
	second->next = top;
	*lst = second;
	return (1);
}

t_op	sa(t_twlist **a, t_twlist **b)
{
	(void)b;
	if (!swap(a))
	{
		return (NONE);
	}
	return (SA);
}
