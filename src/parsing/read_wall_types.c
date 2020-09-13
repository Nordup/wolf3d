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

void			new_type(t_wall_type **temp, t_wall_type **wtype, char *content)
{
	if (*temp != NULL)
	{
		add_wtype_back(wtype, *temp);
	}
	*temp = (t_wall_type*)malloc(sizeof(t_wall_type));
	(*temp)->type = ft_atoi(content);
}

void			wall_types_line(char *list, t_wall_type **wtype,
					t_wall_type **temp, t_texture *tex)
{
	char		*content;

	content = get_content(list);
	if (ft_strnequ(list, "type", 4))
		new_type(temp, wtype, content);
	if (ft_strnequ(list, "\tnorth", 6))
		(*temp)->north = find_texture(tex, content);
	else if (ft_strnequ(list, "\tsouth", 6))
		(*temp)->south = find_texture(tex, content);
	else if (ft_strnequ(list, "\teast", 5))
		(*temp)->east = find_texture(tex, content);
	else if (ft_strnequ(list, "\twest", 5))
		(*temp)->west = find_texture(tex, content);
	ft_strdel(&content);
}

t_wall_type		*read_wall_types(t_texture *tex)
{
	t_wall_type	*wtype;
	t_wall_type	*temp;
	char		**list;
	int			i;

	wtype = NULL;
	temp = NULL;
	list = ft_read_file(WALL_TYPES_LIST);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (list[i] != NULL)
	{
		wall_types_line(list[i], &wtype, &temp, tex);
		i++;
	}
	if (temp)
		add_wtype_back(&wtype, temp);
	if (list != NULL)
		ft_str_arraydel(list);
	return (wtype);
}
