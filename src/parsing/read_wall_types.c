/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_wall_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:27:13 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:27:15 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_wall_type		*read_wall_types(t_texture *tex)
{
	t_wall_type	*wtype;
	t_wall_type	*temp;
	char		**list;
	char		*content;
	int			i;

	wtype = NULL;
	temp = NULL;
	list = ft_read_file(WALL_TYPES_LIST);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (list[i] != NULL)
	{
		content = get_content(list[i]);
		if (ft_strnequ(list[i], "type", 4))
		{
			if (temp != NULL)
			{
				add_wtype_back(&wtype, temp);
			}
			temp = (t_wall_type*)malloc(sizeof(t_wall_type));
			temp->type = ft_atoi(content);
		}
		if (ft_strnequ(list[i], "\tnorth", 6))
			temp->north = find_texture(tex, content);
		else if (ft_strnequ(list[i], "\tsouth", 6))
			temp->south = find_texture(tex, content);
		else if (ft_strnequ(list[i], "\teast", 5))
			temp->east = find_texture(tex, content);
		else if (ft_strnequ(list[i], "\twest", 5))
			temp->west = find_texture(tex, content);
		ft_strdel(&content);
		i++;
	}
	if (temp)
		add_wtype_back(&wtype, temp);
	if (list != NULL)
		ft_str_arraydel(list);
	return (wtype);
}
