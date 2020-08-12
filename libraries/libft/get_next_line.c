/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:51:08 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/10/08 18:27:48 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_end(t_list **list, const int fd)
{
	char	s[1];
	char	*end;
	char	new_content[BUFF_SIZE];
	int		rd;

	rd = read(fd, s, 1);
	if (rd == 0)
		return (1);
	ft_strncpy(new_content, (*list)->content, BUFF_SIZE);
	free((*list)->content);
	end = ft_strchr(new_content, '\0');
	*end = *s;
	(*list)->content = ft_strsub(new_content, 0, BUFF_SIZE);
	return (0);
}

int		ret_line(char **line, t_list **mas, unsigned int klst)
{
	t_list	*tmp;
	char	*end;
	char	last[BUFF_SIZE];

	tmp = *mas;
	if (!(*line = ft_strnew(klst * BUFF_SIZE + 1)))
		return (-1);
	while (tmp)
	{
		end = ft_strchr(*line, '\0');
		ft_strncpy(end, tmp->content, BUFF_SIZE);
		if (tmp->next == NULL)
		{
			ft_strncpy(last, ft_strchr(tmp->content, '\n') + 1, BUFF_SIZE);
			ft_lstdel(&(*mas)->next, ft_dellist);
			ft_dellist((*mas)->content, (*mas)->content_size);
			(*mas)->content = ft_strsub(last, 0, BUFF_SIZE);
			break ;
		}
		tmp = tmp->next;
	}
	end = ft_strchr(*line, '\n');
	*end = '\0';
	return (1);
}

t_list	*wr_list(const int fd)
{
	t_list	*lst;
	size_t	rd;
	char	content[BUFF_SIZE + 1];
	char	check[1];

	if (fd != 0 && (fd <= 2 || read(fd, check, 0) < 0))
		return (NULL);
	rd = read(fd, content, BUFF_SIZE);
	if (rd < 1)
		return (ft_lstnew("\n", fd));
	content[rd] = '\0';
	lst = ft_lstnew(content, fd);
	return (lst);
}

int		find_fd(unsigned int *in, t_list **mas, const int fd)
{
	*in = 0;
	if (!mas[0])
		return (0);
	while (mas[*in])
	{
		if ((size_t)fd == mas[*in]->content_size)
			return (1);
		*in += 1;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*mas[100000];
	t_list			*tmp;
	unsigned int	in;
	unsigned int	klst;

	if (!find_fd(&in, mas, fd))
	{
		if (!(mas[in] = wr_list(fd)))
			return (-1);
	}
	else if (ft_strlen(mas[in]->content) == 0 && is_end(mas + in, fd))
		return (0);
	klst = 1;
	tmp = mas[in];
	while (!ft_strchr(tmp->content, '\n'))
	{
		if (!(tmp->next = wr_list(fd)))
			return (-1);
		tmp = tmp->next;
		klst++;
	}
	return (ret_line(line, mas + in, klst));
}
