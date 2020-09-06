/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:26:41 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:26:43 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
