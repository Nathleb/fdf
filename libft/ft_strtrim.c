/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:14:40 by nle-biha          #+#    #+#             */
/*   Updated: 2020/11/26 15:57:54 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	newlen;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	newlen = (len > i) ? len - i + 1 : 1;
	if ((ret = (char *)malloc(newlen)) == NULL)
		return (NULL);
	while (i < len)
		ret[j++] = s1[i++];
	ret[j] = '\0';
	return (ret);
}
