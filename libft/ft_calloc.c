/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:02:46 by nle-biha          #+#    #+#             */
/*   Updated: 2020/11/26 17:02:53 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if ((ret = (char *)malloc(nmemb * size)) == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		ret[i] = '\0';
		i++;
	}
	return ((void *)ret);
}
