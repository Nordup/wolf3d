#include "wolf3d.h"

char	*get_content(char *line)
{
	char	*begin;
	char	*end;

	begin = ft_strchr(line, '(');
	end = ft_strrchr(line, ')');
	if (begin == NULL || end == NULL)
		return (NULL);
	begin++;
	return (ft_strsub(line, begin - line, end - begin));
}
