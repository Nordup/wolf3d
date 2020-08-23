/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 06:15:55 by mashley           #+#    #+#             */
/*   Updated: 2020/08/21 06:15:58 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int **read_map(int argc, char**argv)
{
	char	*str;int		fd;
	int		**map;
	int		he_we_i_j[4];

	if (argc != 2)
		game_over(1);
	if (!(fd = ft_open_read(argv[1])))
		game_over(2);
	he_we_i_j[0] = 0;
	he_we_i_j[1] = 0;
	while (get_nxt_line(fd, &str) == 1)
	{
		if (he_we_i_j[1] != 0 && ft_spnbrcount(str) != he_we_i_j[1])
			game_over(4);
		he_we_i_j[0]++;
		he_we_i_j[1] = ft_spnbrcount(str);
		free(str);
	}
	close(fd);
	if (!(fd = ft_open_read(argv[1])))
		game_over(2);
	map = (int**)ft_memalloc(sizeof(int*) * he_we_i_j[0]);
	he_we_i_j[2] = 0;
	while (he_we_i_j[2] < he_we_i_j[0])
	{
		map[he_we_i_j[2]] = (int*)ft_memalloc(sizeof(int) * he_we_i_j[1]);
		get_next_line(fd, &str);
		he_we_i_j[3] = 0;
		while (he_we_i_j[3] < he_we_i_j[1])
		{

			he_we_i_j[3]++;
		}
		he_we_i_j[2]++;
	}

	return (NULL);
}
