
#include "push_swap.h"

void	print_twlst(t_twlist *lst)
{
	t_twlist	*node;

	node = ft_twlsthead(lst);
	if (node == NULL)
		ft_printf("stack is null\n");
	while (node != NULL)
	{
		if (node->prev != NULL && node->next != NULL)
		{
			ft_printf("prev : %4d, contnt : %d, next : %4d\n",
				*(int *)(node->prev->content), *(int *)node->content,
				*(int *)node->next->content);
		}
		else
		{
			if (node->next != NULL)
			{
				ft_printf("prev : NULL, contnt : %d, next : %4d\n",
					*(int *)node->content, *(int *)node->next->content);
			}
			else if (node->prev != NULL)
			{
				ft_printf("prev : %4d, contnt : %d, next : NULL\n",
					*(int *)node->prev->content, *(int *)node->content);
			}
			else
			{
				ft_printf("prev : NULL, contnt : %d, next : NULL\n",
					*(int *)node->content);
			}
		}
		node = node->next;
	}
	return ;
}

void	print_stacks(t_twlist *a, t_twlist *b)
{
	ft_printf("[a]\n");
	print_twlst(a);
	ft_printf("[b]\n");
	print_twlst(b);
	ft_printf("-----------------------------------------------\n");
	return ;
}

t_op	*exec_sa(t_twlist **a, t_twlist **b)
{
	t_twlist	*top_a;
	t_twlist	*second_a;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = SA;
	(void)b;
	if (ft_twlstsize(*a) <= 1)
	{
		*op = NONE;
		return (op);
	}
	top_a = *a;
	second_a = top_a->next;
	top_a->prev = second_a;
	top_a->next = second_a->next;
	second_a->prev = NULL;
	if (second_a->next != NULL)
		second_a->next->prev = top_a;
	second_a->next = top_a;
	*a = second_a;
	return (op);
}

t_op	*exec_sb(t_twlist **a, t_twlist **b)
{
	t_twlist	*top_b;
	t_twlist	*second_b;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = SB;
	(void)a;
	if (ft_twlstsize(*b) <= 1)
	{
		*op = NONE;
		return (op);
	}
	top_b = *b;
	second_b = top_b->next;
	top_b->prev = second_b;
	top_b->next = second_b->next;
	second_b->prev = NULL;
	if (second_b->next != NULL)
		second_b->next->prev = top_b;
	second_b->next = top_b;
	*b = second_b;
	return (op);
}

t_op	*exec_ss(t_twlist **a, t_twlist **b)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = SS;
	exec_sa(a, b);
	exec_sb(a, b);
	return (op);
}

t_op	*exec_pa(t_twlist **a, t_twlist **b)
{
	t_twlist	*top_b;
	t_twlist	*second_b;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	*op = PA;
	top_b = ft_twlsthead(*b);
	if (top_b == NULL)
	{
		*op = NONE;
		return (op);
	}
	second_b = top_b->next;
	ft_twlstadd_front(a, top_b);
	if (second_b != NULL)
		second_b->prev = NULL;
	*b = second_b;
	return (op);
}

t_op	*exec_pb(t_twlist **a, t_twlist **b)
{
	t_twlist	*top_a;
	t_twlist	*second_a;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = PB;
	top_a = ft_twlsthead(*a);
	if (top_a == NULL)
	{
		*op = NONE;
		return (op);
	}
	second_a = top_a->next;
	ft_twlstadd_front(b, top_a);
	if (second_a != NULL)
		second_a->prev = NULL;
	*a = second_a;
	return (op);
}

t_op	*exec_ra(t_twlist **a, t_twlist **b)
{
	t_twlist	*top_a;
	t_twlist	*second_a;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = RA;
	ft_twlsthead(*a);
	(void)b;
	if (ft_twlstsize(*a) <= 1)
	{
		*op = NONE;
		return (op);
	}
	top_a = *a;
	second_a = top_a->next;
	second_a->prev = NULL;
	*a = second_a;
	ft_twlstadd_back(a, top_a);
	return (op);
}

t_op	*exec_rb(t_twlist **a, t_twlist **b)
{
	t_twlist	*top_b;
	t_twlist	*second_b;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = RB;
	if (ft_twlstsize(*b) <= 1)
	{
		*op = NONE;
		return (op);
	}
	(void)a;
	top_b = *b;
	second_b = top_b->next;
	second_b->prev = NULL;
	*b = second_b;
	ft_twlstadd_back(b, top_b);
	return (op);
}

t_op	*exec_rr(t_twlist **a, t_twlist **b)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = RR;
	exec_ra(a, b);
	exec_rb(a, b);
	return (op);
}

t_op	*exec_rra(t_twlist **a, t_twlist **b)
{
	t_twlist	*bottom_a;
	t_twlist	*top_a;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = RRA;
	(void)b;
	if (ft_twlstsize(*a) <= 1)
	{
		*op = NONE;
		return (op);
	}
	top_a = *a;
	bottom_a = ft_twlstlast(*a);
	if (bottom_a->prev != NULL)
	{
		bottom_a->prev->next = NULL;
	}
	top_a->prev = bottom_a;
	bottom_a->next = top_a;
	bottom_a->prev = NULL;
	*a = bottom_a;
	return (op);
}

t_op	*exec_rrb(t_twlist **a, t_twlist **b)
{
	t_twlist	*bottom_b;
	t_twlist	*top_b;
	t_op		*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = RRB;
	if (ft_twlstsize(*a) <= 1)
	{
		*op = NONE;
		return (op);
	}
	(void)a;
	top_b = *b;
	bottom_b = ft_twlstlast(*b);
	if (bottom_b->prev != NULL)
	{
		bottom_b->prev->next = NULL;
	}
	top_b->prev = bottom_b;
	bottom_b->next = top_b;
	bottom_b->prev = NULL;
	*a = bottom_b;
	return (op);
}

t_op	*exec_rrr(t_twlist **a, t_twlist **b)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (op == NULL)
		return (NULL);
	*op = RRR;
	exec_rra(a, b);
	exec_rrb(a, b);
	return (op);
}

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

t_list	*sort2(t_twlist *a, t_twlist *b)
{
	t_list	*ops;

	ops = NULL;
	print_stacks(a, b);
	if (*(int *)a->content > *(int *)a->next->content)
		ft_lstadd_back(&ops, ft_lstnew(exec_sa(&a, &b)));
	return (ops);
}

t_list	*sort3(t_twlist *a, t_twlist *b, int min)
{
	t_list	*ops;

	ops = NULL;
	if (*(int *)a->content == min)
	{
		if (*(int *)a->next->content == min + 2)
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_ra(&a, &b)));
			print_stacks(a, b);
			ft_lstadd_back(&ops, ft_lstnew(exec_sa(&a, &b)));
			print_stacks(a, b);
			ft_lstadd_back(&ops, ft_lstnew(exec_rra(&a, &b)));
		}
	}
	else if (*(int *)a->content == min + 1)
	{
		if (*(int *)a->next->content == min)
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_sa(&a, &b)));
		}
		else if (*(int *)a->next->content == min + 2)
			ft_lstadd_back(&ops, ft_lstnew(exec_rra(&a, &b)));
	}
	else if (*(int *)a->content == min + 2)
	{
		if (*(int *)a->next->content == min)
			ft_lstadd_back(&ops, ft_lstnew(exec_ra(&a, &b)));
		else if (*(int *)a->next->content == min + 1)
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_ra(&a, &b)));
			print_stacks(a, b);
			ft_lstadd_back(&ops, ft_lstnew(exec_sa(&a, &b)));
		}
	}
	print_stacks(a, b);
	return (ops);
}

t_list	*rev_sort3(t_twlist *a, t_twlist *b, int min)
{
	t_list	*ops;

	ops = NULL;
	if (*(int *)b->content == min + 2)
	{
		if (*(int *)b->next->content == min)
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_rb(&a, &b)));
			print_stacks(a, b);
			ft_lstadd_back(&ops, ft_lstnew(exec_sb(&a, &b)));
			print_stacks(a, b);
			ft_lstadd_back(&ops, ft_lstnew(exec_rrb(&a, &b)));
		}
	}
	else if (*(int *)b->content == min + 1)
	{
		if (*(int *)b->next->content == min + 2)
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_sb(&a, &b)));
		}
		else if (*(int *)b->next->content == min)
			ft_lstadd_back(&ops, ft_lstnew(exec_rrb(&a, &b)));
	}
	else if (*(int *)b->content == min)
	{
		if (*(int *)b->next->content == min + 2)
			ft_lstadd_back(&ops, ft_lstnew(exec_rb(&a, &b)));
		else if (*(int *)b->next->content == min + 1)
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_rb(&a, &b)));
			print_stacks(a, b);
			ft_lstadd_back(&ops, ft_lstnew(exec_sb(&a, &b)));
		}
	}
	print_stacks(a, b);
	return (ops);
}

t_list	*sort4(t_twlist *a, t_twlist *b)
{
	t_list	*ops;

	ops = NULL;
	while (*(int *)a->content != 0)
	{
		ft_lstadd_back(&ops, ft_lstnew(exec_ra(&a, &b)));
		print_stacks(a, b);
	}
	ft_lstadd_back(&ops, ft_lstnew(exec_pb(&a, &b)));
	print_stacks(a, b);
	ft_lstadd_back(&ops, sort3(a, b, 1));
	ft_lstadd_back(&ops, ft_lstnew(exec_pa(&a, &b)));
	return (ops);
}

t_list	*sort5(t_twlist *a, t_twlist *b)
{
	t_list	*ops;
	int		i;

	ops = NULL;
	i = 0;
	while (i < 2)
	{
		while (!(*(int *)a->content == 0 || *(int *)a->content == 1))
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_ra(&a, &b)));
			print_stacks(a, b);
		}
		ft_lstadd_back(&ops, ft_lstnew(exec_pb(&a, &b)));
		print_stacks(a, b);
		i++;
	}
	ft_lstadd_back(&ops, sort3(a, b, 2));
	if (ft_issortedtwlst(b, 0))
	{
		ft_lstadd_back(&ops, ft_lstnew(exec_sb(&a, &b)));
		print_stacks(a, b);
	}
	ft_lstadd_back(&ops, ft_lstnew(exec_pa(&a, &b)));
	print_stacks(a, b);
	ft_lstadd_back(&ops, ft_lstnew(exec_pa(&a, &b)));
	print_stacks(a, b);
	return (ops);
}

t_list	*sort6(t_twlist *a, t_twlist *b)
{
	t_list	*ops;
	int		i;

	ops = NULL;
	i = 0;
	while (i < 3)
	{
		while (!(*(int *)a->content == 0 || *(int *)a->content == 1
				|| *(int *)a->content == 2))
		{
			ft_lstadd_back(&ops, ft_lstnew(exec_ra(&a, &b)));
			print_stacks(a, b);
		}
		ft_lstadd_back(&ops, ft_lstnew(exec_pb(&a, &b)));
		print_stacks(a, b);
		i++;
	}
	ft_lstadd_back(&ops, sort3(a, b, 3));
	ft_lstadd_back(&ops, rev_sort3(a, b, 0));
	while (ft_twlstsize(b) > 0)
	{
		ft_lstadd_back(&ops, ft_lstnew(exec_pa(&a, &b)));
		print_stacks(a, b);
	}
	return (ops);
}

t_list	*sort_over7(t_twlist *a, t_twlist *b)
{
}

void	print_op(t_op op)
{
	if (op == NONE)
	{
		return ;
	}
	else if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	else if (op == SS)
		ft_printf("ss\n");
	else if (op == RA)
		ft_printf("ra\n");
	else if (op == RB)
		ft_printf("rb\n");
	else if (op == RR)
		ft_printf("rr\n");
	else if (op == PA)
		ft_printf("pa\n");
	else if (op == PB)
		ft_printf("pb\n");
	else if (op == RRA)
		ft_printf("rra\n");
	else if (op == RRB)
		ft_printf("rrb\n");
	else if (op == RRR)
		ft_printf("rrr\n");
	return ;
}

void	print_ops(t_list *ops)
{
	t_list	*node;
	t_op	op;

	if (ops == NULL)
	{
		ft_printf("ops is null\n");
		return ;
	}
	node = ops;
	while (node != NULL)
	{
		op = *(t_op *)node->content;
		print_op(op);
		node = node->next;
	}
	return ;
}

void	test(t_twlist *a, t_twlist *b)
{
	print_stacks(a, b);
	exec_pb(&a, &b);
	print_stacks(a, b);
	exec_pb(&a, &b);
	print_stacks(a, b);
	exec_pb(&a, &b);
	print_stacks(a, b);
	exec_pa(&a, &b);
	print_stacks(a, b);
	exec_pa(&a, &b);
	print_stacks(a, b);
	exec_pa(&a, &b);
	print_stacks(a, b);
}

t_list	*manage_sort(int *arr, int n)
{
	t_twlist	*a;
	t_twlist	*b;
	t_list		*ops;

	ops = NULL;
	create_stacks(&a, &b, arr, n);
	print_stacks(a, b);
	if (ft_issortedtwlst(a, 0))
		ft_printf("already sorted\n");
	else if (n == 2)
		ops = sort2(a, b);
	else if (n == 3)
		ops = sort3(a, b, 0);
	else if (n == 4)
		ops = sort4(a, b);
	else if (n == 5)
		ops = sort5(a, b);
	else if (n == 6)
		ops = sort6(a, b);
	else
	{
		test(a, b);
	}
	ft_exfree(2, a, b);
	return (ops);
}

t_list	*push_swap(int *arr, int n)
{
	int		i;
	t_list	*ops;

	ft_compress(arr, n);
	ft_printf("argments : ");
	ft_print_arr(arr, n);
	ops = manage_sort(arr, n);
	print_ops(ops);
	return (ft_lstnew(&i));
}
