/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-lebiha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:04:54 by nle-biha          #+#    #+#             */
/*   Updated: 2020/11/26 17:08:46 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *destcpy;
	unsigned char *srccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	while (n > 0)
	{
		*destcpy = *srccpy;
		n--;
		if (*srccpy == (unsigned char)c)
			return ((void *)(destcpy + 1));
		destcpy++;
		srccpy++;
	}
	return (NULL);
}
