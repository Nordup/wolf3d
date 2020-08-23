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

t_texture	*read_texture(char *file) {
	char		**ppm;
	t_texture	*tex;

	ppm = ft_read_file(file);
	if (ppm == NULL)
		return NULL;
	return tex;
}

t_texture	*read_textures_list(void) {
	t_texture	*tex;
	t_texture	*temp;
	char		**list;
	char		*texture;
	char		*folder;

	tex = NULL;
	list = ft_read_file(TEXTURES_LIST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		if (ft_strstr(list[i], "folder")) {
			folder = get_content(list[i]);
		}
		else if (ft_strstr(list[i], "texture")) {
			texture = get_content(list[i]);
			temp = read_texture(texture);

		}
		i++;
	}
	// free strarray
	if (list != NULL)
		ft_str_arraydel(list);
	return tex;
}