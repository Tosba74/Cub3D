/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:35:27 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/25 10:08:37 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mov_updown(t_g *g, int neg)
{
	int		mov;

	mov = SPEED * neg;
	if (!is_wall(*g, (int)(g->player.x), (int)(g->player.y + mov)))
		g->player.y += (SPEED * neg);
}

void	mov_lateral(t_g *g, int neg)
{
	int		mov;

	mov = SPEED * neg;
	if (!is_wall(*g, (int)(g->player.x + mov), (int)(g->player.y)))
		g->player.x += (SPEED * neg);
}

void	rot_view(t_g *g, int neg)
{
	g->player.dir++;
	neg = 0;
}
/*
int	move_player_straight(t_game *game, int signe, int *change)
{
	double	pos_x;
	double	pos_y;
	double	p_square_x;
	double	p_square_y;

	*change = 1;
	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	pos_x += signe * ONE_STEP * game->player.dir_x;
	pos_y += signe * ONE_STEP * game->player.dir_y;
	p_square_x = floor(pos_x);
	p_square_y = floor(pos_y);
	if (game->window.map[(int)p_square_x][(int)p_square_y] == 0 ||
		game->window.map[(int)p_square_x][(int)p_square_y] == 2)
	{
		game->player.pos_x = pos_x;
		game->player.pos_y = pos_y;
		game->player.p_square_x = p_square_x;
		game->player.p_square_y = p_square_y;
	}
	return (0);
}
int	turn_player(t_game *game, int signe, int *change)
{
	double	dir_x;
	double	dir_y;

	*change = 1;
	dir_x = game->player.dir_x;
	dir_y = game->player.dir_y;
	game->player.dir_x = dir_x * cos(signe * THETA) -
						dir_y * sin(signe * THETA);
	game->player.dir_y = dir_x * sin(signe * THETA) +
						dir_y * cos(signe * THETA);
	game->player.plane_x = game->player.dir_y;
	game->player.plane_y = -1 * game->player.dir_x;
	return (0);
}
*/