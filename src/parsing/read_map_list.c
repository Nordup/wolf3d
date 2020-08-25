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

t_map   *read_map_list(void) {
	t_map	    *map;
	t_map	    *temp;
	char		**list;
	char		*name;
	char		*file;
    char        *per_pos;

	map = NULL;
	file = NULL;
    per_pos = NULL;
	list = ft_read_file(MAPS_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		if (ft_strstr(list[i], "map")) {
			file = get_content(list[i]);
			// read map
			temp = read_map(file);
			if (temp != NULL)
				add_map_back(&map, temp);
		}
		else if (ft_strstr(list[i], "name")) {
			name = get_content(list[i]);
            temp->name = name;
			// free strings
			//ft_strdel(&name); // added to map->name
		}
        else if (ft_strstr(list[i], "person_x"))
        {
            per_pos = get_content(list[i]);
            temp->prsn.pnt.x = ft_atoi(per_pos);
        }
        else if (ft_strstr(list[i], "person_y"))
        {
            per_pos = get_content(list[i]);
            temp->prsn.pnt.y = ft_atoi(per_pos);
        }
        else if (ft_strstr(list[i], "person_alp"))
        {
            per_pos = get_content(list[i]);
            temp->prsn.alp = ft_atoi(per_pos) / PI2;
        }
        // free
		if (file != NULL)
			ft_strdel(&file);
		if (per_pos != NULL)
			ft_strdel(&per_pos);
		i++;
	}
	// free strings
	if (list != NULL)
		ft_str_arraydel(list);
	return map;
}