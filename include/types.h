/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 10:10:06 by jcarra            #+#    #+#             */
/*   Updated: 2018/07/04 14:56:21 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdint.h>

# define TRUE		1
# define FALSE		0

typedef char				t_bool;
typedef void *				t_pvoid;
typedef char *				t_pchar;
typedef unsigned char *		t_puchar;
typedef unsigned int		t_uint;
typedef long long			t_long;

typedef struct
{
	t_uint			size;
	t_pvoid			bytes;
} t_buffer;

#define BUFFER_CLEAR(target)					{ (target).size = 0; (target).bytes = NULL; }
#define BUFFER_SETUP(target, size, bytes)		{ (target).size = (size); (target).bytes = (bytes); }
#define BUFFER_CHECK(target)					{ (((target).size != 0) && ((target).bytes != NULL)) }

#endif
