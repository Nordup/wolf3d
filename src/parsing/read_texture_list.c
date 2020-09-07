/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:27:06 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:27:08 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*read_texture_list(void)
{
	t_texture	*tex;
	t_texture	*temp;
	char		**list;
	char		*folder;
	char		*tex_name;
	char		*path;
	int			i;

	tex = NULL;
	folder = NULL;
	list = ft_read_file(TEXTURES_LIST);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (list[i] != NULL)
	{
		if (ft_strnequ(list[i], "folder", 6))
		{
			if (folder != NULL)
				ft_strdel(&folder);
			folder = get_content(list[i]);
		}
		else if (ft_strnequ(list[i], "\ttexture", 8))
		{
			tex_name = get_content(list[i]);
			path = ft_strjoin(folder, tex_name);
			temp = read_texture(path, tex_name);
			if (temp != NULL)
				add_tex_back(&tex, temp);
			ft_strdel(&path);
		}
		i++;
	}
	if (folder != NULL)
		ft_strdel(&folder);
	if (list != NULL)
		ft_str_arraydel(list);
	return (tex);
}
