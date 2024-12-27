/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twlst1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icchon <icchon@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 06:00:58 by icchon            #+#    #+#             */
/*   Updated: 2024-12-27 06:00:58 by icchon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twlstadd(t_twlist **lst, t_twlist *new)
{
	ft_twlstadd_back(lst, new);
	return ;
}

void	twlstadd_front(t_twlist **lst, t_twlist *new)
{
	ft_twlstadd_front(lst, new);
	return ;
}

t_twlist	*twlstlast(t_twlist *lst)
{
	return (ft_twlstlast(lst));
}

size_t	twlstsize(t_twlist *lst)
{
	return (ft_twlstsize(lst));
}

t_twlist	*twlsthead(t_twlist *lst)
{
	return (ft_twlsthead(lst));
}
