/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/16 19:47:01 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'x')
				map[y][x] = '0';
			else if (map[y][x] == '*')
				map[y][x] = '2';
		}
	}
}

void	map_flood_fill(char **map, int x, int y)
{
	if (x < 0 || x >= (int)ft_strlen(map[y])
		|| y < 0 || y >= ft_strslen(map) || map[y][x] == ' ')
		ft_err(10);
	if (map[y][x] == '0' || map[y][x] == '2')
	{
		if (map[y][x] == '0')
			map[y][x] = 'x';
		else if (map[y][x] == '2')
			map[y][x] = '*';
		map_flood_fill(map, x + 1, y);
		map_flood_fill(map, x - 1, y);
		map_flood_fill(map, x, y + 1);
		map_flood_fill(map, x, y - 1);
	}
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
	tab[0] = "NO ";
	tab[1] = "SO ";
	tab[2] = "WE ";
	tab[3] = "EA ";
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
