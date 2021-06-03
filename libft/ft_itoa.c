/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:20:26 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:22:35 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrdigit(unsigned int nbr)
{
	int	nbrdigit;

	nbrdigit = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		nbrdigit++;
	}
	return (nbrdigit);
}

void	ft_strrev(char *str)
{
	int		i;
	char	c;
	int		len;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char			*ret;
	long int		nbr;
	int				nbrdigit;
	unsigned int	i;

	i = 0;
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	nbrdigit = ft_nbrdigit(nbr);
	ret = (char *)malloc(sizeof(char) * (nbrdigit + 2));
	if (ret == NULL)
		return (NULL);
	while (nbr > 0)
	{
		ret[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n == 0)
		ret[i++] = '0';
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_strrev(ret);
	return (ret);
}
