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

static	void	fill_map(int fd, int ***map)
{
	int		i;
	int		j;
	char	*str;
	char	**nums;

	i = 1;
	while (i < (*map)[0][0] + 1)
	{
		(*map)[i] = (int*)malloc(sizeof(int) * ((*map)[0][1]));
		get_next_line(fd, &str);
		nums = ft_strsplit(str, ' ');
		j = 0;
		while (j < (*map)[0][1])
		{
			(*map)[i][j] = ft_atoi(nums[j]);
			j++;
		}
		i++;
	}
}

int	**read_map(char *file)
{
	char	*str;
	int		fd;
	int		height;
	int		width;
	int		**map;

	if (!(fd = ft_open_read(file)))
		game_over(2);
	height = 0;
	width = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if (width != 0 && ft_spnbrcount(str) != width)
			game_over(4);
		height++;
		width = ft_spnbrcount(str);
		free(str);
	}
	close(fd);
	if (!(fd = ft_open_read(file)))
		game_over(2);
	map = (int**)ft_memalloc(sizeof(int*) * (height + 1));
	map[0] = (int*)malloc(sizeof(int) * 2);
	map[0][0] = height;
	map[0][1] = width;
	fill_map(fd, &map);
	return (map);
}
