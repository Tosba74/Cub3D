/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/23 14:07:46 by bmangin          ###   ########lyon.fr   */
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


int	is_wall(t_g g, int x, int y)
{
	if (g.map.map[x][y] == '0')
		return (0);
	else
		return (1);
}
