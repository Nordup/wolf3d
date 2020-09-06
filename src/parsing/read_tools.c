/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:33:19 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 13:33:21 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*find_texture(t_texture *tex, char *name)
{
	if (tex)
		while (1)
		{
			if (ft_strequ(tex->name, name))
				return (tex);
			if (tex->next != NULL)
				tex = tex->next;
			else
				break ;
		}
	return (NULL);
}

int			add_wtype_back(t_wall_type **wtype, t_wall_type *add)
{
	t_wall_type	*temp;

	if (add == NULL)
		return (-1);
	else
		add->next = NULL;
	if (*wtype == NULL)
	{
		*wtype = add;
		return (0);
	}
	temp = *wtype;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = add;
	return (0);
}

void		free_int_matrix(int ***matrix, int size)
{
	int		i;
	int		**del;

	del = *matrix;
	i = 0;
	if (del)
	{
		while (i < size)
		{
			if (del[i])
				free(del[i]);
			i++;
		}
		free(del);
	}
}

int			add_tex_back(t_texture **tex, t_texture *add)
{
	t_texture	*temp;

	if (add == NULL)
		return (-1);
	else
		add->next = NULL;
	if (*tex == NULL)
	{
		*tex = add;
		return (0);
	}
	temp = *tex;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = add;
	return (0);
}

int			add_map_back(t_map **map, t_map *add)
{
	t_map	*temp;

	if (add == NULL)
		return (-1);
	else
		add->next = NULL;
	if (*map == NULL)
	{
		*map = add;
		return (0);
	}
	temp = *map;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = add;
	return (0);
}
