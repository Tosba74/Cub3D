/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:22:24 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/01 19:11:38by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_complet_floor(int *c_rgb, int *color, char **tab)
{
	int		i;
	char	**tab_tmp;

	i = -1;
	tab_tmp = ft_split(tab[1], ',');
	if (ft_strslen(tab_tmp) != 3 || ft_strlen(tab[0]) != 1)
		ft_err(6);
	if (tab)
	{
		if (*color)
			ft_err(6);
		while (tab_tmp[++i])
			c_rgb[i] = ft_atoi(tab_tmp[i]);
		*color = ft_get_color(c_rgb[0], c_rgb[1], c_rgb[2]);
	}
	wrfree(tab_tmp);
}

static char	*get_road(char *line)
{
	char	*s;

	s = ft_strdup(ft_strchr(line, 32) + 1);
	skip_space_eol(s);
	if (ft_check_ext(line, ".xpm"))
		ft_err(5);
	return (s);
}

void	ft_complet_data(t_g *g, char *line)
{
	char	**tab;
	int		ret;

	tab = ft_split(line, ' ');
	if (tab)
	{
		ret = iscardino(g, line, 3);
		if (0 <= ret && ret < 4 && !g->tex.cardino[ret].road)
			g->tex.cardino[ret].road = get_road(line);
		else if (g->tex.cardino[ret].road)
			ft_err(5);
		else if (!ft_strncmp(line, "F ", 2))
			ft_complet_floor(g->tex.f, &g->tex.floor, tab);
		else if (!ft_strncmp(line, "C ", 2))
			ft_complet_floor(g->tex.c, &g->tex.ceiling, tab);
		else
			ft_err(8);
	}
	wrfree(tab);
	wrfree(line);
}

static void	add_map_line(t_g *g, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!(48 <= line[i] && line[i] <= 51) && line[i] != ' ')
		{
			if (iscardino(g, line + i, 1) != -1)
			{
				if (!g->map.nb_player)
					ft_init_player(&g->ray, &g->map, line, i);
				else
					ft_err(7);
			}
			else
				ft_err(8);
		}
		else if (line[i] == '2')
			g->map.nb_sprite++;
	}
	if (g->map.collumn < i)
		g->map.collumn = i;
	g->map.map = ft_strsjoin(g->map.map, line);
	g->map.line++;
	wrfree(line);
}

void	ft_complet_map(t_g *g, char *line, int fd, int ret)
{
	while (ret == 1 && (line[0] == ' ' || line[0] == '1' || line[0] == '0'))
	{
		add_map_line(g, line);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0 && line != NULL)
		add_map_line(g, line);
	else if (line[0] != 0 && ret == 1)
		ft_err(8);
	else
		wrfree(line);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != 0)
			ft_err(8);
		wrfree(line);
	}
	if (line[0] != 0)
		ft_err(8);
	if (ret == -1)
		ft_err(8);
	map_flood_fill(g->map.map, g->ray.posX, g->ray.posY);
	wrfree(line);
}
