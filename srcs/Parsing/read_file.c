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

/*
void    fill_flood_map(t_cub *cub, int y, int x)
{
    if (y < 0 || x < 0 || y > (ft_tablen(cub) - 1) || \
	x > ((int)ft_strlen(cub->map.tab_map[y]) - 1))
	error("The map is not close.\n", cub);
    if (ft_ischar("|.$#", cub->map.tab_map[y][x]))
	return ;
    if (cub->map.tab_map[y][x] == '1')
    {
	cub->map.tab_map[y][x] = '|';
	return ;
    }
    if (cub->map.tab_map[y][x] == '0')
	cub->map.tab_map[y][x] = '.';
    if (cub->map.tab_map[y][x] == '2')
	cub->map.tab_map[y][x] = '$';
    if (cub->map.tab_map[y][x] == '3')
	cub->map.tab_map[y][x] = '#';
    fill_flood_map(cub, y - 1, x);
    fill_flood_map(cub, y + 1, x);
    fill_flood_map(cub, y, x - 1);
    fill_flood_map(cub, y, x + 1);
}
*/

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
}

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
}
