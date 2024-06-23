#include "../include/so_long.h"

int	count_end_point(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	plyer_on_exit(t_info *info)
{
	if (info->map[info->p_y][info->p_x] == 'E')
	{
		draw_wtr(info, info->p_x, info->p_y, 1);
		draw_f1(info, info->p_x, info->p_y, 1);
	}
	else
		draw_wtr(info, info->p_x, info->p_y, 1);
}

void	free_2_level_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == 0)
		return ;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	arr = 0;
}
