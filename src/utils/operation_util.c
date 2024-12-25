/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:03:13 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 11:43:43 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_ops(t_list **ops, int argn, ...)
{
	va_list	ap;
	int		i;
	t_op	*op;
	t_list	*new;

	i = 0;
	va_start(ap, argn);
	while (i < argn)
	{
		op = (t_op *)malloc(sizeof(t_op));
		if (op == NULL)
		{
			va_end(ap);
			return ;
		}
		*op = va_arg(ap, t_op);
		new = ft_lstnew((void *)op);
		ft_lstadd_back(ops, new);
		i++;
	}
	va_end(ap);
	return ;
}
