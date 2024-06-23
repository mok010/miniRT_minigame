#include "../include/so_long.h"

void	ani_w(t_info *info)
{
	if ((info->moving) != '0' && ((info->ani / 1000) == 0))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_w1(info, info->p_x, info->p_y, 0);
		info->moving = '0';
	}
	else if ((info->moving2) != '0' && ((info->ani / 1000) == 1))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_w2(info, info->p_x, info->p_y, 0);
		info->moving2 = '0';
	}
	else if ((info->moving3) != '0' && ((info->ani / 1000) == 2))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_w1(info, info->p_x, info->p_y, 0);
		info->moving3 = '0';
	}
}

void	ani_s(t_info *info)
{
	if ((info->moving) != '0' && ((info->ani / 1000) == 0))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_s1(info, info->p_x, info->p_y, 0);
		info->moving = '0';
	}
	else if ((info->moving2) != '0' && ((info->ani / 1000) == 1))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_s2(info, info->p_x, info->p_y, 0);
		info->moving2 = '0';
	}
	else if ((info->moving3) != '0' && ((info->ani / 1000) == 2))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_s1(info, info->p_x, info->p_y, 0);
		info->moving3 = '0';
	}
}

void	ani_a(t_info *info)
{
	if ((info->moving) != '0' && ((info->ani / 1000) == 0))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_l1(info, info->p_x, info->p_y, 0);
		info->moving = '0';
	}
	else if ((info->moving2) != '0' && ((info->ani / 1000) == 1))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_l2(info, info->p_x, info->p_y, 0);
		info->moving2 = '0';
	}
	else if ((info->moving3) != '0' && ((info->ani / 1000) == 2))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_l3(info, info->p_x, info->p_y, 0);
		info->moving3 = '0';
	}
}

void	ani_d(t_info *info)
{
	if ((info->moving) != '0' && (info->ani / 1000 == 0))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_r2(info, info->p_x, info->p_y, 0);
		info->moving = '0';
	}
	else if ((info->moving2) != '0' && (info->ani / 1000 == 1))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_r3(info, info->p_x, info->p_y, 0);
		info->moving2 = '0';
	}
	else if ((info->moving3) != '0' && (info->ani / 1000 == 2))
	{
		draw_wtr(info, info->p_x, info->p_y, 0);
		draw_ali_r1(info, info->p_x, info->p_y, 0);
		info->moving3 = '0';
	}
}

void	ani_e(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (info->map[info->p_y][info->p_x] == 'E')
		return ;
	while (i < (info->h - 1))
	{
		while (j < (info->w))
		{
			if (info->map[i][j] == 'E')
			{
				draw_wtr(info, j, i, 0);
				if (info->ani == 1000)
					draw_f1(info, j, i, 0);
				else
					draw_f2(info, j, i, 0);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
