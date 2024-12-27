/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solver2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icchon <icchon@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 07:11:31 by icchon            #+#    #+#             */
/*   Updated: 2024-12-27 07:11:31 by icchon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nextnbr(t_twlist *a)
{
	t_twlist	*node;
	int			current;

	node = twlstlast(a);
	current = value(node);
	if (current == 0)
	{
		return (1);
	}
	node = node->prev;
	while (node)
	{
		if (!(value(node) == current - 1))
		{
			return (0);
		}
		current = value(node);
		if (current == 0)
		{
			return (value(twlstlast(a)) + 1);
		}
		node = node->prev;
	}
	return (0);
}

int	calc_pivot(t_twlist *a, int n)
{
	int	latest;

	latest = nextnbr(a);
	return ((n + latest) / 2);
}

int	median(t_twlist *lst)
{
	int			*arr;
	int			n;
	t_twlist	*node;
	int			i;

	n = twlstsize(lst);
	arr = (int *)malloc(sizeof(int) * n);
	if (arr == NULL || lst == NULL)
		return (INT_MIN);
	node = lst;
	i = 0;
	while (i < n)
	{
		arr[i++] = value(node);
		node = node->next;
	}
	ft_sort(arr, n, 0);
	node = lst;
	while (node)
	{
		if (value(node) == arr[n / 2])
			return (free(arr), value(node));
		node = node->next;
	}
	return (free(arr), INT_MIN);
}

int	check_buff(t_twlist *lst, int start, int end, int n)
{
	int	i;

	i = start;
	end = ft_min(2, end, n - 1);
	while (i <= end)
	{
		if (!twlst_any(lst, i, i))
			return (0);
		i++;
	}
	return (1);
}

int	check(t_twlist *a, t_twlist *b)
{
	int			next;
	const int	n_condition = 15;

	next = nextnbr(a);
	if (issorted(a, 0) && (twlstsize(b) == 0))
		return (0);
	return (ft_ismatch(next, n_condition, value(get(a, 0)), value(get(a, 1)),
			value(get(a, 2)), value(get(a, 3)), value(get(a, 4)), value(get(a,
					5)), value(get(a, 6)), value(get(a, 7)), value(get(a, 8)),
			value(get(a, 9)), value(get(a, 10)), value(get(b, 0)), value(get(b,
					-1)), value(get(b, -2)), value(get(b, -3))));
}
