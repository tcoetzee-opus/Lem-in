











#include "includes/libft.h"
#include <stdio.h>

static void	new_lst(t_dlist **new, int fd)
{
	*new = (t_dlist *)malloc(sizeof(**new));
	(*new)->result = ft_strnew(0);
	(*new)->fd = fd;
	(*new)->next = NULL;
}

static void	multi_fd_gnl(t_dlist **new, t_dlist **new2, int fd)
{
	static t_dlist	*begin;

	if (begin)
	{
		*new = begin;
		while (*new != NULL)
		{
			if ((*new)->fd == fd)
				break ;
			*new2 = *new;
			*new = (*new)->next;
		}
		if (*new == NULL)
		{
			new_lst(new, fd);
			(*new2)->next = *new;
		}
	}
	else
	{
		new_lst(new, fd);
		begin = *new;
	}
}

static int	backslash_in_buffer(char *buffer, int length, t_dlist **new,
		char **line)
{
	char	*temp;
	size_t	n;

	n = 0;
	temp = NULL;
	if (buffer[0] == '\0')
		return (-1);
	buffer[length] = '\0';
	if ((*new)->result == NULL)
		(*new)->result = ft_strdup("");
	if (ft_strchr(buffer, '\n'))
	{
		n = (size_t)ft_strclen(buffer, '\n');
		buffer[n] = '\0';
		*line = ft_strjoin((*new)->result, buffer);
		free((*new)->result);
		(*new)->result = ft_strdup(&buffer[n + 1]);
		free(buffer);
		return (1);
	}
	temp = (*new)->result;
	(*new)->result = ft_strjoin((*new)->result, buffer);
	free(temp);
	return (0);
}

static int	backslash_in_rest(int fd, char **line, t_dlist **new, char **buffer)
{
	size_t		n;
	char		*temp;
	t_dlist		*new2;

	temp = NULL;
	new2 = NULL;
	*line = NULL;
	multi_fd_gnl(new, &new2, fd);
	*buffer = ft_strnew(BUFF_SIZE);
	if ((*new)->result && ft_strchr((*new)->result, '\n'))
	{
		n = (size_t)ft_strclen((*new)->result, '\n');
		(*new)->result[n] = '\0';
		*line = ft_strdup((*new)->result);
		temp = (*new)->result;
		(*new)->result = ft_strdup(&(*new)->result[n + 1]);
		free(temp);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	t_gnl			gnl;

	gnl.length = 0;
	gnl.ret = -1;
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if ((backslash_in_rest(fd, line, &gnl.new, &gnl.buffer)) == 1)
		return (1);
	while ((gnl.length = (int)read(fd, gnl.buffer, BUFF_SIZE)) > 0)
	{
		gnl.ret = backslash_in_buffer(gnl.buffer, gnl.length, &gnl.new, line);
		if (gnl.ret == 1 || gnl.ret == -1)
			return (gnl.ret);
	}
	if (gnl.length < 0 ||
			((gnl.new->result && (*line = ft_strdup(gnl.new->result)) == NULL)))
		return (-1);
	free(gnl.new->result);
	free(gnl.buffer);
	gnl.buffer = NULL;
	gnl.new->result = NULL;
	if (gnl.length == 0 && *line && (*line)[0] != '\0')
		return (1);
	return (0);
}
