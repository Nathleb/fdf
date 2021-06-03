/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-lebiha@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:01:51 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:18:42 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*scpy;

	scpy = (unsigned char *)s;
	while (n > 0)
	{
		*scpy = 0;
		scpy++;
		n--;
	}
}
