/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:19:18 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/13 10:19:20 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			new_texture(t_texture **tex, char ***ppm,
					char *file, char *tex_name)
{
	int		*array;

	*ppm = ft_read_file(file);
	if (*ppm == NULL)
		return (1);
	else if ((*ppm)[1] == NULL || (*ppm)[2] == NULL || (*ppm)[3] == NULL)
		return (1);
	(*tex) = (t_texture*)malloc(sizeof(t_texture));
	(*tex)->name = tex_name;
	if ((array = get_int_array((*ppm)[1], 2)) == NULL)
		return (1);
	(*tex)->w = array[0];
	(*tex)->h = array[1];
	(*tex)->clr = (int**)malloc(sizeof(int*) * (*tex)->h);
	return (0);
}

int			fill_tex_clr(t_texture **tex, char **ppm, int begin)
{
	int		*array;
	int		i;

	i = begin;
	while (ppm[i] != NULL)
	{
		array = get_clr_array(ppm[i], (*tex)->w);
		if (array == NULL)
		{
			free_int_matrix(&(*tex)->clr, i - begin);
			ft_strdel(&(*tex)->name);
			free(tex);
			return (begin);
		}
		(*tex)->clr[i - begin] = array;
		i++;
	}
	return (i);
}

t_texture	*read_texture(char *file, char *tex_name)
{
	char		**ppm;
	t_texture	*tex;
	int			begin;
	int			i;

	begin = 3;
	if (new_texture(&tex, &ppm, file, tex_name) == 1)
		return (NULL);
	i = fill_tex_clr(&tex, ppm, begin);
	if (i == begin)
		return (NULL);
	if ((i - begin) != tex->h)
	{
		free_int_matrix(&tex->clr, i - begin);
		ft_strdel(&tex->name);
		free(tex);
		return (NULL);
	}
	if (ppm != NULL)
		ft_str_arraydel(ppm);
	return (tex);
}
