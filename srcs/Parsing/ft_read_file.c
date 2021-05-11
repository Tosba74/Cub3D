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
				g->data.f[i] = ft_atoi(tab_tmp[i]);
		}
		else if (!ft_strcmp(tab[0], "C"))
		{
			while (tab_tmp[++i])
				g->data.c[i] = ft_atoi(tab_tmp[i]);
		}
	}
	g->data.floor = ft_get_color(g->data.f[0], g->data.f[1], g->data.f[2]);
	g->data.ceiling = ft_get_color(g->data.c[0], g->data.c[1], g->data.c[2]);
	wrfree(tab_tmp);
}

static void	check_reso(t_g *g)
{
	if (g->data.w <= 0)
		ft_err(3);
	if (g->data.h <= 0)
		ft_err(3);
	if (g->data.w > X_RES)
		g->win.w = X_RES;
	else
		g->win.w = g->data.w;
	if (g->data.h > Y_RES)
		g->win.h = Y_RES;
	else
		g->win.h = g->data.h;
}

static void	get_resolution(t_g *g, char **tab)
{
	int i;

	i = 1;
	printf("*----------- -- --GET RESOLUTION-- -- ----------*\n");
	if (ft_strslen(tab) == 3)
	{
		g->data.w = ft_atoi(tab[i]);
		g->data.h = ft_atoi(tab[i + 1]);
	}
	else if (ft_strslen(tab) < 3)
		ft_err(3);
	else if (ft_strslen(tab) > 3)
		ft_err(4);
	check_reso(g);
}

static char	*get_road(char *line)
{
	char	*s;
	char	*ext;

	s = ft_strdup(ft_strchr(line, 32) + 1);
	ext = ft_strdup(ft_strrchr(s, 46));
	printf("|----------- -- -- -|GET ROAD|- -- -- ----------|\n");
	printf("*-----------------------------------------------*\n");
	printf("| road =>|%-24s|ext =>|%-6s|\n", s, ext);
	if (!ft_strncmp(ext, ".xpm", 4))
		ft_putstr("| -- -- -- -- --XPM EXTENTION OK!-- -- -- -- -- |\n");
	else
	{
		ft_putstr("| -- -- -- -- -MAUVAISE  EXTENTION- -- -- -- -- |\n");
		ft_err(5);
	}
	printf("*- - - - -- -- -- ------------- -- -- -- - - - -*\n");
	printf("| road =>|%-24s|ext =>|%-6s|\n", s, ext);
	printf("*- - - - -- -- -- ------------- -- -- -- - - - -*\n");
	return (s);
}

static void	ft_complet_data(t_g *g, char *line)
{
	char	**tab;
	int		ret;

	printf("*-----------------------------------------------*\n");
	printf("|--------- -- --|COMPLET  DATA|-- -- -----------|\n");
	printf("*-----------------------------------------------*\n");
	printf("|%-47s|\n", line);
	printf("*-----------------------------------------------*\n");
	tab = ft_split(line, ' ');
	if (tab)
	{
		ret = iscardino(&(g->data), tab[0], 2);
		if (ret > -1)
		{
			g->data.cardino[1][ret] = get_road(line);
			printf("*-----------------------------------------------*\n");
			printf("|%4s|%-42s|\n", g->data.cardino[0][ret], g->data.cardino[1][ret]);
			printf("*-----------------------------------------------*\n");
		}
		else if (!ft_strcmp(tab[0], "R"))
		{
			get_resolution(g, tab);
			printf("| %s | %19d | %-19d |\n", tab[0], g->data.w, g->data.h);
			printf("*-----------------------------------------------*\n");
		}
		else if (!ft_strcmp(tab[0], "S"))
			g->data.sprite = ft_strdup((tab[1]));
		else if (!ft_strcmp(tab[0], "F") || !ft_strcmp(tab[0], "C"))
			ft_complet_floor(g, tab);
		printf("|%2d|line => [%-26s] - ok !|\n",ret, line);
	}
	wrfree(line);
	wrfree(tab);
}

static void	ft_complet_map(t_g *g, char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '2')
			(void)i;
		else if (!(48 <= line[i] && line[i] <= 50) && line[i] != ' ')
		{
			if (iscardino(&g->data, line + i, 1) != -1)
			{
				g->player.view = line[i];
				g->player.nb++;
				if (g->player.nb == 1)
				{	
					g->player.x = (float)i;
					g->player.y = (float)g->map.line;
				}
				else if (g->player.nb >= 2)
					ft_err(20);
				line[i] = '0';
			}
		}
	}
	if (g->map.collumn < i)
		g->map.collumn = i;
	printf("%s\n", line);
	g->map.map = ft_strsjoin(g->map.map, line);
	g->map.line++;
}

int	ft_read_file(int fd, t_g *g)
{
	char	*line;

	line = NULL;
	if (fd < 0)
		ft_err(2);
	while (get_next_line(fd, &line))
	{
		skip_space_eol(line);
		if (ft_isalpha(line[0]))
			ft_complet_data(g, line);
		else if (ft_isdigit(line[0]) || line[0] == ' ')
			ft_complet_map(g, line);
	}
	return (0);
}
