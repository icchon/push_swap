/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:18:27 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/24 09:27:47 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_arr(int argc, char *argv[], int **arr)
{
	char	**arg;
	int		n;

	n = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (arg == NULL)
			return (-1);
		n = ft_strslen((const char **)arg);
		*arr = parse_mono_arg(arg);
		free_strs(arg);
		if (*arr == NULL)
			return (-1);
	}
	else
	{
		arg = &argv[1];
		n = ft_strslen((const char **)arg);
		*arr = parse_mul_arg(arg);
		if (*arr == NULL)
			return (-1);
	}
	return (n);
}

void	simulate_push_swap(t_twlist **a, t_twlist **b, t_list *ops)
{
	t_list		*node;
	t_opfunc	f;
	t_op		op;

	if (!ops)
		return ;
	node = ops;
	while (node)
	{
		op = *(t_op *)node->content;
		f = to_func(op);
		if (!f)
			return ;
		f(a, b);
		node = node->next;
	}
	return ;
}

int	push_swap_check(int *arr, int n, t_list *ops)
{
	t_twlist	*a;
	t_twlist	*b;

	ft_compress(arr, n);
	create_stacks(&a, &b, arr, n);
	simulate_push_swap(&a, &b, ops);
	if ((issorted(a, 0) && (twlstsize(b) == 0)))
	{
		free_stacks(a, b);
		return (1);
	}
	else
	{
		free_stacks(a, b);
		return (0);
	}
}

t_list	*get_ops(void)
{
	t_list	*ops;
	t_op	op;
	char	*line;

	ops = NULL;
	line = get_next_line(0);
	while (line)
	{
		op = to_op(line);
		if (op == NONE)
		{
			free(line);
			ft_lstclear(&ops, free);
			return (NULL);
		}
		opsadd(&ops, 1, op);
		free(line);
		line = get_next_line(0);
	}
	return (ops);
}

int	main(int argc, char *argv[])
{
	int		n;
	int		*arr;
	t_list	*ops;

	n = 0;
	if (argc < 2)
		return (ft_dprintf(2, "Error\n"), 0);
	arr = NULL;
	n = set_arr(argc, argv, &arr);
	if (arr == NULL || n < 0)
		return (ft_dprintf(2, "Error\n"), 0);
	if (ft_compress(arr, n) != n)
		return (ft_dprintf(2, "Error\n"), free(arr), 0);
	ops = get_ops();
	if (!ops)
		return (ft_dprintf(2, "Error\n"), free(arr), 0);
	if (push_swap_check(arr, n, ops))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&ops, free);
	return (free(arr), 0);
}
