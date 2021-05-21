/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:09:33 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/21 17:16:51 by bmangin          ###   ########lyon.fr   */
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

// void	my_pixel_put(t_g *g, int x, int y, int color)
// {
// 	//mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x, y, color);
// 	g->win.addr[(y * g->win.w) + x] = color;
// }
// void	my_pixel_put(t_g *g, int x, int y, int color)
// {
// 	int	*dst;

// 	*dst = (int*)g->win.addr + (y * g->win.line_length + x * (g->win.bpp / 8));
// 	*dst = color;
// }

void	my_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;
	// printf("add = %p, line_len = %d, bpp = %d\n", win->addr, win->line_length, win->bpp);
	// // exit(1);
	// win->addr[(y * win->w) + x] = color;
	dst = (char*)win->addr + (y * win->line_length + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}


int		is_wall(t_g g, int x, int y)
{
	if (g.map.map[x][y] == '0')
		return(0);
	else
		return (1);
}

