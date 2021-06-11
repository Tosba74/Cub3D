/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/11 16:50:16 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
