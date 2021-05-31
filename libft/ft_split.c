/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:27:45 by nle-biha          #+#    #+#             */
/*   Updated: 2021/04/20 14:51:45 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_nbrwrd(char const *s, char c)
{
	unsigned int	nbrwrd;
	unsigned int	i;

	i = 0;
	nbrwrd = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nbrwrd++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nbrwrd);
}

int				ft_free_split(char **ret)
{
	int i;
	
	i = 0;
	if (ret == NULL)
		return (0);
	while (ret[i])
		free((ret)[i++]);
	free(ret);
	return (0);
}

int				ft_sub_split(char **ret, char const *s, char c, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lenwrd;

	i = 0;
	j = 0;
	while (j < n)
	{
		lenwrd = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			lenwrd++;
		}
		if ((ret[j] = ft_substr(s, i - lenwrd, lenwrd)) == NULL)
			return (ft_free_split(ret));
		j++;
	}
	ret[j] = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	nbrwrd;
	char			**ret;

	if (!s)
		return (NULL);
	nbrwrd = ft_nbrwrd(s, c);
	if ((ret = (char **)malloc(sizeof(char *) * (nbrwrd + 1))) == NULL)
		return (NULL);
	if (ft_sub_split(ret, s, c, nbrwrd))
		return (ret);
	return (NULL);
}
