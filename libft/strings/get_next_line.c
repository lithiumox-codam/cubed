/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 23:39:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/17 17:41:22 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief A scuffed memcpy that copies the remaining buffer to the beginning.
 *
 * @param x The struct containing the concat variables.
 * @param bufflen The length of the buffer.
 * @param buff The buffer to copy from.
 */
static void	ft_copy_magic(t_concat *x, int bufflen, char *buff)
{
	while (x->j < bufflen && buff[x->j] != '\0' && !x->found)
	{
		x->new[x->i] = buff[x->j];
		if (x->new[x->i] == '\n')
			x->found = 1;
		x->i++;
		x->j++;
	}
}

/**
 * @brief A function to elongate the line with the buffer.
 *
 * @param line The line to elongate.
 * @param buff The buffer to elongate the line with.
 * @param bufflen The length of the buffer.
 * @return char* The new line.
 */
static char	*concat(char *line, char *buff, int bufflen)
{
	t_concat	v;

	v.i = 0;
	v.found = 0;
	v.j = 0;
	if (!bufflen)
		bufflen = 1;
	v.size = bufflen + 1;
	if (line != NULL)
		v.size += ft_strlen(line);
	v.new = ft_calloc(v.size, sizeof(char));
	if (!v.new)
		return (free(line), NULL);
	while (line != NULL && line[v.i])
	{
		v.new[v.i] = line[v.i];
		v.i++;
	}
	ft_copy_magic(&v, bufflen, buff);
	v.new[v.i] = '\0';
	return (free(line), v.new);
}

/**
 * @brief Get the remaining buffer if a newline is found.
 *
 * @note This function is only called when a newline is found in the buffer. And
 * the remaining buffer is put in the beginning of the buffer. This is done so
 * the next call to get_next_line it will read the remaining buffer first.
 *
 * @param buffer
 */
static void	get_remaining_buff(t_gnl *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < buffer->length && buffer->buff[i] != '\n')
		i++;
	if (i < buffer->length)
		i++;
	j = 0;
	while (i < buffer->length)
	{
		buffer->buff[j] = buffer->buff[i];
		i++;
		j++;
	}
	buffer->length = j;
}

/**
 * @brief A wrapper for read() so it modifies the variables in the struct.
 *
 * @param buffer The struct containing the buffer.
 * @param line The line read from the file descriptor.
 * @param fd The file descriptor to read from.
 * @return char* The line read from the file descriptor.
 */
static char	*read_line(t_gnl *buffer, char *line, int fd)
{
	int	found;
	int	bufflen;

	bufflen = 1;
	found = 0;
	while (bufflen > 0 && !found)
	{
		bufflen = read(fd, buffer->buff, BUFFER_SIZE);
		buffer->length = bufflen;
		if (bufflen == 0)
			break ;
		if (bufflen < 0)
		{
			free(line);
			return (NULL);
		}
		line = concat(line, buffer->buff, bufflen);
		if (ft_lstrchr(buffer->buff, '\n', buffer->length))
			found = 1;
		get_remaining_buff(buffer);
	}
	return (line);
}

/**
 * @brief get_next_line reads a line from a file descriptor and returns it.
 *
 * @param fd The file descriptor to read from.
 * @return char* The line read from the file descriptor.
 */
char	*get_next_line(int fd)
{
	static t_gnl	buffer;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer.length > 0)
	{
		if (ft_lstrchr(buffer.buff, '\n', buffer.length))
		{
			line = concat(line, buffer.buff, buffer.length);
			get_remaining_buff(&buffer);
			return (line);
		}
		else
		{
			line = concat(line, buffer.buff, buffer.length);
			buffer.length = 0;
		}
	}
	line = read_line(&buffer, line, fd);
	return (line);
}
