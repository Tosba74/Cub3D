/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:19:42 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/19 18:09:05 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_side_and_step(t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
	}
}

static void	init_ray(t_ray *ray, int w, int x)
{
	ray->cameraX = 2 * x / (float)(w) - 1;
	ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
	ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
	ray->mapX = (int)(ray->posX);
	ray->mapY = (int)(ray->posY);
	if (ray->rayDirY == 0)
		ray->deltaDistX = 0;
	else if (ray->rayDirX == 0)
		ray->deltaDistX = 1;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirX == 0)
		ray->deltaDistY = 0;
	else if (ray->rayDirY == 0)
		ray->deltaDistY = 1;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
	init_ray_side_and_step(ray);
}

static void	dda_xy(t_ray *ray)
{
	if (ray->sideDistX < ray->sideDistY)
	{
		ray->sideDistX += ray->deltaDistX;
		ray->mapX += ray->stepX;
		ray->side = 0;
	}
	else
	{
		ray->sideDistY += ray->deltaDistY;
		ray->mapY += ray->stepY;
		ray->side = 1;
	}
}

static void	add_sprite(t_sprite *sprite, t_ray ray, t_map map)
{
	if (!sprite->lst)
		sprite->lst = lst_new((float)ray.mapX + 0.5, (float)ray.mapY + 0.5,
				map.map[ray.mapY][ray.mapX] - '0');
	else if (!in_lst(sprite->lst, ray.mapX + 0.5, ray.mapY + 0.5))
		lstadd_frt(&sprite->lst, lst_new((float)ray.mapX + 0.5,
				(float)ray.mapY + 0.5, map.map[ray.mapY][ray.mapX] - '0'));
}

float	ft_dda(t_g *g, int x_win)
{
	init_ray(&g->ray, g->win.w, x_win);
	while (g->ray.hit == 0)
	{
		dda_xy(&g->ray);
		if (g->map.map[g->ray.mapY][g->ray.mapX] == '1')
			g->ray.hit = 1;
		if (g->map.map[g->ray.mapY][g->ray.mapX] == '2')
			add_sprite(&g->sprite, g->ray, g->map);
	}
	if (g->ray.side == 0)
		g->ray.perpWallDist = (g->ray.mapX - g->ray.posX
				+ (1 - g->ray.stepX) / 2) / g->ray.rayDirX;
	else
		g->ray.perpWallDist = (g->ray.mapY - g->ray.posY
				+ (1 - g->ray.stepY) / 2) / g->ray.rayDirY;
	g->zbuffer[x_win] = g->ray.perpWallDist;
	return (g->ray.perpWallDist);
}

// if (!g->sprite.lst)
	// g->sprite.lst = lst_new((float)g->ray.mapX + 0.5, (float)g->ray.mapY + 0.5, g->map.map[g->ray.mapY][g->ray.mapX] - '0');
// else if (!in_lst(g->sprite.lst, g->ray.mapX + 0.5,
		// g->ray.mapY + 0.5))
	// lstadd_frt(&g->sprite.lst, lst_new((float)g->ray.mapX + 0.5, (float)g->ray.mapY + 0.5, g->map.map[g->ray.mapY][g->ray.mapX] - '0'));