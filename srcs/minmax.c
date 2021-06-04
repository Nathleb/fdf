/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:51:36 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/04 12:27:55 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

double	max_double(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

double	min_double(double a, double b)
{
	fprintf(stderr, "%f %f\n", a, b);
	if (a < b)
		return (a);
	return (b);
}
