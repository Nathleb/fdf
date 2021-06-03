/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:14:40 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:37:27 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ret;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	if (len > i)
		 ret = malloc(len - i + 1);
	else
		ret = malloc(1);
	if ((ret) == NULL)
		return (NULL);
	while (i < len)
		ret[j++] = s1[i++];
	ret[j] = '\0';
	return (ret);
}
