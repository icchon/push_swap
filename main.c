/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:37 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/24 09:23:07 by kaisobe          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int	n;
	int	*arr;

	n = 0;
	if (argc < 2)
		return (0);
	arr = NULL;
	n = set_arr(argc, argv, &arr);
	if (arr == NULL || n < 0)
		return (ft_dprintf(2, "Error\n"), 0);
	if (ft_compress(arr, n) != n)
		return (ft_dprintf(2, "Error\n"), free(arr), 0);
	push_swap(arr, n);
	return (free(arr), 0);
}
