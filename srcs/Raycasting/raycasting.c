/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:19:42 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/28 19:11:45 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void raycast(t_g *g)
// {
// 	t_vector	vector;
// 	float		pos_x;
// 	float		pos_y;

// 	vector = (t_vector) {.x = -1};
// 	pos_x = g->player.x;
// 	pos_y = g->player.y;
// }

static void	init_ray3(t_ray *var)
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

static void	init_ray2(t_ray *var)
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
	init_ray3(var);
}

static void	init_ray(t_ray *var, t_g *g, int x)
{
	var->posX = g->player.x;
	var->posY = g->player.y;
	var->dirX = g->player.dirX;
	var->dirY = g->player.dirY;
	var->planeX = g->player.planeX;
	var->planeY = g->player.planeY;
	var->cameraX = 2 * x / (double)(g->win.w) - 1;
	var->rayDirX = var->dirX + var->planeX * var->cameraX;
	var->rayDirY = var->dirY + var->planeY * var->cameraX;
	var->mapX = (int)(g->player.x);
	var->mapY = (int)(g->player.y);
	init_ray2(var);
}

static double	ft_dist(t_ray *v)
{
	if (v->side == 0)
		v->perpWallDist = (v->mapX - v->posX + (1 - v->stepX) / 2) / v->rayDirX;
	else
		v->perpWallDist = (v->mapY - v->posY + (1 - v->stepY) / 2) / v->rayDirY;
	return (v->perpWallDist);
}

float	ft_dda(t_g *g, int x_win, t_ray *var)
{
	init_ray(var, g, x_win);
	while (var->hit == 0)
	{
		if (var->sideDistX < var->sideDistY)
		{
			var->sideDistX += var->deltaDistX;
			var->mapX += var->stepX;
			var->side = 0;
		}
		else
		{
			var->sideDistY += var->deltaDistY;
			var->mapY += var->stepY;
			var->side = 1;
		}
		if (g->map.map[var->mapY][var->mapX] == '1')
			var->hit = 1;
	}
	g->player.side = var->side;
	return (ft_dist(var));
}
