/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:20:23 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/21 01:01:47 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprite2(t_sprite *sprite, t_win win, t_ray ray)
{
	(void)win;
	printf("%f|%f|%f\n", ray.posX, sprite->lst->x, sprite->sprite_x);
	sprite->sprite_x = sprite->lst->x - ray.posX;
	printf("%f|%f|%f\n", ray.posY, sprite->lst->y, sprite->sprite_y);
	sprite->sprite_y = sprite->lst->y - ray.posY;
	// sprite->invdet = 1.0 / (ray.planeX * ray.dirY - ray.dirX * ray.planeY);
	// sprite->transform_x = sprite->invdet * (ray.dirY * sprite->sprite_x
			// - ray.dirX * sprite->sprite_y);
	// sprite->transform_y = sprite->invdet * (-ray.planeY * sprite->sprite_x
			// + ray.planeX * sprite->sprite_y);
	// sprite->screen_x = (int)((win.w / 2)
			// * (1 + sprite->transform_x / sprite->transform_y));
	// sprite->sprite_h = abs((int)(win.h / sprite->transform_y));
	// sprite->start_draw_y = -sprite->sprite_h / 2 + win.h / 2;
	// if (sprite->start_draw_y < 0)
		// sprite->start_draw_y = 0;
	// sprite->end_draw_y = sprite->sprite_h / 2 + win.h / 2;
	// if (sprite->end_draw_y >= win.h)
		// sprite->end_draw_y = win.h - 1;
	// sprite->sprite_w = abs((int)(win.h / sprite->transform_y));
	// sprite->start_draw_x = -sprite->sprite_w / 2
		// + sprite->screen_x;
	// if (sprite->start_draw_x < 0)
		// sprite->start_draw_x = 0;
	// sprite->end_draw_x = sprite->sprite_w / 2
		// + sprite->screen_x;
	// if (sprite->end_draw_x >= win.w)
		// sprite->end_draw_x = win.w - 1;
}

static void	init_sprite(t_sprite *sprite, t_win win, t_ray ray)
{
	init_sprite2(sprite, win, ray);
	// sprite->sprite_x = sprite->lst->x - ray.posX;
	// sprite->sprite_y = sprite->lst->y - ray.posY;
	sprite->invdet = 1.0 / (ray.planeX * ray.dirY - ray.dirX * ray.planeY);
	sprite->transform_x = sprite->invdet * (ray.dirY * sprite->sprite_x
			- ray.dirX * sprite->sprite_y);
	sprite->transform_y = sprite->invdet * (-ray.planeY * sprite->sprite_x
			+ ray.planeX * sprite->sprite_y);
	sprite->screen_x = (int)((win.w / 2)
			* (1 + sprite->transform_x / sprite->transform_y));
	sprite->sprite_h = abs((int)(win.h / sprite->transform_y));
	sprite->start_draw_y = -sprite->sprite_h / 2 + win.h / 2;
	if (sprite->start_draw_y < 0)
		sprite->start_draw_y = 0;
	sprite->end_draw_y = sprite->sprite_h / 2 + win.h / 2;
	if (sprite->end_draw_y >= win.h)
		sprite->end_draw_y = win.h - 1;
	sprite->sprite_w = abs((int)(win.h / sprite->transform_y));
	sprite->start_draw_x = -sprite->sprite_w / 2
		+ sprite->screen_x;
	if (sprite->start_draw_x < 0)
		sprite->start_draw_x = 0;
	sprite->end_draw_x = sprite->sprite_w / 2
		+ sprite->screen_x;
	if (sprite->end_draw_x >= win.w)
		sprite->end_draw_x = win.w - 1;
	// init_sprite2(sprite, win, ray);
}

static void	draw_pix_sprite(t_g *g, t_texture *tex, int startY, int startX)
{
	int	color;

	color = 0;
	g->sprite.d = (startY) * 256 - g->win.h * 128
		+ g->sprite.sprite_h * 128;
	g->sprite.text_y = ((g->sprite.d * tex->text_height)
			/ g->sprite.sprite_h) / 256;
	if (g->sprite.lst->id == 2)
		color = tex->sprite.addr[tex->sprite.h
			* g->sprite.text_y + g->sprite.text_x];
	if ((color & 0x00FFFFFF) != 0 && g->sprite.lst->id != 2)
		my_pixel_put(&g->win, startX, startY, color);
}

static int	text_x(t_g *g, t_texture *tex, int startX)
{
	int	ret;

	ret = (int)(256 * (startX - (-g->sprite.sprite_w / 2
					+ g->sprite.screen_x)) * tex->text_width
			/ g->sprite.sprite_w) / 256;
	return (ret);
}

void	draw_sprite(t_g *g)
{
	int		startY;
	int		startX;
	t_lst	*lst;

	lst = g->sprite.lst;
	while (g->sprite.lst)
	{
		init_sprite(&g->sprite, g->win, g->ray);
		// ft_print_img(*g);
		startX = g->sprite.start_draw_x - 1;
		while (++startX < g->sprite.end_draw_x)
		{
			g->sprite.text_x = text_x(g, &g->tex, startX);
			startY = g->sprite.start_draw_y - 1;
			if (g->sprite.transform_y > 0 && startX > 0 && startX < g->win.w
				&& g->sprite.transform_y < g->zbuffer[startX])
				while (++startY < g->sprite.end_draw_y)
					draw_pix_sprite(g, &g->tex, startY, startX);
		}
		g->sprite.lst = g->sprite.lst->next;
	}
	g->sprite.lst = lst;
}

// static void	draw_pix_sprite(t_g *g, t_texture *tex, int startY, int startX)
// {
	// int	color;

	// color = 0;
	// g->sprite.d = (startY) * 256 - g->win.h * 128
	// 	+ g->sprite.sprite_h * 128;
	// g->sprite.text_y = ((g->sprite.d * tex->text_height)
	// 		/ g->sprite.sprite_h) / 256;
	// color = tex->sprite.addr[tex->sprite.h
	// 	* g->sprite.text_y + g->sprite.text_x];
	// else if (g->sprite.lst->id == 3)
	// 	color = tex->sprite.addr[tex->sprite.h
	// 		* g->sprite.text_y + g->sprite.text_x];
// }
