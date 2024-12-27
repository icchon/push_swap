/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twlst2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icchon <icchon@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 06:01:06 by icchon            #+#    #+#             */
/*   Updated: 2024-12-27 06:01:06 by icchon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_twlist *lst, int reversed)
{
	return (ft_issortedtwlst(lst, reversed));
}

t_twlist	*get(t_twlist *lst, int index)
{
	return (ft_twlstget(lst, index));
}
