/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-lebiha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:35:17 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:32:34 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (size <= lendst)
		return (lensrc + size);
	while (i + lendst < size - 1 && src[i] != 0)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lensrc + lendst);
}
