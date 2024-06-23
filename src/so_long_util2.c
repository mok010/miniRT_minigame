#include "../include/so_long.h"

int	check_hit_wall(int x_plus, int y_plus, t_info *info)
{
	if ((info->map)[(info->p_x) + x_plus][(info->p_y) + y_plus] == 1)
		return (-1);
	return (0);
}

void	visited_arr_unit(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	info->visited = (char **)malloc(sizeof(char *) * (info->h + 1));
	if (info->visited == 0)
		error_print(info, "malloc error", 0);
	while (i < (info->h))
	{
		info->visited[i] = (char *)malloc(sizeof(char) * (info->w));
		if (info->visited[i] == 0)
			error_print(info, "malloc error", 0);
		i++;
	}
	i = 0;
	info->visited[info->h] = 0;
	while (i < info->h)
	{
		while (++j < (info->w))
			info->visited[i][j] = '0';
		i++;
		j = -1;
	}
}

void	map_to_arry_util(char ***map_t, t_info *info, int *i)
{
	int	j;

	j = 0;
	while ((info->map)[*i] != 0)
	{
		while ((info->map)[*i][j] != '\0' && (info->map)[*i][j] != '\n')
		{
			(*map_t)[*i][j] = (info->map)[*i][j];
			j++;
		}
		(*map_t)[*i][j] = (info->map)[*i][j];
		j = 0;
		(*i)++;
	}
}

void	transfer_arry(t_info *info, char **map_t, char *str)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	map_t[info->h] = 0;
	if (info->map != 0)
		map_to_arry_util(&map_t, info, &i);
	while (str[j] != '\0' && str[j] != '\n')
	{
		map_t[i][j] = str[j];
		j++;
	}
	map_t[i][j] = str[j];
	map_t[++i] = 0;
	tmp = info->map;
	info->map = map_t;
	free_2_level_arr(tmp);
}

void	map_to_arry(char *str, t_info *info)
{
	int		i;
	char	**map_t;

	i = 0;
	map_t = 0;
	map_t = (char **)malloc(sizeof(char *) * ((info->h) + 1));
	if (map_t == 0)
		error_print(info, "map_to_array", 0);
	while ((i) < info->h)
	{
		map_t[i] = (char *)malloc(sizeof(char) * (info->w));
		if (map_t[i] == 0)
			error_print(info, "map_to_array", 0);
		i++;
	}
	transfer_arry(info, map_t, str);
}
