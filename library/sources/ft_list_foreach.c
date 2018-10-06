/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:40:12 by jcarra            #+#    #+#             */
/*   Updated: 2018/02/26 14:46:06 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_lst *begin_list, void (*f)(void *))
{
	t_lst	*elem;

	elem = begin_list;
	while (elem != NULL)
	{
		(*f)(elem->data);
		elem = elem->next;
	}
}
