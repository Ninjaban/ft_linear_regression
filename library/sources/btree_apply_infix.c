/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 09:29:59 by jcarra            #+#    #+#             */
/*   Updated: 2018/02/26 13:44:32 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		btree_apply_infix(root->left, applyf);
		applyf(root);
		btree_apply_infix(root->right, applyf);
	}
}
