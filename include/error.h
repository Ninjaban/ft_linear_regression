/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 10:09:56 by jcarra            #+#    #+#             */
/*   Updated: 2018/06/22 13:17:45 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <inttypes.h>
# include <stdint.h>
# include <stdarg.h>

#define FT_DEBUG(in_context, ...)															\
	do {																					\
	(void) fprintf (stderr, "DEBUG:%s:%" PRIu64 ":%s: " in_context "\n",					\
					__FILE__, (uint64_t)__LINE__, __func__,									\
					__VA_ARGS__);															\
	} while (0)

#define FT_WARNING(in_context, ...)															\
	do {																					\
	(void) fprintf (stderr, "WARNING:%s:%" PRIu64 ":%s: " in_context "\n",					\
					__FILE__, (uint64_t)__LINE__, __func__,									\
					__VA_ARGS__);															\
	} while (0)

#define FT_ERROR(in_context, ...)															\
	do {																					\
	(void) fprintf (stderr, "ERROR:%s:%" PRIu64 ":%s: " in_context "\n",					\
					__FILE__, (uint64_t)__LINE__, __func__,									\
					__VA_ARGS__);															\
	} while (0)

# define	DEBUG_MODE		TRUE

#endif
