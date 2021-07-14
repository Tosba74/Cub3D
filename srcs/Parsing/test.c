/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:50:17 by bmangin           #+#    #+#             */
/*   Updated: 2021/04/30 14:42:53by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_cardino(t_img img, char *str)
{
	printf("| -- TEXTURE -- %4s -- INFO --  ---------------|\n", str);
	printf("*-----------------------------------------------*\n");
	printf("| ROAD => %-38s|\n", img.road);
	printf("| IMG => %-39p|\n", img.img);
	printf("| ADDR => %-38s|\n", (char *)img.addr);
	printf("| W => %-17d |H => %-17d|\n", img.w, img.h);
	printf("| ENDIAN => [%-3d] BYTES => [%-3d] SIZE => [%-3d]  |\n", img.endian,
		img.bytes, img.sizeline);
	printf("*-----------------------------------------------*\n");
}

void	ft_print_img(t_g g)
{
	printf("*-----------------------------------------------*\n");
	printf("| --------------  IMAGES  --------------------- |\n");
	printf("*-----------------------------------------------*\n");
	ft_print_cardino(g.tex.cardino[0], "NORD");
	ft_print_cardino(g.tex.cardino[1], "SUD");
	ft_print_cardino(g.tex.cardino[2], "EST");
	ft_print_cardino(g.tex.cardino[3], "WEST");
	ft_print_cardino(g.tex.sprite[0], "SPRITE1");
	ft_print_cardino(g.tex.sprite[1], "SPRITE2");
	printf("| Wall_X   	=> %-29f|\n", g.tex.wallX);
	printf("| Step     	=> %-29f|\n", g.tex.step);
	printf("| text_pos   	=> %-29f|\n", g.tex.text_pos);
	printf("| text_width	=> %-29d|\n", g.tex.text_width);
	printf("| text_height	=> %-29d|\n", g.tex.text_height);
	printf("| text_num	=> %-29d|\n", g.tex.text_num);
	printf("| text_x	=> %-29d|\n", g.tex.text_x);
	printf("| text_y	=> %-29d|\n", g.tex.text_y);
	printf("| COLORFLOOR	=> %-29d|\n", g.tex.floor);
	printf("| COLORCEIL 	=> %-29d|\n", g.tex.ceiling);
}

void	ft_print_map(t_g g)
{
	int	t;

	t = -1;
	if (g.map.map == NULL)
		printf("LA MAP est Vide !!!\n");
	printf("*-----------------------------------------------*\n");
	printf("| ----------  MAP -- %4d x %4d  ------------- |\n",
		g.map.line + 1, g.map.collumn + 1);
	printf("*-----------------------------------------------*\n");
	printf("\n");
	printf("*-----------------------------------------------*\n");
	printf("| %s | %19d | %-19d |\n", "R", g.win.w, g.win.h);
	printf("*-----------------------------------------------*\n");
	while (g.map.map[++t])
	{
		printf("|%6s%-35s%6s|\n", "", g.map.map[t], "");
	}
	printf("*-----------------------------------------------*\n");
	printf("| nb_player = %-34d|\n", g.map.nb_player);
	printf("| nb_sprite = %-34d|\n", g.map.nb_sprite);
	printf("*-----------------------------------------------*\n\n");
}

void	ft_print_ray(t_g g)
{

	printf("*-----------------------------------------------*\n");
	printf("| ------------ --  INFO RAY  -- --------------- |\n");
	printf("*-----------------------------------------------*\n");
	printf("| posX = %-41f|\n", g.ray.posX);
	printf("| posY = %-41f|\n", g.ray.posY);
	printf("| dirX = %-41f|\n", g.ray.dirX);
	printf("| dirY = %-41f|\n", g.ray.dirY);
	printf("| planeX = %-39f|\n", g.ray.planeX);
	printf("| planeY = %-39f|\n", g.ray.planeY);
	printf("| cameraX = %-38f|\n", g.ray.cameraX);
	printf("| rayDirX = %-38f|\n", g.ray.rayDirX);
	printf("| rayDirY = %-38f|\n", g.ray.rayDirY);
	printf("| sideDistX = %-37f|\n", g.ray.sideDistX);
	printf("| sideDistY = %-37f|\n", g.ray.sideDistY);
	printf("| deltaDistX = %-38f|\n", g.ray.deltaDistX);
	printf("| deltaDistY = %-38f|\n", g.ray.deltaDistY);
	printf("| perpWallDist = %-33f|\n", g.ray.perpWallDist);
	printf("| mapX = %-41d|\n", g.ray.mapX);
	printf("| mapY = %-41d|\n", g.ray.mapY);
	printf("| stepX = %-40d|\n", g.ray.stepX);
	printf("| stepY = %-40d|\n", g.ray.stepY);
	printf("| hit = %-42d|\n", g.ray.hit);
	printf("| side = %-41d|\n", g.ray.side);
	printf("| camera = %-40c|\n", g.ray.camera);
	printf("*-----------------------------------------------*\n");
}

void	test(t_g g)
{
	ft_print_ray(g);
	ft_print_img(g);
	ft_print_map(g);
}
