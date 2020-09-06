/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:27:00 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:27:01 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map	*read_map(char *file_name)
{
	char	**file;
	t_map	*map;
	int		*array;
	int		begin;
	int		i;

	begin = 1;
	file = ft_read_file(file_name);
	if (file == NULL)
		return (NULL);
	else if (file[0] == NULL || file[1] == NULL)
		return (NULL);
	map = (t_map*)malloc(sizeof(t_map));
	if ((array = get_int_array(file[0], 2)) == NULL)
		return (NULL);
	map->h = array[0];
	map->w = array[1];
	i = begin;
	map->box = (int**)malloc(sizeof(int*) * map->h);
	while (file[i] != NULL)
	{
		array = get_int_array(file[i], map->w);
		if (array == NULL)
		{
			free_int_matrix(&map->box, i - begin);
			ft_strdel(&map->name);
			free(map);
			return (NULL);
		}
		map->box[i - begin] = array;
		i++;
	}
	if ((i - begin) != map->h)
	{
		free_int_matrix(&map->box, i - begin);
		ft_strdel(&map->name);
		free(map);
		return (NULL);
	}
	if (file != NULL)
		ft_str_arraydel(file);
	return (map);
}

t_map	*read_map_list(void)
{
	t_map	*map;
	t_map	*temp;
	char	**list;
	char	*content;
	int		i;

	map = NULL;
	content = NULL;
	temp = NULL;
	list = ft_read_file(MAPS_LIST);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (list[i] != NULL)
	{
		content = get_content(list[i]);
		if (ft_strnequ(list[i], "map", 3))
		{
			if (temp != NULL)
				add_map_back(&map, temp);
			temp = read_map(content);
			if (content)
				ft_strdel(&content);
		}
		else if (ft_strnequ(list[i], "\tname", 5))
			temp->name = content;
		else if (ft_strnequ(list[i], "\tperson_x", 9))
		{
			temp->prsn.pnt.x = ft_atof(content);
			if (content)
				ft_strdel(&content);
		}
		else if (ft_strnequ(list[i], "\tperson_y", 9))
		{
			temp->prsn.pnt.y = ft_atof(content);
			if (content)
				ft_strdel(&content);
		}
		else if (ft_strnequ(list[i], "\tperson_alp", 11))
		{
			temp->prsn.alp = ft_atoi(content) / PI2;
			if (content)
				ft_strdel(&content);
		}
		else if (content)
			ft_strdel(&content);
		i++;
	}
	if (temp != NULL)
		add_map_back(&map, temp);
	if (list != NULL)
		ft_str_arraydel(list);
	return (map);
}
