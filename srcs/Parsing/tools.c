/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/19 15:15:32 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_color(int *color)
{
	int		i;

	i = -1;
	while (color[++i] && i < 3)
	{
		if (0 > color[i] || color[i] > 255)
			ft_err(6);
	}
	if (i != 3)
		ft_err(6);
	return (ft_get_color(color[0], color[1], color[2]));
}

void	get_texture(t_g *g)
{
	g->tex.cardino[0] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[0].road);
	g->tex.cardino[1] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[1].road);
	g->tex.cardino[2] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[2].road);
	g->tex.cardino[3] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[3].road);
	g->tex.sprite.road = "./textures/sprites/mush.xpm";
	g->tex.sprite = *open_xpm(g->win.mlx_ptr, g->tex.sprite.road);
	g->tex.floor = check_color(g->tex.f);
	g->tex.ceiling = check_color(g->tex.c);
}

void	skip_space_eol(char *s)
{
	int	len;

	len = 0;
	if (s)
		len = ft_strlen(s);
	while (0 <= --len && ft_isspace(s[len]))
		s[len] = 0;
}

int	iscardino(t_g *g, char *s, int nb)
{
	int		i;
	char	*tab[5];

	(void)g;
	i = -1;
	tab[0] = "NO";
	tab[1] = "SO";
	tab[2] = "WE";
	tab[3] = "EA";
	tab[4] = 0;
	while (++i < 4 && tab[i])
		if (!ft_strncmp(s, tab[i], nb))
			return (i);
	return (-1);
}

int	is_wall(t_g g, int x, int y)
{
	if (g.map.map[y][x] != '1')
		return (0);
	else
		return (1);
}
