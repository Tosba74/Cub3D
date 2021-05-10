/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:33:03 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/07 13:43:48 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// int     deal_key(int key, void *param)
// {
// 	// t_player *p = param;
// 	// (void)p;
// 	if (key == KEY_LEFT || key == KEY_A)
// 	{
// 		// param->x -= 0.1;
// 		printf("<== %d\n", key);
// 	}
// 	else if (key == KEY_RIGHT || key == KEY_D)
// 	{
// 		// param->x += 0.1;
// 		printf("==> %d\n", key);
// 	}
// 	else if (key == KEY_DOWN || key == KEY_S)
// 	{
// 		// param->y -= 0.1;
// 		printf("vvv %d\n", key);
// 	}
// 	else if (key == KEY_UP || key == KEY_W)
// 	{
// 		// param->y += 0.1;
// 		printf("^^^ %d\n", key);
// 	}
// 	else if (key)
// 	{
// 		printf("%d\n", key);
// 	}
// 	(void)param;
// 	return(0);   
// }

static void print_carre(t_g *g, int x, int y, int color)
{
	int w = 0;
	int h = 0;
	while(h != 10)
	{
		w = 0;
		while(w != 10)
		{
			// if ((h = 1 && (1 <= w && w <= 8 )) || (w = 9 && (2 <= h && h <= 9)))
			// 	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + w, y + h, 0);
			// else
			if (w == 0 || w == 9 || h == 0 || h == 9)
				mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x + w, y + h, 900000);
			else
				mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x + w, y + h, color);
			w++;
		}
		h++;
	}
}

static void print_carrev(t_g *g, int x, int y, int color)
{
	int w = 0;
	int h = 0;
	while(h != 10)
	{
		w = 0;
		while(w != 10)
		{
			if (w == 0 || w == 9 || h == 0 || h == 9)
				mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x + w, y + h, color);
			w++;
		}
		h++;
	}
}

static void print_view(t_g *g, int x, int y, int color)
{
	int i;

	i = 0;
	while (i != 20)
		mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x, y + i++, color);
}

static void print_player(t_g *g, int x, int y, int color)
{
	int w = 0;
	int h = 0;
	while(h != 6)
	{
		w = 0;
		while(w != 6)
		{
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, x + w, y + h, color);
			w++;
		}
		h++;
	}
	print_view(g, x + (w / 2), y + (h / 2), color);
	/*
	if (g->player.view == 'N')
	{
		while (h != -50 && w != 50)    
		{
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + w++, (y + 5) + h, 16712455);
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + -w, (y + 5) + h--, 16712455);
		}
	}
	else if (g->player.view == 'S')
	{
		while (h != 50 && w != 50)    
		{
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + w++, (y + 5) + h, 16712455);
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + -w, (y + 5) + h++, 16712455);
		}
	}
	else if (g->player.view == 'W')
	{
		while (h != 50 && w != -50)    
		{
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + w, (y + 5) + h++, 16712455);
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + w--, (y + 5) + -h, 16712455);
		}
	}
	else if (g->player.view == 'E')
	{
		while (h != 50 && w != 50)    
		{
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + w, (y + 5) + h++, 16712455);
			mlx_pixel_put(g->win.mlx_ptr, g->win.win_ptr, (x + 5) + w++, (y + 5) + -h, 16712455);
		}
	}
	*/
}

static void	proc_win(t_g *g)
{
	// int size;
	int i = -1;
	int t = -1;
	int x = 10; 
	int y = 10;

	// char *pix;
	g->win.mlx_ptr = mlx_init();
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->data.w, g->data.h, "42");
	// size = mlx_get_screen_size(g->win.mlx_ptr, &g->data.w, &g->data.h);
	// printf("size_screen => %d\n", size);
	while (g->map.map[++t])
	{
		i = -1;
		x = 10;
		while (g->map.map[t][++i])
		{
			if (g->map.map[t][i] == '1')        
				print_carre(g, x, y, 5197647);
			else if (g->map.map[t][i] == '0')        
				print_carrev(g, x, y, 16514295);
			x += 10;
		}
		y += 10;
		print_player(g, (g->player.x * 10) + 2, (g->player.y * 10) + 12, 16066343);
	}
	// img = mlx_png_file_to_image(g->win.mlx_ptr, param.no, (int *)64, (int *)64);
	// printf("%s", img);
	// if (img)
	//     mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, img, 64, 64);
	// else 
	//     printf("TON IMG EST NULL CONNARD!!!\n");
	// pix = mlx_get_data_addr(g->win.mlx_ptr, &g->win.bpp, &g->win.line_length, 0);
	// ft_putstr(pix);
	// mlx_key_hook(g->win.mlx_ptr, deal_key, (void *)0);
	mlx_loop(g->win.mlx_ptr);
}

void	new_win(t_g *tg)
{
	proc_win(tg);
	// print_pict(&win, *param);
}

// t_image		open_image(void *mlx_ptr, char *img_path, int width, int height)
// {
// 	t_image	t_img;
// 	int		p;
// 	int		e;
// 	int		*img_c;

// 	if (!width)
// 		t_img.x_i = width;
// 	if (!height)
// 		t_img.y_i = height;
// 	if (!(t_img.image = mlx_xpm_file_to_image(mlx_ptr, img_path,
// 					&t_img.x_i, &t_img.y_i)))
// 		return (t_img);
// 	img_c = (int*)mlx_get_data_addr(t_img.image, &p, &t_img.line_bytes, &e);
// 	t_img.p_color = img_c;
// 	return (t_img);
// }