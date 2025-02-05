/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:57 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 12:23:56 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_twlist **lst)
{
	t_twlist	*top;
	t_twlist	*second;

	if (twlstsize(*lst) <= 1)
	{
		return (0);
	}
	top = twlsthead(*lst);
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

t_op	sb(t_twlist **a, t_twlist **b)
{
	(void)a;
	if (!swap(b))
	{
		return (NONE);
	}
	return (SB);
}
