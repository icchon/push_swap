/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:49 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 10:12:52 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_twlist **lst)
{
	t_twlist	*bottom;
	t_twlist	*top;

	if (twlstsize(*lst) <= 1)
	{
		return (0);
	}
	top = twlsthead(*lst);
	bottom = twlstlast(*lst);
	if (bottom->prev != NULL)
	{
		bottom->prev->next = NULL;
	}
	top->prev = bottom;
	bottom->next = top;
	bottom->prev = NULL;
	twlstadd_front(lst, bottom);
	return (1);
}

t_op	rra(t_twlist **a, t_twlist **b)
{
	(void)b;
	if (!reverse_rotate(a))
	{
		return (NONE);
	}
	return (RRA);
}
