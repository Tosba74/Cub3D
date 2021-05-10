/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:33:12 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/05 23:01:34 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	if (ac ==1)
		ft_err(0);
	else if (ac == 2)
	{
		int fd;
		fd = open(av[1], O_RDWR);
		ft_cub(fd);
		wrdestroy();	
		close (fd);
	}
	else
		ft_err(1);
	return(0);
}