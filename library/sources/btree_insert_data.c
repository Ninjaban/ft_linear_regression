/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 10:49:39 by jcarra            #+#    #+#             */
/*   Updated: 2018/02/26 11:54:59 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	t_btree	*tree;
	int		exit;

	exit = 0;
	tree = *root;
	if (tree && cmpf)
		while (exit == 0)
		{
			if (cmpf(tree->item, item) < 0)
			{
				if (tree->left != NULL)
					tree = tree->left;
				else
					tree->left = btree_create_node(item);
			}
			else
			{
				if (tree->right != NULL)
					tree = tree->right;
				else
					tree->right = btree_create_node(item);
			}
		}
}
