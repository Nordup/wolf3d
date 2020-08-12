/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:03:19 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/20 14:33:49 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mlc_size(char const *s, char c)
{
	int		i;
	int		log;
	int		mlc;

	i = 0;
	log = 0;
	mlc = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (log == 0)
			{
				mlc++;
				log = 1;
			}
		}
		else
			log = 0;
		i++;
	}
	return (mlc);
}

static int	join_str(char const *s, struct s_split *r, char **sp)
{
	sp[r->mlc] = ft_strsub(s, r->start, r->i - r->start);
	if (!sp[r->mlc])
	{
		r->mlc++;
		while (--r->mlc)
		{
			free(sp[r->mlc]);
		}
		return (1);
	}
	r->mlc++;
	return (0);
}

static int	split(char const *s, char c, char **sp)
{
	struct s_split	r;
	int				before_is_sim;

	before_is_sim = 0;
	r.i = -1;
	r.mlc = 0;
	while (s[++r.i] != '\0')
	{
		if (before_is_sim == 0)
			r.start = r.i;
		if (s[r.i] != c)
			before_is_sim = 1;
		else
		{
			if (before_is_sim == 1 && join_str(s, &r, sp))
				return (1);
			before_is_sim = 0;
		}
	}
	if (r.i != 0 && s[r.i - 1] != c && join_str(s, &r, sp))
		return (1);
	sp[r.mlc] = NULL;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		mlc;
	char	**sp;

	if (!s)
		return (NULL);
	mlc = mlc_size(s, c);
	sp = (char**)malloc(sizeof(char*) * (mlc + 2));
	if (!sp)
		return (NULL);
	if (split(s, c, sp))
	{
		free(sp);
		return (NULL);
	}
	return (sp);
}
