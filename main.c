/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:13:37 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 15:50:02 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_one_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		if (!ft_isint(arg[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	*strstoarr(char **strs)
{
	int	*arr;
	int	n;
	int	i;

	n = ft_strslen((const char **)strs);
	arr = (int *)malloc(sizeof(int) * n);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		arr[i] = ft_atoi(strs[i]);
		i++;
	}
	return (arr);
}

int	*parse_mono_arg(char **arg)
{
	int	n;
	int	*arr;

	n = ft_strslen((const char **)arg);
	if (arg == NULL)
		return (NULL);
	if (!is_valid_one_arg(arg))
		return (NULL);
	arr = strstoarr(arg);
	if (arr == NULL)
		return (NULL);
	return (arr);
}

int	*parse_mul_arg(char **arg)
{
	int	n;
	int	*arr;

	n = ft_strslen((const char **)arg);
	if (!is_valid_one_arg(arg))
		return (0);
	arr = strstoarr(arg);
	return (arr);
}

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
