#include "libft.h"

void	put_cannot_open(char *name) {
	ft_putstr("Cannot open file \"");
	ft_putstr(name);
	ft_putendl("\"");
}

void	ft_str_arraydel(char **file) {
	int		i;

	i = 0;
	if (file != NULL) {
		while (file[i] != NULL) {
			ft_strdel(&file[i]);
			i++;
		}
		free(file);
	}
}

char	**add_line(char **file, char *line) {
	int		i;
	int		count;
	char	**new;

	i = 0;
	count = 0;
	if (file == NULL) {
		new = (char**)malloc(sizeof(char*) * 2);
		new[0] = line;
		new[1] = NULL;
		return new;
	}
	while (file[count] != NULL)
		count++;
	new = (char**)malloc(sizeof(char*) * (count + 2));
	while (i < count) {
		new[i] = file[i];
		i++;
	}
	new[i] = line;
	new[i + 1] = NULL;
	free(file);
	return new;
}

char	**ft_read_file(char *name) {
	int		fd;
	int		gnl_status;
	char	**file;
	char	*line;

	gnl_status = 1;
	file = NULL;
	fd = ft_open_read(name);
	if (fd == -1) {
		put_cannot_open(name);
		return NULL;
	}
	while (gnl_status == 1) {
		gnl_status = get_next_line(fd, &line);
		if (gnl_status == 1)
			file = add_line(file, line);
	}
	if (gnl_status != 0) {
		ft_str_arraydel(file);
		return NULL;
	}
	else
		return file;
}