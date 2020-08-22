#include "wolf3d.h"

int		add_tex_back(t_texture *tex, t_texture add) {
	t_texture	*new;
	t_texture	*temp;

	new = (t_texture*)malloc(sizeof(t_texture));
	new->name = add.name;
	new->w = add.w;
	new->h = add.h;
	new->clr = add.clr;
	new->next = NULL;
	temp = tex;
	if (tex == NULL) {
		tex = new;
		return 0;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new;
	return 0;
}

t_texture	*read_textures(void) {
	t_texture	*tex;
	t_texture	temp;
	char		**list = NULL;

	tex = NULL;
	list = ft_read_file(TEXTURES_LISST);
	if (list == NULL)
		return NULL;
	
	int i = 0;
	while (list[i] != NULL) {
		ft_putendl(list[i]);
		i++;
	}
	
	add_tex_back(tex, temp);
	// free strarray
	if (list != NULL)
		ft_str_arraydel(list);
	return tex;
}