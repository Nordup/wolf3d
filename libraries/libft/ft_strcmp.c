/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:57:55 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/13 18:57:59 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		n;

	n = 0;
	while (s1[n] != '\0' && s2[n] != '\0')
	{
		if (s1[n] == s2[n])
			n++;
		else
			return ((unsigned char)s1[n] - (unsigned char)s2[n]);
	}
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
