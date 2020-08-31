#include "world.h"
#include "wolf3d.h"

void	print_wall_types(t_wall_type *wtype)
{
	if (wtype != NULL)
	{
		ft_putendl("wtype list:");
		while (1)
		{
			ft_putstr("\t");
			ft_putnbr(wtype->type);
			ft_putstr(" ");
			if (wtype->north)
				ft_putstr(wtype->north->name);
			else
				ft_putstr("null");
			ft_putstr(" ");
			if (wtype->south)
				ft_putstr(wtype->south->name);
			else
				ft_putstr("null");
			ft_putstr(" ");
			if (wtype->east)
				ft_putstr(wtype->east->name);
			else
				ft_putstr("null");
			ft_putstr(" ");
			if (wtype->west)
				ft_putstr(wtype->west->name);
			else
				ft_putstr("null");
			ft_putstr("\n");
			if (wtype->next == NULL)
				break ;
			wtype = wtype->next;
		}
	}
	else
	{
		ft_putendl("wtype == NULL");
	}
}

void	print_textures(t_texture *tex)
{
	if (tex)
	{
		ft_putendl("textures list:");
		while (1)
		{
			ft_putstr("\t");
			ft_putstr(tex->name);
			ft_putstr(" ");
			ft_putnbr(tex->h);
			ft_putstr(" ");
			ft_putnbr(tex->w);
			/*for (int i = 0; i < tex->w; i++) {
				for (int j = 0; j < tex->h; j++) {
					ft_putstr(" ");
					ft_putnbr(tex->clr[i][j]);
				}
			}*/
			ft_putstr("\n");
			if (tex->next == NULL)
				break ;
			tex = tex->next;
		}
	}
	else
	{
		ft_putendl("textures == NULL");
	}
}

void	print_maps(t_map *map)
{
	if (map)
	{
		ft_putendl("maps list:");
		while (1)
		{
			ft_putstr("\t");
			ft_putstr(map->name);
			ft_putstr(" ");
			ft_putnbr(map->h);
			ft_putstr(" ");
			ft_putnbr(map->w);
			ft_putstr(" ");
			//printf("x %f\n", map->prsn.pnt.x);
			ft_putstr(" ");
			//printf("y %f\n", map->prsn.pnt.y);
			/*for (int i = 0; i < map->h; i++) {
				for (int j = 0; j < map->w; j++) {
					ft_putstr(" ");
					ft_putnbr(map->box[i][j]);
				}
			}*/
			ft_putstr("\n");
			if (map->next == NULL)
				break ;
			map = map->next;
		}
	}
	else
	{
		ft_putendl("maps == NULL");
	}
}

t_wall	*init_wall(void)
{
	int		size;
	t_wall	*wall;

	size = WIN_H + 1;
	wall = (t_wall*)malloc(sizeof(t_wall));
	wall->tex = (Uint32*)malloc(sizeof(Uint32) * size);
	wall->size = size;
	return (wall);
}

t_wrld	*init_world(void)
{
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->wall = init_wall();
	ft_putendl("Map reading...");
	world->map = read_map_list();
	print_maps(world->map);
	ft_putendl("Texture reading...");
	world->tex = read_texture_list();
	print_textures(world->tex);
	ft_putendl("Wall types reading...");
	world->type = read_wall_types(world->tex);
	print_wall_types(world->type);
	return (world);
}
