/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:24:22 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/28 13:37:51 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	init_rc_var3(t_rc_var *var)
{
	if (var->rayDirX < 0)
	{
		var->stepX = -1;
		var->sideDistX = (var->posX - var->mapX) * var->deltaDistX;
	}
	else
	{
		var->stepX = 1;
		var->sideDistX = (var->mapX + 1.0 - var->posX) * var->deltaDistX;
	}
	if (var->rayDirY < 0)
	{
		var->stepY = -1;
		var->sideDistY = (var->posY - var->mapY) * var->deltaDistY;
	}
	else
	{
		var->stepY = 1;
		var->sideDistY = (var->mapY + 1.0 - var->posY) * var->deltaDistY;
	}
}

static void	init_rc_var2(t_rc_var *var)
{
	if (var->rayDirY == 0)
		var->deltaDistX = 0;
	else if (var->rayDirX == 0)
		var->deltaDistX = 1;
	else
		var->deltaDistX = fabs(1 / var->rayDirX);
	if (var->rayDirX == 0)
		var->deltaDistY = 0;
	else if (var->rayDirY == 0)
		var->deltaDistY = 1;
	else
		var->deltaDistY = fabs(1 / var->rayDirY);
	var->hit = 0;
	init_rc_var3(var);
}

static void	init_rc_var(t_rc_var *var, t_game *game, int x)
{
	var->posX = game->player.x;
	var->posY = game->player.y;
	var->dirX = game->player.dirX;
	var->dirY = game->player.dirY;
	var->planeX = game->player.planeX;
	var->planeY = game->player.planeY;
	var->cameraX = 2 * x / (float)(game->data.rx) - 1;
	var->rayDirX = var->dirX + var->planeX * var->cameraX;
	var->rayDirY = var->dirY + var->planeY * var->cameraX;
	var->mapX = (int)(game->player.x);
	var->mapY = (int)(game->player.y);
	init_rc_var2(var);
}

static float	ft_dist(t_rc_var *v, t_game *game, int x_win)
{
	if (v->side == 0)
		v->perpWallDist = (v->mapX
				- v->posX + (1 - v->stepX) / 2) / v->rayDirX;
	else
		v->perpWallDist = (v->mapY
				- v->posY + (1 - v->stepY) / 2) / v->rayDirY;
	game->player.side = v->side;
	game->zbuffer[x_win] = v->perpWallDist;
	return (v->perpWallDist);
}

float	ft_dda(t_game *game, int x_win, t_rc_var *var)
{
	init_rc_var(var, game, x_win);
	while (var->hit == 0)
	{
		if (var->sideDistX < var->sideDistY)
			ft_dda_x_inf_y(var);
		else
			ft_dda_x_sup_y(var);
		if (game->data.map[var->mapY][var->mapX] == '1' ||
			(game->data.map[var->mapY][var->mapX] == '4' && game->trip == 0))
			var->hit = 1;
		if (game->data.map[var->mapY][var->mapX] == '2' ||
			game->data.map[var->mapY][var->mapX] == '3')
		{
			if (game->lst_sprite == NULL)
				game->lst_sprite = ft_lst_new(var->mapX + 0.5, var->mapY + 0.5,
						game->data.map[var->mapY][var->mapX] - '0');
			else if (ft_in_lst(game->lst_sprite, var->mapX + 0.5,
					var->mapY + 0.5) == 0)
				ft_lstadd_frt(&game->lst_sprite, ft_lst_new(var->mapX + 0.5,
						var->mapY + 0.5,
						game->data.map[var->mapY][var->mapX] - '0'));
		}
	}
	return (ft_dist(var, game, x_win));
}
