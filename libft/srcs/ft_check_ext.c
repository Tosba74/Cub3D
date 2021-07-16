/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:40:20 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/16 19:41:53 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_ext(char *s, char *ext)
{
	char	*cmp;

	cmp = ft_strdup(ft_strrchr(s, 46));
	if (ft_strncmp(cmp, ext, 4))
		return (FAILURE);
	wrfree(cmp);
	return (SUCCESS);
}
