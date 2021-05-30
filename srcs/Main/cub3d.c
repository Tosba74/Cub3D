/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:09:39 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/29 22:53:13 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_read_file(int fd, t_g *g)
{
	char	*line;

	line = NULL;
	if (fd < 0)
		ft_err(2);
	while (get_next_line(fd, &line))
	{
		skip_space_eol(line);
		if (ft_isalpha(line[0]))
			ft_complet_data(g, line);
		else if (ft_isdigit(line[0]) || line[0] == ' ')
			ft_complet_map(g, line);
	}
	return (0);
}

void	ft_cub(int fd)
{
	int		bool;
	t_g		tg;

	tg = (t_g){};
	ft_init_global(&tg);
	test(tg);
	bool = ft_read_file(fd, &tg);
	printf("hein\n");
	if (bool)
		ft_putstr("Error\n");
	ft_print_struct_p(tg);
	// ft_print_player(tg);
	ft_print_map(tg);
	new_win(&tg);
}
