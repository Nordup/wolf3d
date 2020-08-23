#include "wolf3d.h"

int		add_tex_back(t_texture **tex, t_texture *add) {
	t_texture	*temp;

	if (add == NULL)
		return -1;
	else
		add->next = NULL;
	if (*tex == NULL) {
		*tex = add;
		return 0;
	}
	temp = *tex;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = add;
	return 0;
}

t_texture	*read_texture(char *file, char *tex_name) {
	char		**ppm;
	t_texture	*tex;
	int			*array;

	ppm = ft_read_file(file);
	if (ppm == NULL)
		return NULL;
	else if (ppm[1] == NULL || ppm[2] == NULL || ppm[3] == NULL)
		return NULL;
	// malloc tex
	tex = (t_texture*)malloc(sizeof(t_texture));
	tex->name = tex_name;
	// read w and h
	if ((array = get_int_array(ppm[1], 2)) == NULL)
		return NULL;
	tex->w = array[0];
	tex->h = array[1];
	// read clrs
	int	i = 3;
	while (ppm[i] != NULL) {
		i++;
	}
	if (ppm != NULL)
		ft_str_arraydel(ppm);
	return tex;
}

t_texture	*read_textures_list(void) {
	t_texture	*tex;
	t_texture	*temp;
	char		**list;
	char		*folder;
	char		*tex_name;
	char		*path;

	tex = NULL;
	folder = NULL;
	list = ft_read_file(TEXTURES_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		if (ft_strstr(list[i], "folder")) {
			if (folder != NULL)
				ft_strdel(&folder);
			folder = get_content(list[i]);
		}
		else if (ft_strstr(list[i], "texture")) {
			tex_name = get_content(list[i]);
			path = ft_strjoin(folder, tex_name);
			// read texture
			temp = read_texture(path, tex_name);
			if (temp != NULL)
				add_tex_back(&tex, temp);
			// free strings
			//ft_strdel(&tex_name); // added to tex->name
			ft_strdel(&path);
		}
		i++;
	}
	// free strings
	if (folder != NULL)
		ft_strdel(&folder);
	if (list != NULL)
		ft_str_arraydel(list);
	return tex;
}