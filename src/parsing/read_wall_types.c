#include "wolf3d.h"

int		add_wtype_back(t_wall_type *wtype, t_wall_type add) {
	t_wall_type	*new;
	t_wall_type	*temp;

	new = (t_wall_type*)malloc(sizeof(t_wall_type));
	new->type = add.type;
	new->north = add.north;
	new->south = add.south;
	new->east = add.east;
	new->west = add.west;
	new->next = NULL;
	temp = wtype;
	if (wtype == NULL) {
		wtype = new;
		return 0;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new;
	return 0;
}

t_wall_type	*read_wall_types(void) {
	t_wall_type	*wtype;
	t_wall_type	temp;
	char		**file = NULL;

	wtype = NULL;
	file = ft_read_file(WALL_TYPES_LIST);
	if (file == NULL)
		return NULL;
	
	int i = 0;
	while (file[i] != NULL) {
		ft_putendl(file[i]);
		i++;
	}

	add_wtype_back(wtype, temp);
	// free strarray
	if (file != NULL)
		ft_str_arraydel(file);
	return wtype;
}