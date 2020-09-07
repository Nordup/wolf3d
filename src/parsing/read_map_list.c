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

void	new_map(t_map **map, t_map **temp, char *content)
{
	if (*temp != NULL)
		add_map_back(map, *temp);
	*temp = read_map(content);
	if (content)
		ft_strdel(&content);
}

void	map_list_line(char *list, t_map **map, t_map **temp)
{
	char	*content;
	int		cont_del;

	cont_del = 1;
	content = NULL;
	content = get_content(list);
	if (ft_strnequ(list, "map", 3))
	{
		new_map(map, temp, content);
		cont_del = 0;
	}
	else if (ft_strnequ(list, "\tname", 5))
	{
		(*temp)->name = content;
		cont_del = 0;
	}
	else if (ft_strnequ(list, "\tperson_x", 9))
		(*temp)->prsn.pnt.x = ft_atof(content);
	else if (ft_strnequ(list, "\tperson_y", 9))
		(*temp)->prsn.pnt.y = ft_atof(content);
	else if (ft_strnequ(list, "\tperson_alp", 11))
		(*temp)->prsn.alp = ft_atoi(content) / PI2;
	if (content && cont_del)
		ft_strdel(&content);
}

t_map	*read_map_list(void)
{
	t_map	*map;
	t_map	*temp;
	char	**list;
	int		i;

	map = NULL;
	temp = NULL;
	list = ft_read_file(MAPS_LIST);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (list[i] != NULL)
	{
		map_list_line(list[i], &map, &temp);
		i++;
	}
	if (temp != NULL)
		add_map_back(&map, temp);
	if (list != NULL)
		ft_str_arraydel(list);
	return (map);
}
