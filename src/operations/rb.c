/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:45 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 11:24:00 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_twlist **lst)
{
	t_twlist	*top;
	t_twlist	*second;

	top = twlsthead(*lst);
	if (twlstsize(*lst) <= 1)
	{
		return (0);
	}
	second = top->next;
	second->prev = NULL;
	*lst = second;
	twlstadd(lst, top);
	return (1);
}

t_op	rb(t_twlist **a, t_twlist **b)
{
	(void)a;
	if (!rotate(b))
	{
		return (NONE);
	}
	return (RB);
}
