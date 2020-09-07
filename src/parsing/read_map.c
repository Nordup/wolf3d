#include "wolf3d.h"

int		new_maps(t_map **map, char ***file, char *file_name)
{
	int		*array;

	*file = ft_read_file(file_name);
	if (*file == NULL)
		return (1);
	else if ((*file)[0] == NULL || (*file)[1] == NULL)
		return (1);
	*map = (t_map*)malloc(sizeof(t_map));
	if ((array = get_int_array((*file)[0], 2)) == NULL)
		return (1);
	(*map)->h = array[0];
	(*map)->w = array[1];
	(*map)->box = (int**)malloc(sizeof(int*) * (*map)->h);
}

int		fill_map_box(t_map **map, char **file, int begin)
{
	int		*array;
	int		i;

	i = begin;
	while (file[i] != NULL)
	{
		array = get_int_array(file[i], (*map)->w);
		if (array == NULL)
		{
			free_int_matrix(&(*map)->box, i - begin);
			ft_strdel(&(*map)->name);
			free(map);
			return (begin);
		}
		(*map)->box[i - begin] = array;
		i++;
	}
	return i;
}

t_map	*read_map(char *file_name)
{
	char	**file;
	t_map	*map;
	int		begin;
	int		i;

	begin = 1;
	if (new_maps(&map, &file, file_name) == 1)
		return (NULL);
	i = fill_map_box(&map, file, begin);
	if (i == begin)
		return (NULL);
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