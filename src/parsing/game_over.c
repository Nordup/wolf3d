/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:43:20 by mashley           #+#    #+#             */
/*   Updated: 2020/07/18 16:43:24 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_over(int error)
{
	if (error == 0)
		ft_putstr("Error!!\n");
	else if (error == 1)
		ft_putstr("I need exactly one argument.\n");
	else if (error == 2)
		ft_putstr("I cannot read this file.\n");
	else if (error == 3)
		ft_putstr("There are some incomprehensible characters in the file.\n");
	else if (error == 4)
		ft_putstr("All lines must be the same width.\n");
	else if (error == 5)
		ft_putstr("The file must have the extension .fdf\n");
	else if (error == 32)
		ft_putstr("!\n");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else if (error == 32)
		ft_putstr("!");
	else
		ft_putstr("Some error :(");
	exit(0);
}
