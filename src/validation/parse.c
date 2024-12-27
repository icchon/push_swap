/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:30:47 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/25 16:34:50 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*strstoarr(char **strs)
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

static int	is_valid_arg(char **arg)
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

int	*parse_mono_arg(char **arg)
{
	int	*arr;

	if (arg == NULL)
		return (NULL);
	if (!is_valid_arg(arg))
		return (NULL);
	arr = strstoarr(arg);
	if (arr == NULL)
		return (NULL);
	return (arr);
}

int	*parse_mul_arg(char **arg)
{
	int	*arr;

	if (!is_valid_arg(arg))
		return (0);
	arr = strstoarr(arg);
	return (arr);
}
