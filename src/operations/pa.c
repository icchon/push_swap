/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:33:38 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 12:45:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_twlist **dest, t_twlist **src)
{
	t_twlist	*top_src;
	t_twlist	*second_src;

	top_src = twlsthead(*src);
	if (top_src == NULL)
	{
		return (0);
	}
	second_src = top_src->next;
	top_src->prev = NULL;
	twlstadd_front(dest, top_src);
	if (second_src != NULL)
		second_src->prev = NULL;
	*src = second_src;
	return (1);
}

t_op	pa(t_twlist **a, t_twlist **b)
{
	if (!push(a, b))
	{
		return (NONE);
	}
	return (PA);
}
