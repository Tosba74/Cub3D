/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:20:23 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/14 21:23:57y bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstadd_frt(t_lst **lst, t_lst *new)
{
	new->next = *lst;
	*lst = new;
}

t_lst	*ft_lst_new(float x, float y, int id)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (lst)
	{
		lst->x = x;
		lst->y = y;
		lst->id = id;
		lst->next = NULL;
	}
	return (lst);
}

void	ft_clear_lst(t_lst **lst)
{
	t_lst	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	ft_in_lst(t_lst *lst, float x, float y)
{
	while (lst)
	{
		if (lst->x == x && lst->y == y)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ft_lst_size(t_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
