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

// void	ft_print_struct_p(t_g g)
// {
// 	printf("*-----------------------------------------------*\n");
// 	printf("| ---------------  DATA  ---------------------- |\n");
// 	printf("*-----------------------------------------------*\n");
// 	printf("|%8s == [%-4d]                             |\n", "weight", g.data.w);
// 	printf("|%8s == [%-4d]                             |\n", "height", g.data.h);
// 	printf("|%8s == [%-32s] |\n", g.data.cardino[0][0], g.data.cardino[1][0]);
// 	printf("|%8s == [%-32s] |\n", g.data.cardino[0][1], g.data.cardino[1][1]);
// 	printf("|%8s == [%-32s] |\n", g.data.cardino[0][2], g.data.cardino[1][2]);
// 	printf("|%8s == [%-32s] |\n", g.data.cardino[0][3], g.data.cardino[1][3]);
// 	printf("|%8s == [%-32s] |\n", g.data.cardino[0][4], g.data.cardino[1][4]);
// 	printf("|%8s == [%-32s] |\n", "sprite", g.data.sprite);
// 	printf("|%8s == [%3d] [%3d] [%3d]                  |\n", "floor",
// 		g.data.f[0], g.data.f[1], g.data.f[2]);
// 	printf("|%8s == [%3d] [%3d] [%3d]                  |\n", "color",
// 		g.data.c[0], g.data.c[1], g.data.c[2]);
// 	printf("|%8s == [%7d]                          |\n", "floor", g.data.floor);
// 	printf("|%8s == [%7d]                          |\n", "ceiling",
// 		g.data.ceiling);
// 	printf("*-----------------------------------------------*\n\n");
// }

// void	ft_print_player(t_g g)
// {
// 	printf("*-----------------------------------------------*\n");
// 	printf("| --------------  PLAYER  --------------------- |\n");
// 	printf("*-----------------------------------------------*\n");
// 	printf("| NB PLAYER => %-33d|\n", g.player.nb);
// 	printf("| View PLAYER ONE => %-27c|\n", g.player.view);
// 	printf("| Pos X => %-12f Pos Y => %-14f |\n", g.player.x, g.player.y);
// 	printf("*-----------------------------------------------*\n");
// }

int	ft_print_map(t_g g)
{
	int	t;

	t = -1;
	if (g.map.map == NULL)
		return (1);
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
	printf("*-----------------------------------------------*\n\n");
	return (0);
}

void	ft_print_cardino(t_img img)
{
	printf("| ROAD => %-38s|\n", img.road);
	printf("| IMG => %-39p|\n", img.img);
	printf("| ADDR => %-38s|\n", (char *)img.addr);
	printf("| W => %-17d |H => %-17d|\n", img.w, img.h);
	printf("| ENDIAN => [%-3d] BYTES => [%-3d] SIZE => [%-3d]  |\n", img.endian,
		img.bytes, img.sizeline);

}

void	ft_print_img(t_g g)
{
	printf("*-----------------------------------------------*\n");
	printf("| --------------  IMAGES  --------------------- |\n");
	printf("*-----------------------------------------------*\n");
	printf("| -- CARDINO -- NORD -- INFO --  ---------------|\n");
	printf("*-----------------------------------------------*\n");
	ft_print_cardino(g.tex.cardino[0]);
	printf("*-----------------------------------------------*\n");
	printf("| -- CARDINO -- SUD -- INFO --  ----------------|\n");
	printf("*-----------------------------------------------*\n");
	ft_print_cardino(g.tex.cardino[1]);
	printf("*-----------------------------------------------*\n");
	printf("| -- CARDINO -- EST -- INFO --  ----------------|\n");
	printf("*-----------------------------------------------*\n");
	ft_print_cardino(g.tex.cardino[2]);
	printf("*-----------------------------------------------*\n");
	printf("| -- CARDINO -- WEST -- INFO --  ---------------|\n");
	printf("*-----------------------------------------------*\n");
	ft_print_cardino(g.tex.cardino[3]);
	printf("*-----------------------------------------------*\n");
	printf("* SPRITE -- INFO --   --------------------------*\n");
	printf("*-----------------------------------------------*\n");
	ft_print_cardino(g.tex.sprite);
	printf("*-----------------------------------------------*\n");
	printf("| -------------  INFO TEX  -------------------- |\n");
	printf("*-----------------------------------------------*\n");
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
	printf("*-----------------------------------------------*\n");
	printf("| -------------  INFO SPRITE  ----------------- |\n");
	printf("*-----------------------------------------------*\n");
	printf("| sprite_x => %-34f|\n", g.sprite.sprite_x);
	printf("| sprite_y => %-34f|\n", g.sprite.sprite_y);
	printf("| Invdet => %-36f|\n", g.sprite.invdet);
	printf("| TransfX => %-35f|\n", g.sprite.transform_x);
	printf("| TransfY => %-35f|\n", g.sprite.transform_y);
	printf("| spriteW => %-35d|\n", g.sprite.sprite_w);
	printf("| spriteH => %-35d|\n", g.sprite.sprite_h);
	printf("| sreenX => %-36d|\n", g.sprite.screen_x);
	printf("| Draw_SX => %-35d|\n", g.sprite.start_draw_x);
	printf("| Draw_SY => %-35d|\n", g.sprite.start_draw_y);
	printf("| Draw_EX => %-35d|\n", g.sprite.end_draw_x);
	printf("| Draw_EY => %-35d|\n", g.sprite.end_draw_y);
	printf("| TextX => %-37d|\n", g.sprite.text_x);
	printf("| TextY => %-37d|\n", g.sprite.text_y);
	printf("| D => %-41d|\n", g.sprite.d);
	printf("*-----------------------------------------------*\n");
}

void	test(t_g g)
{
	// ft_print_struct_p(g);
	// ft_print_player(g);
	ft_print_img(g);
	ft_print_map(g);
}
