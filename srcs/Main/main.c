/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:33:12 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/11 21:27:31y bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*msg_err(int i)
{
	static char	*tab[12];

	tab[0] = "Cub3d need an argument\nLa map Connard\n";
	tab[1] = "Too many arguments\n";
	tab[2] = "There are problem while opening .cub file\n";
	tab[3] = "Incorrect Resolution\n";
	tab[4] = "Resolution Too Many Argument\n";
	tab[5] = "Texture's files incorrect\n";
	tab[6] = "Color incorrect\n";
	tab[7] = "Too many players";
	tab[8] = "Map -- Bad Format !!!\n";
	tab[9] = "Map -- Bad Caratere !!!\n";
	tab[10] = "Map isn't closed !!!\n";
	tab[11] = "You need position's player\n";
	return (tab[i]);
}

void	ft_err(int err)
{
	char	*str_err;

	str_err = msg_err(err);
	if (err == -1)
		ft_putstr("FINISH !!!\n");
	else
	{
		ft_putstr("Error: ");
		ft_putstr(str_err);
	}
	wrdestroy();
	exit(1);
}

static void	proc_win(t_g *g)
{
	mlx_get_screen_size(g->win.mlx_ptr, &g->win.w, &g->win.h);
	if (X_RES < g->win.w)
		g->win.w = X_RES;
	if (Y_RES < g->win.h)
		g->win.h = Y_RES;
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->win.w, g->win.h,
			"Cub3d");
	g->win.img = mlx_new_image(g->win.mlx_ptr, g->win.w, g->win.h);
	g->win.addr = (int *)mlx_get_data_addr(g->win.img, &(g->win.bpp),
			&(g->win.line_length), &(g->win.endian));
	get_texture(g);
	mlx_do_key_autorepeatoff(g->win.mlx_ptr);
	mlx_hook(g->win.win_ptr, 02, KeyPressMask, key_deal, g);
	mlx_hook(g->win.win_ptr, 03, KeyReleaseMask, key_death, g);
	mlx_hook(g->win.win_ptr, 17, 0, close_window, g);
	mlx_loop_hook(g->win.mlx_ptr, update, g);
	mlx_loop(g->win.mlx_ptr);
}

static void	read_file(int fd, t_g *g)
{
	char	*line;
	int		ret;

	line = NULL;
	if (fd < 0)
		ft_err(2);
	ret = get_next_line(fd, &line);
	while (ret != -1)
	{
		skip_space_eol(line);
		if (ft_isalpha(line[0]))
			ft_complet_data(g, line);
		else if (ft_isdigit(line[0]) || line[0] == ' ')
			ft_complet_map(g, line, fd, ret);
		else if (line[0] != 0)
			ft_err(-1);
		else
			wrfree(line);
		if (ret == 0)
			break;
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		ft_err(2);
}

int	main(int ac, char **av)
{
	int		fd;
	t_g		tg;

	if (ac == 2)
	{
		tg = (t_g){};
		ft_init_global(&tg);
		if (ft_check_ext(av[1], ".cub"))
			ft_err(2);
		fd = open(av[1], O_RDWR);
		read_file(fd, &tg);
		close(fd);
		map_flood_fill(tg.map.map, tg.ray.posX, tg.ray.posY);
		reset_map(tg.map.map);
		test(tg);
		if (tg.map.nb_player == 1)
			proc_win(&tg);
		else
			ft_err(11);
		wrdestroy();
	}
	else
		ft_err(0);
	return (0);
}
