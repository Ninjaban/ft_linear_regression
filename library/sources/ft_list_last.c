/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:10:26 by jcarra            #+#    #+#             */
/*   Updated: 2018/02/26 13:44:32 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst	*ft_list_last(t_lst *begin_list)
{
	t_lst	*last;

	last = begin_list;
	if (begin_list == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
