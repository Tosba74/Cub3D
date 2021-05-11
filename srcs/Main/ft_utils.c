/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/10 22:06:53 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_space_eol(char *s)
{
	// int i;

	// i = -1;
	// while(s[++i])
	// 	;
	// while(s[--i] == ' ')
		// s[i] = 0;
	int len;

	len = ft_strlen(s);
	while (s[--len] == ' ')
		s[len] = 0;
}

int		iscardino(t_data *data, char *s, int nb)
{
	int		i;

	i = -1;
	// ft_putstr(s);
	// ft_putchar('\n');
	while (++i < 4 && data->cardino[0][i]) 
		if (!ft_strncmp(s, data->cardino[0][i], nb))
			return (i);
	return(-1);
}

void	my_pixel_put(t_g *g, int x, int y, int color)
{
		g->win.addr[(y * g->win.w) + x] = color;
}