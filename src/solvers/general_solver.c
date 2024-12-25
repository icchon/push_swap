/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:40 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 18:22:22 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_certained_cnt(t_twlist **a)
{
	t_twlist	*node;
	int			current;

	node = ft_twlstlast(*a);
	if (node == NULL)
	{
		return (0);
	}
	if (get_val(node) != 0)
	{
		return (0);
	}
	node = node->next;
	current = 0;
	while (node)
	{
		if (!(get_val(node) == current + 1))
		{
			return (current + 1);
		}
		current++;
		node = node->next;
	}
	return (current + 1);
}

int	calc_pivot(t_twlist **a, int n)
{
	int	latest;

	latest = get_certained_cnt(a);
	return ((n + latest) / 2);
}

int	twlst_any(t_twlist *lst, int start, int end)
{
	int			content;
	t_twlist	*node;

	node = ft_twlsthead(lst);
	while (node)
	{
		content = get_val(node);
		if (start <= content && content <= end)
		{
			return (1);
		}
		node = node->next;
	}
	return (0);
}

t_list	*quick_sort(t_twlist **a, t_twlist **b, int n)
{
	int		pivot;
	t_list	*ops;

	ops = NULL;
	static t_op (*f[N_AB][N_FUNC])(t_twlist * *a, t_twlist * *b) = {{sa, pa,
		ra}, {sb, pb, rb}};
	pivot = calc_pivot(a, n);
	ft_printf("pivot : %d\n", pivot);
	while (twlst_any(*a, 0, pivot - 1))
	{
		if (get_val(*a) < pivot)
		{
			add_ops(&ops, 1, f[B][PUSH](a, b));
		}
		else
		{
			add_ops(&ops, 1, f[A][ROTATE](a, b));
		}
	}
	return (ops);
}

t_list	*solve_general(t_twlist **a, t_twlist **b, int n)
{
	t_list	*ops;

	ops = NULL;
	ft_lstadd_back(&ops, quick_sort(a, b, n));
	return (ops);
}
