/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:20:23 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/19 14:54:31 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprite2(t_sprite *sprite, t_win win)
{
	sprite->drawStartX = -sprite->spriteWidth / 2
		+ sprite->spriteScreenX;
	if (sprite->drawStartX < 0)
		sprite->drawStartX = 0;
	printf("drawstartX = %d", sprite->drawStartX);
	sprite->drawEndX = sprite->spriteWidth / 2
		+ sprite->spriteScreenX;
	if (sprite->drawEndX >= win.w)
		sprite->drawEndX = win.w - 1;
	printf("drawEndX = %d", sprite->drawEndX );
}

static void	init_sprite(t_sprite *sprite, t_win win, t_ray ray)
{
	sprite->spriteX = sprite->lst->x - ray.posX;
	sprite->spriteY = sprite->lst->y - ray.posY;
	printf("spriteX-Y = %f || %f", sprite->spriteX, sprite->spriteY);
	sprite->invDet = 1.0 / (ray.planeX * ray.dirY - ray.dirX * ray.planeY);
	printf("invDet = %f", sprite->invDet);
	sprite->transformX = sprite->invDet * (ray.dirY * sprite->spriteX
		- ray.dirX * sprite->spriteY);
	sprite->transformY = sprite->invDet * (-ray.planeY * sprite->spriteX
		+ ray.planeX * sprite->spriteY);
	printf("transformX-Y = %f || %f", sprite->transformX, sprite->transformY);
	sprite->spriteScreenX = (int)((win.w / 2)
		* (1 + sprite->transformX / sprite->transformY));
	printf("spritescreenX = %d", sprite->spriteScreenX);
	sprite->spriteHeight = abs((int)(win.h / sprite->transformY));
	printf("spriteHeight = %d", sprite->spriteHeight);
	sprite->drawStartY = -sprite->spriteHeight / 2 + win.h / 2;
	if (sprite->drawStartY < 0)
		sprite->drawStartY = 0;
	printf("drawstartY = %d", sprite->drawStartY);
	sprite->drawEndY = sprite->spriteHeight / 2 + win.h / 2;
	if (sprite->drawEndY >= win.h)
		sprite->drawEndY = win.h - 1;
	printf("drawEndY = %d", sprite->drawEndY);
	sprite->spriteWidth = abs((int)(win.h / sprite->transformY));
	printf("spriteWidth = %d", sprite->spriteWidth);
	init_sprite2(sprite, win);
}

static void	draw_pix_sprite(t_g *g, t_texture *tex, int startY, int startX)
{
	// int	color;

	// color = 0;
	// g->sprite.d = (startY) * 256 - g->win.h * 128
	// 	+ g->sprite.spriteHeight * 128;
	// g->sprite.texY = ((g->sprite.d * tex->texHeight)
	// 		/ g->sprite.spriteHeight) / 256;
	// color = tex->sprite.addr[tex->sprite.h
	// 	* g->sprite.texY + g->sprite.texX];
		int	color;

	color = 0;
	g->sprite.d = (startY) * 256 - g->win.h * 128
		+ g->sprite.spriteHeight * 128;
	g->sprite.texY = ((g->sprite.d * tex->texHeight)
			/ g->sprite.spriteHeight) / 256;
	if (g->sprite.lst->id == 2)
		color = tex->sprite.addr[tex->sprite.h
			* g->sprite.texY + g->sprite.texX];
	// else if (g->sprite.lst->id == 3)
	// 	color = tex->sprite.addr[tex->sprite.h
	// 		* g->sprite.texY + g->sprite.texX];
	if ((color & 0x00FFFFFF) != 0 && g->sprite.lst->id != 2)
		my_pixel_put(&g->win, startX, startY, color);
}

static int	texx(t_g *g, t_texture *tex, int startX)
{
	int	ret;

	ret = (int)(256 * (startX - (-g->sprite.spriteWidth / 2
					+ g->sprite.spriteScreenX)) * tex->texWidth
			/ g->sprite.spriteWidth) / 256;
	return (ret);
}

void	draw_sprite(t_g *g)
{
	int			startY;
	int			startX;
	t_lst		*lst;

	lst = g->sprite.lst;
	while (g->sprite.lst)
	{
		init_sprite(&g->sprite, g->win, g->ray);
		startX = g->sprite.drawStartX - 1;
		while (++startX < g->sprite.drawEndX)
		{
			g->sprite.texX = texx(g, &g->tex, startX);
			startY = g->sprite.drawStartY - 1;
			if (g->sprite.transformY > 0 && startX > 0 && startX < g->win.w
				&& g->sprite.transformY < g->zbuffer[startX])
				while (++startY < g->sprite.drawEndY)
					draw_pix_sprite(g, &g->tex, startY, startX);
		}
		g->sprite.lst = g->sprite.lst->next;
	}
	g->sprite.lst = lst;
}
