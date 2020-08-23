#include "world.h"
#include "wolf3d.h"

void	print_wall_types(t_wall_type *wtype) {
	if (wtype != NULL) {
		ft_putendl("wtype list:");
		while (1) {
			ft_putstr("\t");
			ft_putnbr(wtype->type);
			ft_putstr(" ");
			ft_putstr(wtype->north);
			ft_putstr(" ");
			ft_putstr(wtype->south);
			ft_putstr(" ");
			ft_putstr(wtype->east);
			ft_putstr(" ");
			ft_putstr(wtype->west);
			ft_putstr("\n");
			if (wtype->next == NULL)
				break;
			wtype = wtype->next;
		}
	} else {
		ft_putendl("wtype == NULL");
	}
}

void	print_textures(t_texture *tex) {
	if (tex) {
		ft_putendl("textures list:");
		while (1) {
			ft_putstr("\t");
			ft_putstr(tex->name);
			ft_putstr(" ");
			ft_putnbr(tex->w);
			ft_putstr(" ");
			ft_putnbr(tex->h);
			ft_putstr("\n");
			if (tex->next == NULL)
				break;
			tex = tex->next;
		}
	} else {
		ft_putendl("textures == NULL");
	}
}

void	set_wall_size(t_wrld *wrld, float size) {
	if (size >= WIN_H)
		size = WIN_H - 1;
	wrld->wall->size = size;
}

t_wall	*init_wall(void) {
	int		size = WIN_H + 1;
	t_wall *wall = (t_wall*)malloc(sizeof(t_wall));
	wall->tex = (Uint32*)malloc(sizeof(Uint32) * size);
	wall->size = size;
	return wall;
}

t_wrld	*init_world(void) {
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->wall = init_wall();
	world->map = init_map();
	world->prsn = init_person();
	world->tex = read_textures_list();
	world->type = read_wall_types();
	print_textures(world->tex);
	print_wall_types(world->type);
	return world;
}