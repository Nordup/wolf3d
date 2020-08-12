/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:55:58 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/15 13:56:00 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (ft_abs(n) > 9 || n == -2147483648)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	c = '0' + ft_abs((n % 10));
	ft_putchar_fd(c, fd);
}
