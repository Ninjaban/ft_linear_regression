/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:28:41 by nathan            #+#    #+#             */
/*   Updated: 2018/09/25 12:29:20 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "error.h"
#include "types.h"

/*
** -- basic check
*/
typedef char		t__check_for_ft_nm_true[(TRUE == 1) ? 1 : -1];
typedef char		t__check_for_ft_nm_false[(FALSE == 0) ? 1 : -1];

/*
**	ft_map_file()
**
**	map a file descriptor in memory and set the buffer with the value.
**
**	@param		fd		file descriptor
**	@param		size	file size
**	@param		file	out buffer
**
**	@return	TRUE in success, FALSE otherwise
*/

extern t_bool		ft_map_file(const char *path, t_buffer *file)
{
	int				fd;
	void			*bytes;
	struct stat		buf;
	size_t			size;

	if (file == NULL)
	{
		FT_ERROR("file %p", file);
		return (FALSE);
	}
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		FT_ERROR("open() failed path %s", path);
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

/*
**	ft_unmap_file()
**
**	release memory of a maped file.
**
**	@param		file	in buffer
**
**	@return	TRUE in success, FALSE otherwise
*/

extern t_bool		ft_unmap_file(t_buffer *file)
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