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

void	fill_flood_map(t_map map, int x, int y)
{
	if (y < 0 || x < 0 || y > (ft_strslen(map.map) - 1)
		|| x > ((int)ft_strlen(map.map[y]) - 1))
		ft_err(8);
	if (ft_isinstr("012", map.map[y][x]))
		return ;
	else
		ft_err(8);
	if (map.map[y][x] == '1')
		return ;
	fill_flood_map(map, y - 1, x);
	fill_flood_map(map, y + 1, x);
	fill_flood_map(map, y, x - 1);
	fill_flood_map(map, y, x + 1);
}

static void	ft_complet_floor(t_g *g, char **tab)
{
	int		i;
	char	**tab_tmp;

	i = -1;
	tab_tmp = ft_split(tab[1], ',');
	if (tab)
	{
		if (!ft_strcmp(tab[0], "F"))
		{
			while (tab_tmp[++i])
				g->tex.f[i] = ft_atoi(tab_tmp[i]);
		}
		else if (!ft_strcmp(tab[0], "C"))
		{
			while (tab_tmp[++i])
				g->tex.c[i] = ft_atoi(tab_tmp[i]);
		}
	}
	g->tex.floor = ft_get_color(g->tex.f[0], g->tex.f[1], g->tex.f[2]);
	g->tex.ceiling = ft_get_color(g->tex.c[0], g->tex.c[1], g->tex.c[2]);
	wrfree(tab_tmp);
}

static char	*get_road(char *line)
{
	char	*s;
	char	*ext;

	s = ft_strdup(ft_strchr(line, 32) + 1);
	skip_space_eol(s);
	ext = ft_strdup(ft_strrchr(s, 46));
	if (ft_strncmp(ext, ".xpm", 4))
		ft_err(5);
	wrfree(ext);
	return (s);
}

void	ft_complet_data(t_g *g, char *line)
{
	char	**tab;
	int		ret;

	tab = ft_split(line, ' ');
	if (tab)
	{
		ret = iscardino(g, tab[0], 2);
		if (0 <= ret && ret < 4)
			g->tex.cardino[ret].road = get_road(line);
		else if (!ft_strcmp(tab[0], "F") || !ft_strcmp(tab[0], "C"))
			ft_complet_floor(g, tab);
	}
	wrfree(tab);
	wrfree(line);
}

static void	add_map_line(t_g *g, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!(48 <= line[i] && line[i] <= 51) && line[i] != ' ')
		{
			if (iscardino(g, line + i, 1) != -1)
			{
				g->ray.camera = line[i];
				if (!g->map.nb_player)
					ft_init_player(&g->ray, &g->map, (int)i);
				else
					ft_err(7);
				line[i] = '0';
			}
			else
				ft_err(8);
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
	g->map.line = ft_strslen(g->map.map);
	wrfree(line);
}

/*
void	ft_complet_map(t_g *g, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!(48 <= line[i] && line[i] <= 51) && line[i] != ' ')
		{
			if (iscardino(g, line + i, 1) != -1)
			{
				g->ray.camera = line[i];
				if (!g->map.nb_player)
					ft_init_player(&g->ray, &g->map, (int)i);
				else
					ft_err(7);
				line[i] = '0';
			}
			else
				ft_err(8);
		}
	if (g->map.collumn < i)
		g->map.collumn = i;
	g->map.map = ft_strsjoin(g->map.map, line);
	g->map.line++;
	wrfree(line);
}
*/
