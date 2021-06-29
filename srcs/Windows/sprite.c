/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:20:23 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/29 18:47:38 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_sprite2(t_g *g)
{
	g->sprite.start_draw_x = -g->sprite.sprite_w / 2
		+ g->sprite.screen_x;
	if (g->sprite.start_draw_x < 0)
		g->sprite.start_draw_x = 0;
	g->sprite.end_draw_x = g->sprite.sprite_w / 2
		+ g->sprite.screen_x;
	if (g->sprite.end_draw_x >= g->win.w)
		g->sprite.end_draw_x = g->win.w - 1;
}

static void	ft_init_sprite(t_g *g, t_ray *r)
{
	g->sprite.sprite_x = g->lst->x - r->posX;
	g->sprite.sprite_y = g->lst->y - r->posY;
	g->sprite.invdet = 1.0 / (r->planeX * r->dirY - r->dirX * r->planeY);
	g->sprite.transform_x = g->sprite.invdet
		* (r->dirY * g->sprite.sprite_x - r->dirX * g->sprite.sprite_y);
	g->sprite.transform_y = g->sprite.invdet
		* (-r->planeY * g->sprite.sprite_x + r->planeX * g->sprite.sprite_y);
	g->sprite.screen_x = (int)((g->win.w / 2)
			* (1 + g->sprite.transform_x / g->sprite.transform_y));
	g->sprite.sprite_h = abs((int)(g->win.h / g->sprite.transform_y));
	g->sprite.start_draw_y = -g->sprite.sprite_h / 2 + g->win.h / 2;
	if (g->sprite.start_draw_y < 0)
		g->sprite.start_draw_y = 0;
	g->sprite.end_draw_y = g->sprite.sprite_h / 2 + g->win.h / 2;
	if (g->sprite.end_draw_y >= g->win.h)
		g->sprite.end_draw_y = g->win.h - 1;
	g->sprite.sprite_w = abs((int)(g->win.h / g->sprite.transform_y));
	ft_init_sprite2(g);
}

static void	ft_draw_pix_sprite(t_g *g, t_img *sprt, int startY, int startX)
{
	int	color;

	color = 0;
	g->sprite.d = (startY) * 256 - g->win.h * 128
		+ g->sprite.sprite_h * 128;
	g->sprite.text_y = ((g->sprite.d * g->tex.text_height)
			/ g->sprite.sprite_h) / 256;
	if (g->lst->id == 2)
		color = sprt->addr[sprt->h * g->sprite.text_y + g->sprite.text_x];
	if ((color & 0x00FFFFFF) != 0)
		my_pixel_put(&g->win, startX, startY, color);
}

static int	ft_texx(t_g *g, t_texture *t, int startX)
{
	int	ret;

	ret = (int)(256 * (startX - (-g->sprite.sprite_w / 2
					+ g->sprite.screen_x)) * t->text_width
			/ g->sprite.sprite_w) / 256;
	return (ret);
}
 void	draw_sprite(t_g *g, t_ray *ray, t_texture *t)
{
	int				startY;
	int				startX;
	t_lst			*fst;

	fst = g->lst;
	while (g->lst)
	{
		ft_init_sprite(g, ray);
		startX = g->sprite.start_draw_x - 1;
		while (++startX < g->sprite.end_draw_x)
		{
			g->sprite.text_x = ft_texx(g, t, startX);
			startY = g->sprite.start_draw_y - 1;
			if (g->sprite.transform_y > 0 && startX > 0
				&& startX < g->win.w
				&& g->sprite.transform_y < g->zbuffer[startX])
				while (++startY < g->sprite.end_draw_y)
				{
					if (g->time < 5)
						ft_draw_pix_sprite(g, &t->sprite[0], startY, startX);
					else
						ft_draw_pix_sprite(g, &t->sprite[1], startY, startX);
				}
		}
		g->lst = g->lst->next;
	}
	g->lst = fst;
}