/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:36:00 by nathan            #+#    #+#             */
/*   Updated: 2018/10/06 12:34:37 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "internal.h"

extern void		ft_tabdel(char **tab)
{
	int		n;

	n = 0;
	while (tab[n])
		free(tab[n++]);
	free(tab);
}

extern float	ft_abs(float nbr)
{
	return ((nbr < 0) ? nbr * -1 : nbr);
}

extern double	ft_min(t_data *data)
{
	double	min;
	int		n;

	n = 0;
	min = data[0].km;
	while (data[n].km != -1)
	{
		if (min > data[n].km)
			min = data[n].km;
		n = n + 1;
	}
	return (min);
}

extern double	ft_max(t_data *data)
{
	double	max;
	int		n;

	n = 0;
	max = data[0].km;
	while (data[n].km != -1)
	{
		if (max < data[n].km)
			max = data[n].km;
		n = n + 1;
	}
	return (max);
}

extern void		ft_save_theta(double theta0, double theta1, double margin)
{
	FILE	*stream;

	if ((stream = fopen(THETA_FILE, "w+")) == NULL)
		return;
	fprintf(stream, "%f,%f,%f", theta0, theta1, margin);
	fclose(stream);
}