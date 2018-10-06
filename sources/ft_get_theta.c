/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_theta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:57:43 by nathan            #+#    #+#             */
/*   Updated: 2018/10/06 12:21:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static t_bool		ft_map(t_buffer *file)
{
	int				fd;
	void			*bytes;
	struct stat		buf;
	size_t			size;

	if ((fd = open(THETA_FILE, O_RDONLY)) == -1)
	{
		FT_ERROR("open() failed path %s", THETA_FILE);
		return (FALSE);
	}
	if (fstat(fd, &buf) == -1)
	{
		FT_ERROR("fstat() failed fd %d", fd);
		return (FALSE);
	}
	size = (size_t)buf.st_size;
	FT_DEBUG("File size %ld", size);
	if (!(bytes = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0)))
	{
		FT_ERROR("mmap() failed size %zu fd %d", size, fd);
		return (FALSE);
	}
	FT_DEBUG("file : %.*s", (unsigned int)size, (char *)bytes);
	BUFFER_SETUP(*file, size, bytes);
	return (TRUE);
}

static t_bool		ft_unmap(t_buffer *file)
{
	if ((*file).bytes == NULL)
	{
		FT_ERROR("(*file).bytes %p", (*file).bytes);
		return (FALSE);
	}

	if (munmap((*file).bytes, (*file).size) == -1)
	{
		FT_ERROR("munmap() failed bytes {%.*s} size %" PRIu32, (*file).size, (t_pchar)(*file).bytes, (*file).size);
		return (FALSE);
	}
	BUFFER_CLEAR(*file);
	return (TRUE);
}

extern t_bool		ft_get_theta(double *out_theta0, double *out_theta1, double *out_margin)
{
	t_buffer		file;
	t_pchar			ptr;
	t_pchar			ptr2;

	if (!ft_map(&file))
	{
		FT_WARNING("ft_map() %s", "failed");
		return (FALSE);
	}

	ptr = (t_pchar)ft_strchr(file.bytes, ',');
	*ptr = '\0';
	ptr2 = (t_pchar)ft_strchr(ptr + 1, ',');
	*ptr2 = '\0';
	*out_theta0 = atof(file.bytes);
	*out_theta1 = atof(ptr + 1);
	*out_margin = atof(ptr2 + 1);
	FT_DEBUG("theta0 %f theta1 %f", *out_theta0, *out_theta1);

	if (!ft_unmap(&file))
	{
		FT_WARNING("ft_unmap() %s", "failed");
		return (FALSE);
	}
	return (TRUE);
}
