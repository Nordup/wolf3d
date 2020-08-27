#include "wolf3d.h"

int		add_map_back(t_map **map, t_map *add) {
	t_map	*temp;

	if (add == NULL)
		return -1;
	else
		add->next = NULL;
	if (*map == NULL) {
		*map = add;
		return 0;
	}
	temp = *map;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = add;
	return 0;
}

t_map   *read_map(char *file_name) {
    char		**file;
    t_map   	*map;
    int			*array;
    int         begin = 1;

    file = ft_read_file(file_name);
    if (file == NULL)
        return NULL;
    else if (file[0] == NULL || file[1] == NULL)
        return NULL;
    // malloc tex
    map = (t_map*)malloc(sizeof(t_map));
    // read w and h
    if ((array = get_int_array(file[0], 2)) == NULL)
        return NULL;
    map->h = array[0];
    map->w = array[1];
    // read clrs
    int	i = begin;
    map->box = (int**)malloc(sizeof(int*) * map->h);
    while (file[i] != NULL) {
        array = get_int_array(file[i], map->w);
        if (array == NULL) {
            free_int_matrix(&map->box, i - begin);
            ft_strdel(&map->name);
            free(map);
            return NULL;
        }
        map->box[i - begin] = array;
        i++;
    }
    if ((i - begin) != map->h) {
        free_int_matrix(&map->box, i - begin);
        ft_strdel(&map->name);
        free(map);
        return NULL;
    }
    if (file != NULL)
        ft_str_arraydel(file);
    return map;
}

t_map   *read_map_list(void) {
	t_map	    *map;
	t_map	    *temp;
	char		**list;
	char		*content;

    map = NULL;
	content = NULL;
    temp = NULL;
	list = ft_read_file(MAPS_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
        content = get_content(list[i]);
		if (ft_strnequ(list[i], "map", 3))
        {
			if (temp != NULL)
				add_map_back(&map, temp);
			// read map
			temp = read_map(content);
            if (content)
                ft_strdel(&content);
		}
		else if (ft_strnequ(list[i], "\tname", 5))
        {
            temp->name = content;
			// free strings
			//ft_strdel(&name); // added to map->name
		}
        else if (ft_strnequ(list[i], "\tperson_x", 9))
        {
            temp->prsn.pnt.x = ft_atoi(content);
            if (content)
                ft_strdel(&content);
        }
        else if (ft_strnequ(list[i], "\tperson_y", 9))
        {
            temp->prsn.pnt.y = ft_atoi(content);
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
	// add last map
    if (temp != NULL)
        add_map_back(&map, temp);
	// free strings
	if (list != NULL)
		ft_str_arraydel(list);
	return map;
}