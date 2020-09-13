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

void		new_texture_(char *list, char **folder, t_texture **tex)
{
	char		*tex_name;
	t_texture	*temp;
	char		*path;

	tex_name = get_content(list);
	path = ft_strjoin(*folder, tex_name);
	temp = read_texture(path, tex_name);
	if (temp != NULL)
		add_tex_back(tex, temp);
	ft_strdel(&path);
}

void		texture_list_line(char *list, t_texture **tex, char **folder)
{
	if (ft_strnequ(list, "folder", 6))
	{
		if (*folder != NULL)
			ft_strdel(folder);
		*folder = get_content(list);
	}
	else if (ft_strnequ(list, "\ttexture", 8))
		new_texture_(list, folder, tex);
}

t_texture	*read_texture_list(void)
{
	t_texture	*tex;
	char		**list;
	char		*folder;
	int			i;

	tex = NULL;
	folder = NULL;
	list = ft_read_file(TEXTURES_LIST);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (list[i] != NULL)
	{
		texture_list_line(list[i], &tex, &folder);
		i++;
	}
	if (folder != NULL)
		ft_strdel(&folder);
	if (list != NULL)
		ft_str_arraydel(list);
	return (tex);
}
