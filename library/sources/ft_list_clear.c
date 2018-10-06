/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:35:16 by jcarra            #+#    #+#             */
/*   Updated: 2018/02/26 126 15:38:06 by jcarra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_lst **begin_list, void (*f)(void *))
{
	t_lst	*elem;
	t_lst	*next;

	if (!begin_list || !(*begin_list))
		return ;
	elem = *begin_list;
	while (elem != NULL)
	{
		next = elem->next;
		ft_list_del(elem, f);
		elem = next;
	}
	*begin_list = NULL;
}
