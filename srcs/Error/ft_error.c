/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:46:46 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/20 17:46:06 by bmangin          ###   ########lyon.fr   */
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
	tab[7] = "";
	tab[8] = "";
	tab[9] = "";
	tab[10] = "";
	tab[11] = "";
	tab[12] = "";
	tab[13] = "";
	tab[14] = "";
	tab[15] = "";
	tab[16] = "";
	tab[17] = "";
	tab[18] = "";
	tab[19] = "FINISH !!!\n";
	tab[20] = "Too many players";
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
