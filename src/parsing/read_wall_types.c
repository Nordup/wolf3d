#include "wolf3d.h"

int		add_wtype_back(t_wall_type **wtype, t_wall_type *add) {
	t_wall_type	*temp;

	if (add == NULL)
		return -1;
	else
		add->next = NULL;
	if (*wtype == NULL) {
		*wtype = add;
		return 0;
	}
	temp = *wtype;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = add;
	return 0;
}

t_wall_type	*read_wall_types(void) {
	t_wall_type	*wtype;
	t_wall_type	*temp;
	char		**list;
	char		*type;

	wtype = NULL;
	temp = NULL;
	list = ft_read_file(WALL_TYPES_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		// read type
		if (ft_strstr(list[i], "type")) {
			if (temp != NULL) {
				add_wtype_back(&wtype, temp); // add previous
			}
			temp = (t_wall_type*)malloc(sizeof(t_wall_type));
			// read type content
			type = get_content(list[i]);
			temp->type = ft_atoi(type);
			ft_strdel(&type);
		}
		// read fields
		if (ft_strstr(list[i], "north"))
			temp->north = get_content(list[i]);
		else if (ft_strstr(list[i], "south"))
			temp->south = get_content(list[i]);
		else if (ft_strstr(list[i], "east"))
			temp->east = get_content(list[i]);
		else if (ft_strstr(list[i], "west"))
			temp->west = get_content(list[i]);
		i++;
	}
	// add last wall type
	if (temp)
		add_wtype_back(&wtype, temp);
	// free list
	if (list != NULL)
		ft_str_arraydel(list);
	return wtype;
}