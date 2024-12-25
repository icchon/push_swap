/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:43 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 11:34:29 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_twlist **lst)
{
	t_twlist	*top;
	t_twlist	*second;

	top = ft_twlsthead(*lst);
	if (ft_twlstsize(top) <= 1)
	{
		return (0);
	}
	second = top->next;
	second->prev = NULL;
	*lst = second;
	ft_twlstadd_back(lst, top);
	return (1);
}

t_op	ra(t_twlist **a, t_twlist **b)
{
	(void)b;
	if (!rotate(a))
	{
		return (NONE);
	}
	return (RA);
}
