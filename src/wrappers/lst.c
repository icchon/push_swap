/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icchon <icchon@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 06:00:52 by icchon            #+#    #+#             */
/*   Updated: 2024-12-27 06:00:52 by icchon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd(t_list **lst, t_list *new)
{
	ft_lstadd_back(lst, new);
	return ;
}

void	lstadd_front(t_list **lst, t_list *new)
{
	ft_lstadd_front(lst, new);
	return ;
}

t_list	*lstlast(t_list *lst)
{
	return (ft_lstlast(lst));
}

size_t	lstsize(t_list *lst)
{
	return (ft_lstsize(lst));
}
