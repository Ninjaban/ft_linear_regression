/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:05:55 by jcarra            #+#    #+#             */
/*   Updated: 2018/02/26 13:44:32 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_list_size(t_lst *begin_list)
{
	t_lst	*elem;
	int		n;

	n = 1;
	if (begin_list == NULL)
		return (0);
	elem = begin_list;
	while (elem->next != NULL)
	{
		n = n + 1;
		elem = elem->next;
	}
	return (n);
}
