/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_regression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:26:42 by nathan            #+#    #+#             */
/*   Updated: 2018/10/06 13:18:29 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "error.h"
#include "libft.h"
#include "types.h"
#include "internal.h"

int		main(int ac, char **av)
{
	double	theta0;
	double	theta1;
	double	price;
	double	margin;

	if (ac != 2)
		return (1);
	if (!ft_get_theta(&theta0, &theta1, &margin))
	{
		FT_WARNING("ft_get_theta() %s", "failed");
		return (1);
	}

	price = ESTIMATE_PRICE(ft_atoi(av[1]));

	if (!margin)
		printf("\033[38;5;27m%0.2f\033[0m€\n", price);
	else
		printf("\033[38;5;27m%0.2f\033[0m€ (\033[38;5;245m+/-\033[0m \033[38;5;141m%0.1f\033[0m%% -> Entre \033[38;5;196m%0.2f\033[0m€ et \033[38;5;46m%0.2f\033[0m€)\n", price, margin, price - (price * margin / 100), price + (price * margin / 100));
	return (0);
}
