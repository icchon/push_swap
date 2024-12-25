/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:37 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 16:33:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		n;
	int		*arr;
	char	**arg;

	n = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (arg == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		n = ft_strslen((const char **)arg);
		arr = parse_mono_arg(arg);
		free(arg);
	}
	else
	{
		arg = &argv[1];
		n = ft_strslen((const char **)arg);
		arr = parse_mul_arg(arg);
	}
	if (arr == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	push_swap(arr, n);
	free(arr);
	return (0);
}
