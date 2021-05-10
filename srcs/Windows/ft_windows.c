/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:33:03 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/07 18:49:44bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
/*
static void print_carre(t_g *g, int x, int y, int color)
{
	int w = 0;
	int h = 0;
	while(h != 10)
	{
		w = 0;
		while(w != 10)
		{
			if (w == 0 || w == 9 || h == 0 || h == 9)
				my_pixel_put(g, x + w, y + h, 900000);
			else
				my_pixel_put(g, x + w, y + h, color);
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
				my_pixel_put(g, x + w, y + h, color);
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
		my_pixel_put(g, x, y + i++, color);
}

static void print_player(t_g *g, int x, int y, int color)
{
	int w = 0;
	int h = 0;
	(void)x; 
	(void)y;
	(void)g;
	(void)color;
	while(h != 6)
	{
		w = 0;
		while(w != 6)
		{
			my_pixel_put(g, x + w, y + h, color);
			w++;
		}
		h++;
	}
	print_view(g, x + (w / 2), y + (h / 2), color);
}
*/

void	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(19);
	// ft_putstr("FINISH !!!\n");
	// wrdestroy();
	// exit(1);
}

int     deal_key(int key, void *param)
{
	t_g *g = param;
	if (key == KEY_LEFT || key == KEY_A)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" <== %d\n", key);
		printf("-------------\n");
		return (MOV_LEFT);
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" ==> %d\n", key);
		printf("-------------\n");
		return (MOV_RIGHT);
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" vvv %d\n", key);
		printf("-------------\n");
		return (MOV_DOWN);
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" ^^^ %d\n", key);
		printf("-------------\n");
		return (MOV_UP);
	}
	else if (key == KEY_ESC)
	{
		printf("-------------");
		ft_putbytes(key);
		printf("<> %d\n", key);
		printf("-------------");
		close_window(g);
	}
	else if (key)
	{
		printf("-------------");
		ft_putbytes(key);
		printf("<> %d\n", key);
		printf("-------------");
	}
	return(0);   
}
/*
static int	update(t_g *g)
{
	int i = -1;
	int t = -1;
	int x = 10; 
	int y = 10;
	while (g->map.map[++t])
	{
		i = -1;
		x = 10;
		while (g->map.map[t][++i])
		{
			if (g->map.map[t][i] == '1')
			{       
				print_carre(g, x, y, 5197647);
			}
			else if (g->map.map[t][i] == '0')        
			{
				print_carrev(g, x, y, 16514295);
			}
			x += 10;
		}
		y += 10;
		print_player(g, (g->player.x * 10) + 2, (g->player.y * 10) + 12, 16066343);
	}
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->win.img, g->data.w, g->data.h);
	return (0);	
}

static void cmpbytes(void)
{
	ft_putnbr(MOV_RIGHT&MOV_LEFT);
	ft_putstr("=>");
	ft_putbytes(MOV_RIGHT&MOV_LEFT);
	ft_putchar('\n');
	// ft_putnbr(MOV_A|MOV_D);
	// ft_putstr("=>");
	// ft_putbytes(MOV_A|MOV_D);
	// ft_putchar('\n');
	ft_putnbr(MOV_UP&MOV_DOWN);
	ft_putstr("=>");
	ft_putbytes(MOV_UP&MOV_DOWN);
	ft_putchar('\n');
	// ft_putnbr(MOV_W|MOV_S);
	// ft_putstr("=>");
	// ft_putbytes(MOV_W|MOV_S);
	// ft_putchar('\n');
}

void	move(t_g *g)
{
	char	mov = 0;
    int 	dx;
    int 	dy;
    char    movx;
    char    movy;

    movx = mov & (MOV_LEFT | MOV_RIGHT);
    movy = mov & (MOV_DOWN | MOV_UP);
    if (movx == MOV_LEFT)
        dx = -SPEED;
    else if (movx == MOV_RIGHT)
        dx = SPEED;
    if (movy == MOV_DOWN)
        dy = SPEED;
    else if (movy == MOV_UP)
        dy = -SPEED;
    g->player.x += dx;
    g->player.y += dy;	
	mlx_key_hook(g->win.win_ptr, deal_key, &(g->player));
	// mlx_loop_hook(g->win.mlx_ptr, update, &(g));
}
*/
static void	proc_win(t_g *g)
{
	g->win.mlx_ptr = mlx_init();
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->data.w, g->data.h, "42");
	// g->win.addr = mlx_get_data_addr(g->win.img, &(g->win.bpp), &(g->win.line_length), &(g->win.endian));
	// cmpbytes();
	// move(g);
	mlx_key_hook(g->win.win_ptr, deal_key, g);
	// mlx_loop_hook(g->win.mlx_ptr, update, &(g));
	mlx_loop(g->win.mlx_ptr);
}

/*
static int	key_deal(int key, void *param)
{
	t_g *g = param;
	if (key == KEY_S || key == KEY_W || key == KEY_DOWN || key == KEY_UP)
		g->win.img = mlx_xpm_file_to_image(g->win.mlx_ptr, g->data.cardino[0][0], &(g->data.w), &(g->data.h));
	if (key == KEY_A || key == KEY_D || key == KEY_LEFT || key == KEY_RIGHT)
		g->win.img = mlx_xpm_file_to_image(g->win.mlx_ptr, g->data.cardino[1][0], &(g->data.w)+64, &(g->data.h)+64);
	// mlx_loop_hook(g->win.mlx_ptr, key_deal, g);
	return (0);
}

static void	proc_win(t_g *g)
{
	g->win.mlx_ptr = mlx_init();
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->data.w, g->data.h, "42");
	mlx_key_hook(g->win.win_ptr, key_deal, &(g));
	mlx_loop_hook(g->win.mlx_ptr, key_deal, g);
	// g->win.img = mlx_xpm_file_to_image(g->win.mlx_ptr, g->data.cardino[0][0], &(g->data.w), &(g->data.h));
	// g->win.img += mlx_xpm_file_to_image(g->win.mlx_ptr, g->data.cardino[1][0], &(g->data.w)+64, &(g->data.h)+64);
	g->win.addr = (int *)mlx_get_data_addr(g->win.img, &(g->win.bpp), &(g->win.line_length), &(g->win.endian));
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->win.img, 64, 64);
	mlx_loop(g->win.mlx_ptr);
}
*/

void	new_win(t_g *tg)
{
	proc_win(tg);
}
