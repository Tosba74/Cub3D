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

void	ft_print_struct_p(t_g g)
{
	printf("*-----------------------------------------------*\n");
	printf("| ---------------  DATA  ---------------------- |\n");
	printf("*-----------------------------------------------*\n");
	printf("|%8s == [%-4d]                             |\n", "weight", g.data.w);
	printf("|%8s == [%-4d]                             |\n", "height", g.data.h);
	printf("|%8s == [%-32s] |\n", g.data.cardino[0][0], g.data.cardino[1][0]);
	printf("|%8s == [%-32s] |\n", g.data.cardino[0][1], g.data.cardino[1][1]);
	printf("|%8s == [%-32s] |\n", g.data.cardino[0][2], g.data.cardino[1][2]);
	printf("|%8s == [%-32s] |\n", g.data.cardino[0][3], g.data.cardino[1][3]);
	printf("|%8s == [%-32s] |\n", g.data.cardino[0][4], g.data.cardino[1][4]);
	printf("|%8s == [%-32s] |\n", "sprite", g.data.sprite);
	printf("|%8s == [%3d] [%3d] [%3d]                  |\n", "floor",
		g.data.f[0], g.data.f[1], g.data.f[2]);
	printf("|%8s == [%3d] [%3d] [%3d]                  |\n", "color",
		g.data.c[0], g.data.c[1], g.data.c[2]);
	printf("|%8s == [%7d]                          |\n", "floor", g.data.floor);
	printf("|%8s == [%7d]                          |\n", "ceiling",
		g.data.ceiling);
	printf("*-----------------------------------------------*\n\n");
}

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
	printf("\n");
	while (g.map.map[++t])
	{
		printf("%s\n", g.map.map[t]);
	}
	printf("\n*-----------------------------------------------*\n\n");
	return (0);
}

void	ft_print_img(t_g g)
{
	printf("*-----------------------------------------------*\n");
	printf("| --------------  IMAGES  --------------------- |\n");
	printf("*-----------------------------------------------*\n");
	printf("| ROAD =>NO => %-33s|\n", g.img_c.no.road);
	printf("| ROAD =>SO => %-33s|\n", g.img_c.so.road);
	printf("| ROAD =>EA => %-33s|\n", g.img_c.ea.road);
	printf("| ROAD =>WE => %-33s|\n", g.img_c.we.road);
	printf("| IMG_C=>NO => %-33p|\n", g.img_c.no.img);
	printf("| IMG_C=>SO => %-33p|\n", g.img_c.so.img);
	printf("| IMG_C=>EA => %-33p|\n", g.img_c.ea.img);
	printf("| IMG_C=>WE => %-33p|\n", g.img_c.we.img);
	printf("| COLORFLOOR=> %-33d|\n", g.img_c.floor);
	printf("| COLORCEIL => %-33d|\n", g.img_c.ceiling);
	printf("*-----------------------------------------------*\n");
}

void	test(t_g g)
{
	ft_print_struct_p(g);
	// ft_print_player(g);
	ft_print_img(g);
}
