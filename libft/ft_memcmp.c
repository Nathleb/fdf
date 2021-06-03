/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:03:42 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:27:50 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *s1cpy == *s2cpy)
	{
		s1cpy++;
		s2cpy++;
		n--;
	}
	return ((int)(*s1cpy - *s2cpy));
}
