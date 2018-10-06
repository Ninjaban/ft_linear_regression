/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_learn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:26:37 by nathan            #+#    #+#             */
/*   Updated: 2018/10/06 13:05:39 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "types.h"
#include "internal.h"

static void			ft_get_data_value(t_data **data, t_pchar *tab)
{
	t_uint		n;
	t_uint		i;

	n = 0;
	i = 0;
	while (tab[n] && tab[n + 1])
	{
		FT_DEBUG("tab[%d] : %s", n, tab[n]);
		FT_DEBUG("tab[%d] : %s", n + 1, tab[n + 1]);
		if (ft_isdigit(tab[n][0]))
		{
			(*data)[i].km = atof(tab[n]);
			(*data)[i].price = atof(tab[n + 1]);
			i = i + 1;
		}

		n = n + 2;
	}
	(*data)[i].km = -1;
	(*data)[i].price = -1;
}

static t_bool		ft_get_data(t_pchar path, t_data **data)
{
	t_buffer	file;
	t_pchar		*tab;

	if (!ft_map_file(path, &file))
	{
		FT_WARNING("ft_map_file() failed path %s", path);
		return (FALSE);
	}

	if ((tab = ft_strsplit(file.bytes, ",\n")) == NULL)
	{
		FT_ERROR("ft_strsplit() %s", "failed");
		return (FALSE);
	}

	if ((*data = malloc(sizeof(t_data) * (ft_tablen(tab) + 1))) == NULL)
	{
		FT_ERROR("malloc() failed size %ld", sizeof(t_data) * (ft_tablen(tab) + 1));
		return (FALSE);
	}

	ft_get_data_value(data, tab);
	ft_tabdel(tab);

	if (!ft_unmap_file(&file))
	{
		FT_WARNING("ft_unmap_file() %s", "failed");
		return (FALSE);
	}
	return (TRUE);
}

static void		ft_scale(t_data *data, double *scale, double *scale_min)
{
	double	min;
	double	max;

	min = ft_min(data);
	max = ft_max(data);
	*scale = max - min;
	*scale_min = min / *scale;
	for (int n = 0 ; data[n].km != -1 ; n ++)
	{
		data[n].km = ((data[n].km - min) / *scale);
		FT_DEBUG("data[%d].km : %f", n, data[n].km);
		FT_DEBUG("data[%d].price : %f", n, data[n].price);
	}
	FT_DEBUG("scale : %f", *scale);
}

static void		ft_undo_scale(t_data *data, double scale, double scale_min)
{
	double	min;

	min = scale_min * scale;
	for (int n = 0 ; data[n].km != -1 ; n ++)
		data[n].km = data[n].km * scale + min;
}

static double	ft_get_margin(t_data *data, int m, double theta0, double theta1)
{
	double	margin;
	double	price;
	double	diff;

	margin = 0;
	for (int i = 0 ; i < m ; i ++)
	{
		price = ESTIMATE_PRICE(data[i].km);
		diff = ft_abs((float)(price - data[i].price));
		if (margin < diff * 100 / price)
			margin = diff * 100 / price;
		FT_DEBUG("Estimate : %0.2f Price %0.2f diff : %f percent : %f", price, data[i].price, diff, diff * 100 / price);
	}
	return (margin);
}

static void		ft_learn(t_data *data, int m, double theta0, double theta1)
{
	float	tmpTheta0;
	float	tmpTheta1;
	float	learning_rate;
	double	scale;
	double	scale_min;

	learning_rate = 0.1;
	ft_scale(data, &scale, &scale_min);
	do
	{
		FT_DEBUG("theta0 : %f theta1 : %f", theta0, theta1);
		tmpTheta0 = 0;
		tmpTheta1 = 0;
		for (int i = 0 ; i < m ; i ++)
		{
			tmpTheta0 += ESTIMATE_PRICE_LEARN(data[i].km + scale_min);
			tmpTheta1 += ESTIMATE_PRICE_LEARN(data[i].km + scale_min) * data[i].km;
		}
		theta0 -= learning_rate * tmpTheta0 / m;
		theta1 -= learning_rate * tmpTheta1 / m;
		FT_DEBUG("tmpTheta0 : %f tmpTheta1 : %f", tmpTheta0, tmpTheta1);
	}
	while (ft_abs(tmpTheta0) > 0.001 && ft_abs(tmpTheta1) > 0.001);
	theta1 /= scale;
	FT_DEBUG("theta0 : %f theta1 : %f", theta0, theta1);
	ft_undo_scale(data, scale, scale_min);
	ft_save_theta(theta0, theta1, ft_get_margin(data, m, theta0, theta1));
}

int			main(int ac, char **av)
{
	t_data		*data;
	int			m;
	double		theta0;
	double		theta1;
	double		margin;

	if (ac != 2)
		return (1);

	if (!ft_get_data(av[1], &data))
	{
		FT_WARNING("ft_get_data() %s", "failed");
		return (1);
	}

	m = 0;
	while (data[m].km != -1 && data[m].price != -1)
		m = m + 1;

	if (!ft_get_theta(&theta0, &theta1, &margin))
	{
		FT_WARNING("ft_get_theta() %s", "failed");
		return (1);
	}

	ft_learn(data, m, theta0, theta1);
	free(data);

	return (0);
}