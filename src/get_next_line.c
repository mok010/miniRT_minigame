#include "../include/so_long.h"

int	line_maker(char	**line, char **storage, int	*end_point, int	*all_size)
{
	char	*tmp_stg;

	tmp_stg = 0;
	(*line) = make_substr(0, (*end_point), (*storage));
	if (*line == 0)
	{
		free((*storage));
		(*storage) = 0;
		return (0);
	}
	if (((*end_point) < (*all_size)) && (*storage)[(*end_point) + 1] != '\0')
	{
		tmp_stg = make_substr((*end_point) + 1, (*all_size), (*storage));
		if (tmp_stg == 0)
		{
			free(*line);
			(*line) = 0;
			free((*storage));
			(*storage) = 0;
			return (0);
		}
	}
	free((*storage));
	(*storage) = tmp_stg;
	return (1);
}

int	free_all(char **line, char **storage)
{
	if ((*storage) != 0)
		free((*storage));
	(*storage) = 0;
	if ((*line) != 0)
		free((*line));
	(*line) = 0;
	return (0);
}

int	return_str(char **line, char **storage, char *buff, int *flag)
{
	int		end_point;
	int		all_size;
	char	*all_str;

	end_point = 0;
	all_str = 0;
	all_str = ft_strjoin((*storage), buff, 0);
	if (all_str == 0)
		return (free_all(line, storage));
	if ((*storage) != 0)
		free((*storage));
	(*storage) = all_str;
	end_point = count_end_point((*storage));
	all_size = ft_strlen((*storage));
	if ((end_point == all_size) && (*flag) == 1)
	{
		(*line) = (*storage);
		(*storage) = 0;
		return (1);
	}
	if (end_point < all_size)
		(*flag) = 1;
	if ((*flag) == 1)
		return (line_maker(line, storage, &end_point, &all_size));
	return (1);
}

int	can_read(char *buff, char **storage, char **line, int *read_size)
{
	int	flag;

	flag = 0;
	if ((*read_size) == 0 && (*storage) == 0)
		return (0);
	if (((*read_size) == 0) || (buff[(*read_size) - 1] == '\0'))
		flag = 1;
	if (return_str(line, storage, buff, &flag) == 0)
		return (0);
	if (flag == 1)
	{
		if ((*storage) != 0 && (*storage)[0] == '\0')
		{
			free((*storage));
			(*storage) = 0;
		}
		return (1);
	}
	return (2);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	static char	*storage = 0;
	int			read_size;
	int			tmp;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		read_size = 0;
		clean_buff(BUFFER_SIZE, buff);
		read_size = read(fd, buff, BUFFER_SIZE);
		if ((read_size < 0) && (free_all(&line, &storage) == 0))
			return (0);
		else
		{
			tmp = can_read(&(buff[0]), &storage, &line, &read_size);
			if (tmp == 0)
				return (0);
			else if (tmp == 1)
				return (line);
		}	
	}
}
