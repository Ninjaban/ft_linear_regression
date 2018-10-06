/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:44:46 by jcarra            #+#    #+#             */
/*   Updated: 26 12018/02/26 14:02:20jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int		ft_revnbr(unsigned long int nbr)
{
	unsigned long int	rev;

	rev = 1;
	while (nbr > 0)
	{
		rev = rev * 10 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (rev);
}
