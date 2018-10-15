/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 10:09:56 by jcarra            #+#    #+#             */
/*   Updated: 2018/10/15 11:52:10 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <inttypes.h>
# include <stdint.h>
# include <stdarg.h>

#define FT_DEBUG(in_context, ...)																																	\
	do {																																							\
	(void) fprintf (stderr, "\033[38;5;14mDEBUG\033[0m:\033[38;5;244m%s\033[0m:\033[38;5;227m%" PRIu64 "\033[0m:\033[38;5;40m%s\033[0m: " in_context "\n",			\
					__FILE__, (uint64_t)__LINE__, __func__,																											\
					__VA_ARGS__);																																	\
	} while (0)

#define FT_WARNING(in_context, ...)																																	\
	do {																																							\
	(void) fprintf (stderr, "\033[38;5;114mWARNING\033[0m:\033[38;5;244m%s\033[0m:\033[38;5;227m%" PRIu64 "\033[0m:\033[38;5;40m%s\033[0m: " in_context "\n",		\
					__FILE__, (uint64_t)__LINE__, __func__,																											\
					__VA_ARGS__);																																	\
	} while (0)

#define FT_ERROR(in_context, ...)																																	\
	do {																																							\
	(void) fprintf (stderr, "\033[38;5;160mERROR\033[0m:\033[38;5;244m%s\033[0m:\033[38;5;227m%" PRIu64 "\033[0m:\033[38;5;40m%s\033[0m: " in_context "\n",			\
					__FILE__, (uint64_t)__LINE__, __func__,																											\
					__VA_ARGS__);																																	\
	} while (0)

# define	DEBUG_MODE		TRUE

#endif
