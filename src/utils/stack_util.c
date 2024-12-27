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

int	value(t_twlist *lst)
{
	if (lst == NULL)
		return (INT_MIN);
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

int	twlst_any(t_twlist *lst, int start, int end)
{
	int			content;
	t_twlist	*node;

	node = twlsthead(lst);
	while (node)
	{
		content = value(node);
		if (start <= content && content <= end)
		{
			return (1);
		}
		node = node->next;
	}
	return (0);
}
