/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:00:58 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 16:14:58 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(t_twlist **a, t_twlist **b, int *arr, int n)
{
	t_twlist	*node;
	int			i;

	*a = NULL;
	*b = NULL;
	i = 0;
	while (i < n)
	{
		node = ft_twlstnew(&arr[i]);
		ft_twlstadd_back(a, node);
		i++;
	}
	return ;
}

int	get_val(t_twlist *lst)
{
	if (lst == NULL)
		return (-1);
	return (*(int *)(lst)->content);
}

void	free_stacks(t_twlist *a, t_twlist *b)
{
	t_twlist	*node;
	t_twlist	*next;

	node = ft_twlsthead(a);
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	node = ft_twlsthead(b);
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	return ;
}
