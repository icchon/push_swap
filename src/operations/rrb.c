/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:51 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 10:13:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_twlist **lst)
{
	t_twlist	*bottom;
	t_twlist	*top;

	if (ft_twlstsize(*lst) <= 1)
	{
		return (0);
	}
	top = ft_twlsthead(*lst);
	bottom = ft_twlstlast(*lst);
	if (bottom->prev != NULL)
	{
		bottom->prev->next = NULL;
	}
	top->prev = bottom;
	bottom->next = top;
	bottom->prev = NULL;
	ft_twlstadd_front(lst, bottom);
	return (1);
}

t_op	rrb(t_twlist **a, t_twlist **b)
{
	(void)a;
	if (!reverse_rotate(b))
	{
		return (NONE);
	}
	return (RRB);
}
