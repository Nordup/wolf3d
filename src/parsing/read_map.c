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

static	void	fill_box(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*str;
	char	**nums;

	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		map->box[i] = (int*)malloc(sizeof(int) * map->w);
		nums = ft_strsplit(str, ' ');
		free(str);
		str = NULL;
		j = 0;
		while (nums[j])
		{
			map->box[i][j] = ft_atoi(nums[j]);
			free(nums[j]);
			nums[j] = NULL;
			j++;
		}
		free(nums);
		nums = NULL;
		i++;
	}
}

t_map			*read_map(char *file)
{
	char	*str;
	int		fd;
	t_map	*map;

	if (!(fd = ft_open_read(file)))
		game_over(2);
	map = (t_map*)malloc(sizeof(t_map));
	map->h = 0;
	map->w = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if (map->w != 0 && ft_spnbrcount(str) != map->w)
			game_over(4);
		map->h++;
		map->w = ft_spnbrcount(str);
		free(str);
	}
	close(fd);
	if (!(fd = ft_open_read(file)))
		game_over(2);
	map->box = (int**)ft_memalloc(sizeof(int*) * (map->h));
	fill_box(fd, map);
	map->win_map.x = WIN_W / map->w;
	map->win_map.y = WIN_H / map->h;
	return (map);
}
