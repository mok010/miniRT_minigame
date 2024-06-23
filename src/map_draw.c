#include "../include/so_long.h"

void	set_moving(t_info *info, char dir)
{
	info->moving = dir;
	info->moving2 = dir;
	info->moving3 = dir;
}

void	check_file_ber(t_info *info, char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		error_print(info, "file is not ber", 0);
	if (filename[len - 2] != 'e')
		error_print(info, "file is not ber", 0);
	if (filename[len - 3] != 'b')
		error_print(info, "file is not ber", 0);
	if (filename[len - 4] != '.')
		error_print(info, "file is not ber", 0);
}

void	draw_what(t_info *info, int i, int j)
{
	if ((info->map)[i][j] == 'C')
		draw_coin1(info, j, i, 0);
	else if ((info->map)[i][j] == 'P')
		draw_ali(info, j, i, 0);
	else if ((info->map)[i][j] == 'E')
		draw_f1(info, j, i, 0);
	else if ((info->map)[i][j] == '1')
		draw_w1(info, j, i, 0);
	else if ((info->map)[i][j] == 'N')
		draw_ene(info, "./img/coin2.xpm", 0, 0);
}

void	draw_img(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (info->h))
	{
		while (j < (info->w -1))
		{
			draw_wtr(info, j, i, 0);
			j++;
		}
		i++;
		j = 0;
	}
	i = -1;
	while (++i < (info->h))
	{
		while (j < (info->w))
		{
			draw_what(info, i, j);
			j++;
		}
		j = 0;
	}
}
