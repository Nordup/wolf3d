/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:03:46 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/11/05 19:10:58 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isvalid(char c, int base)
{
	int		i;
	char	digits[17];
	char	digits2[17];

	i = 0;
	while (i < 10)
	{
		digits[i] = '0' + i;
		digits2[i] = '0' + i;
		i++;
	}
	while (i < 18)
	{
		digits[i] = 'a' + i - 10;
		digits2[i] = 'A' + i - 10;
		i++;
	}
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}
