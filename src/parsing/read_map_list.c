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
	// free strings
	if (list != NULL)
		ft_str_arraydel(list);
	return map;
}