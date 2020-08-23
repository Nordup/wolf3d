#include "wolf3d.h"

t_texture	*find_texture(t_texture *tex, char *name) {
	if (tex)
		while (1) {
			if (ft_strequ(tex->name, name))
				return tex;
			if (tex->next != NULL)
				tex = tex->next;
			else
				break;
		}
	return 	NULL;
}

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

t_wall_type	*read_wall_types(t_texture *tex) {
	t_wall_type	*wtype;
	t_wall_type	*temp;
	char		**list;
	char		*content;

	wtype = NULL;
	temp = NULL;
	list = ft_read_file(WALL_TYPES_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		content = get_content(list[i]); // read type content
		if (ft_strstr(list[i], "type")) {
			if (temp != NULL) {
				add_wtype_back(&wtype, temp); // add previous
			}
			temp = (t_wall_type*)malloc(sizeof(t_wall_type));
			temp->type = ft_atoi(content);
		}
		// read fields
		if (ft_strstr(list[i], "north"))
			temp->north = find_texture(tex, content);
		else if (ft_strstr(list[i], "south"))
			temp->south =  find_texture(tex, content);
		else if (ft_strstr(list[i], "east"))
			temp->east =  find_texture(tex, content);
		else if (ft_strstr(list[i], "west"))
			temp->west =  find_texture(tex, content);
		ft_strdel(&content);
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