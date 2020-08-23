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

	ppm = ft_read_file(file);
	if (ppm == NULL)
		return NULL;

	if (ppm != NULL)
		ft_str_arraydel(ppm);
	return NULL;
}

t_texture	*read_textures_list(void) {
	t_texture	*tex;
	t_texture	*temp;
	char		**list;
	char		*tex_name;
	char		*folder;
	char		*path;

	tex = NULL;
	list = ft_read_file(TEXTURES_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		if (ft_strstr(list[i], "folder")) {
			folder = get_content(list[i]);
			ft_putendl(folder);
		}
		else if (ft_strstr(list[i], "texture")) {
			tex_name = get_content(list[i]);
			// print file name
			ft_putstr("\t");
			ft_putendl(tex_name);
			path = ft_strjoin(folder, tex_name);
			// read texture
			temp = read_texture(path, tex_name);
			if (temp != NULL)
				add_tex_back(&tex, temp);
			// free strings
			ft_strdel(&tex_name);
			ft_strdel(&path);
		}
		i++;
	}
	// free strarray
	if (list != NULL)
		ft_str_arraydel(list);
	return tex;
}