/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:33:12 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/14 00:05:43 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*msg_err(int i)
{
	static char	*tab[21];

	tab[0] = "Cub3d need an argument\nLa map Connard\n";
	tab[1] = "Too many arguments\n";
	tab[2] = "There are problem while opening .cub file\n";
	tab[3] = "Incorrect Resolution\n";
	tab[4] = "Resolution Too Many Argument\n";
	tab[5] = "Texture's files incorrect\n";
	tab[6] = "Color incorrect\n";
	tab[7] = "Too many players";
	tab[8] = "Map must be close !!!\n";
	tab[9] = "FINISH !!!\n";
	return (tab[i]);
}

void	ft_err(int err)
{
	char	*str_err;

	str_err = msg_err(err);
	ft_putstr("Error: ");
	ft_putstr(str_err);
	wrdestroy();
	exit(1);
}

static void	ft_read_file(int fd, t_g *g)
{
	char	*line;

	line = NULL;
	if (fd < 0)
		ft_err(2);
	while (get_next_line(fd, &line))
	{
		skip_space_eol(line);
		printf("|%s|\n", line);
		if (ft_isalpha(line[0]))
			ft_complet_data(g, line);
		else if (ft_isdigit(line[0]) || line[0] == ' ')
			ft_complet_map(g, line);
	}
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
	mlx_loop_hook(g->win.mlx_ptr, update, g);
	mlx_loop(g->win.mlx_ptr);
}

int	main(int ac, char **av)
{
	int		fd;
	t_g		tg;

	if (ac == 1)
		ft_err(0);
	else if (ac == 2)
	{
		tg = (t_g){};
		ft_init_global(&tg);
		test(tg);
		fd = open(av[1], O_RDWR);
		ft_read_file(fd, &tg);
		test(tg);
		proc_win(&tg);
		wrdestroy();
		close (fd);
	}
	else
		ft_err(1);
	return (0);
}