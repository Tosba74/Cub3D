/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/17 15:36:02 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_space_eol(char *s)
{
	int	len;

	len = 0;
	if (s)
		len = ft_strlen(s);
	while (s[--len] == ' ')
		s[len] = 0;
}

int	iscardino(t_data *data, char *s, int nb)
{
	int		i;

	i = -1;
	while (++i < 4 && data->cardino[0][i])
		if (!ft_strncmp(s, data->cardino[0][i], nb))
			return (i);
	return (-1);
}

void	my_pixel_put(t_g *g, int x, int y, int color)
{
	mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x, y, color);
	// g->win.addr[(y * g->win.w) + x] = color;
}

int		is_wall(t_g g)
{
	if (g.map.map[(int)g.player.x][(int)g.player.y] == '0')
		return(1);
	else
		return (0);
}

