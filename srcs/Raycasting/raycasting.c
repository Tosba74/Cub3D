/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:19:42 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/29 22:52:38 by bmangin          ###   ########lyon.fr   */
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

static void	init_ray_delta(t_ray *ray)
{
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
}

static void	init_ray(t_ray *ray, t_g *g, int x)
{
	ray->cameraX = 2 * x / (float)(g->win.w) - 1;
	ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
	ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
	ray->mapX = (int)(g->ray.posX);
	ray->mapY = (int)(g->ray.posY);
	init_ray_delta(ray);
	init_ray_side_and_step(ray);
}

static double	ft_dist(t_ray *r)
{
	if (r->side == 0)
		r->perpWallDist = (r->mapX - r->posX + (1 - r->stepX) / 2) / r->rayDirX;
	else
		r->perpWallDist = (r->mapY - r->posY + (1 - r->stepY) / 2) / r->rayDirY;
	return (r->perpWallDist);
}

float	ft_dda(t_g *g, int x_win, t_ray *ray)
{
	init_ray(ray, g, x_win);
	while (ray->hit == 0)
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
		if (g->map.map[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
	}
	g->ray.side = ray->side;
	return (ft_dist(ray));
}
