/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/12 12:27:15 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_flood_map(t_map *map, int x, int y)
{
	if (y < 0 || x < 0 || y > map->line - 1 || x > map->collumn)
		ft_err(8);
	if (!ft_isinstr("012", map->map[y][x]))
		ft_err(9);
	else if (map->map[y][x] == ' ')
		ft_err(10);
	else if (map->map[y][x] == '1')
		return ;
	// else if (map->map[y][x] == '0')
		// map->map[y][x] = '1';
	fill_flood_map(map, y - 1, x);
	fill_flood_map(map, y + 1, x);
	fill_flood_map(map, y, x - 1);
	fill_flood_map(map, y, x + 1);
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
