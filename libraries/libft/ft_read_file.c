#include "libft.h"

void	put_cannot_open(char *name) {
	ft_putstr("Cannot open file \"");
	ft_putstr(name);
	ft_putendl("\"");
}

char	*ft_read_file(char *name) {
	int		fd;
	int		gnl_status;
	char	*file;
	char	*del;
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
		del = file;
		file = ft_strjoin(file, line);
		ft_strdel(&del);
		ft_strdel(&line);
	}
	if (gnl_status != 0)
		return NULL;
	else
		return file;
}