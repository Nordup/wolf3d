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

//static	int	fill_map(int **map, int fd)
//{
//	int		i;
//	int		j;
//	char	**nums;
//
//	(void)j;
//	(void)nums;
//	i = 0;
//	while (0)
//		i++;
//	return ((int**) {{0, 0}, {0, 0}});
//}

//int	**read_map(char *file)
//{
//	char	*str;
//	char	**numb;
//	int		fd;
//	int		**map;
//	int		he_we_i_j[4];
//
//	if (!(fd = ft_open_read(file)))
//		game_over(2);
//	he_we_i_j[0] = 0;
//	he_we_i_j[1] = 0;
//	while (get_next_line(fd, &str) == 1)
//	{
//		if (he_we_i_j[1] != 0 && ft_spnbrcount(str) != he_we_i_j[1])
//			game_over(4);
//		he_we_i_j[0]++;
//		he_we_i_j[1] = ft_spnbrcount(str);
//		free(str);
//	}
//	close(fd);
//	if (!(fd = ft_open_read(file)))
//		game_over(2);
//	map = (int**)ft_memalloc(sizeof(int*) * he_we_i_j[0]);
//	he_we_i_j[2] = 0;
//	while (he_we_i_j[2] < he_we_i_j[0])
//	{
//		map[he_we_i_j[2]] = (int*)ft_memalloc(sizeof(int) * he_we_i_j[1]);
//		get_next_line(fd, &str);
//		numb = ft_strsplit(str);
//		he_we_i_j[3] = 0;
//		while (he_we_i_j[3] < he_we_i_j[1])
//		{
//			map[he_we_i_j[2]][he_we_i_j[3]] = ft_atoi(numb[he_we_i_j[2]][he_we_i_j[3]]);
//			free(numb[he_we_i_j[2]][he_we_i_j[3]]);
//			numb[he_we_i_j[2]][he_we_i_j[3]] = NULL;
//			he_we_i_j[3]++;
//		}
//		he_we_i_j[2]++;
//	}
//
//	return ((int**) {{0, 0}, {0, 0}});
//}
