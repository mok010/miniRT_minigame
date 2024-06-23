#include "../include/so_long.h"

int	horizontal_check(t_info *info)
{
	int	i;
	int	last;

	i = 0;
	while ((info->map)[0][i] != '\n' && (info->map)[0][i] != '\0')
	{
		if ((info->map)[0][i] != '1')
			error_print(info, "horizontal_check_1", 0);
		i++;
	}
	i = 0;
	last = (info->h) - 1;
	while ((info->map)[last][i] != '\n' && (info->map)[last][i] != '\0')
	{
		if ((info->map)[last][i] != '1')
			error_print(info, "horizontal_check_2", 0);
		i++;
	}
	return (0);
}

int	vertical_check(t_info *info)
{
	int	i;

	i = 0;
	while ((info->map)[i][0] != '\n' && (info->map)[i][0] != '\0')
	{
		if ((info->map)[i][0] != '1')
			error_print(info, "vertical_check_1", 0);
		i++;
		if (info->map[i] == 0)
			break ;
	}
	i = 0;
	while (info->map[i] != 0)
	{
		if ((info->map)[i][(info->w) - 2] != '1')
			error_print(info, "vertical_check_2", 0);
		i++;
	}
	return (0);
}

void	check_width(char *line, t_info *info)
{
	int	wid_cnt;

	wid_cnt = 0;
	if (info->w == 0)
	{
		while (line[wid_cnt] != '\n' && line[wid_cnt] != '\0')
			wid_cnt++;
		wid_cnt++;
		info->w = wid_cnt;
		(info->h)++;
	}
	else
	{
		while (line[wid_cnt] != '\n' && line[wid_cnt] != '\0')
			wid_cnt++;
		wid_cnt++;
		if (info->w != wid_cnt)
			error_print(info, "check_w", 0);
		(info->h)++;
	}
}
