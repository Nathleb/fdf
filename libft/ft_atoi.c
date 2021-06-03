/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:38:25 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:18:10 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long int	sign;
	long long int	ret;
	unsigned int	i;

	i = 0;
	sign = 1;
	ret = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	ret *= sign;
	return ((int)ret);
}
