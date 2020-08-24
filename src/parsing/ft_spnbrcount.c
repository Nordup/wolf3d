/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spnbrcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:33:52 by mashley           #+#    #+#             */
/*   Updated: 2020/07/21 16:33:55 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_spnbrcount(char *str)
{
	int i;
	int count;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!(ft_isspace(str[i]) || ft_isnumber(str[i])))
		game_over(3);
	count = 0;
	while (str[i + 1])
	{
		if (ft_isspace(str[i]) && ft_isnumber(str[i + 1]))
			count++;
		else if (!(ft_isspace(str[i + 1]) || ft_isnumber(str[i + 1])))
			game_over(3);
		i++;
	}
	return (count);
}
