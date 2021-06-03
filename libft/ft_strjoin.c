/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:30:27 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:33:27 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*ret;
	size_t	i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ret = malloc(lens1 + lens2 + 1);
	if (ret == NULL)
		return (ret);
	while (++i < lens1)
		ret[i] = s1[i];
	while (i < lens2 + lens1)
	{
		ret[i] = s2[i - lens1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
