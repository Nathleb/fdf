/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-lebiha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:02:04 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:28:27 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*destcpy = *srccpy;
		destcpy++;
		srccpy++;
		n--;
	}
	return (dest);
}
