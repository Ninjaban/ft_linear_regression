/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 10:09:51 by jcarra            #+#    #+#             */
/*   Updated: 2018/10/06 12:27:59 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# define THETA_FILE			"sources/value.csv"
# define ESTIMATE_PRICE(mileage)		(theta0 + (theta1 * (mileage)))
# define ESTIMATE_PRICE_LEARN(mileage)	(ESTIMATE_PRICE(mileage) - data[i].price)

typedef struct		s_data
{
	double			km;
	double			price;
}					t_data;

t_bool		ft_map_file(const char *path, t_buffer *file);
t_bool		ft_unmap_file(t_buffer *file);

void		ft_tabdel(char **tab);
float		ft_abs(float nbr);
double		ft_min(t_data *data);
double		ft_max(t_data *data);
void		ft_save_theta(double theta0, double theta1, double margin);

t_bool		ft_get_theta(double *out_theta0, double *out_theta1, double *out_margin);

#endif
