/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:36:25 by mashley           #+#    #+#             */
/*   Updated: 2020/07/29 15:36:28 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_open_read(char *name)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open(name, O_RDONLY, 0);
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (0);
	return (fd);
}
