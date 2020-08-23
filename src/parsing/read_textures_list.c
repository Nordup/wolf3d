#include "wolf3d.h"

void	free_int_array(int	**array, int size) {
	int		i;

	i = 0;
	if (array) {
		while (i < size) {
			if (array[i])
				free(array[i]);
			i++;
		}
		free(array);
	}
}

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
	char		*file_ppm = ft_strjoin(file, ".ppm");

	ppm = ft_read_file(file_ppm);
	ft_strdel(&file_ppm);
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
	tex->clr = (int**)malloc(sizeof(int*) * tex->w);
	while (ppm[i] != NULL) {
		array = get_clr_array(ppm[i], tex->h);
		if (array == NULL) {
			free_int_array(tex->clr, i - 3);
			ft_strdel(&tex->name);
			free(tex);
			return NULL;
		}
		tex->clr[i - 3] = array;
		i++;
	}
	if ((i - 3) != tex->w) {
		free_int_array(tex->clr, i - 3);
		ft_strdel(&tex->name);
		free(tex);
		return NULL;
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