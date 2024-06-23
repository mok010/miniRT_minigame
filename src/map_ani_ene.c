#include "../include/so_long.h"

int	draw_ene_util(t_info *info, int x_p, int y_p, void *img)
{
	int		*x;
	int		*y;
	void	*t_mlx;
	void	*t_win;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	x = &(info->n_x);
	y = &(info->n_y);
	if ((info->map[*y][*x] == 'N') && (x_p == 0) && (y_p == 0))
	{
		mlx_put_image_to_window(t_mlx, t_win, img, (bit) * (*x), (bit) * (*y));
		return (1);
	}
	if (info->map[(*y) + y_p][(*x) + x_p] != '0')
	{
		if (info->map[(*y) + y_p][(*x) + x_p] == 'P')
			lose_game(info);
		else
			return (1);
	}
	return (0);
}

void	draw_ene(t_info *info, char *file, int x_p, int y_p)
{
	void	*img;
	void	*t_mlx;
	int		bit;
	int		*x;
	int		*y;

	img = 0;
	bit = info->bt;
	t_mlx = info->mlx;
	x = &(info->n_x);
	y = &(info->n_y);
	img = mlx_xpm_file_to_image(t_mlx, file, &(bit), &(bit));
	if (img == NULL)
		error_print(info, "draw_ene", 0);
	if (draw_ene_util(info, x_p, y_p, img) == 1)
		return ;
	draw_wtr(info, *x, *y, 1);
	(info->n_x) += x_p;
	(info->n_y) += y_p;
	info->map[*y][*x] = 'N';
	mlx_put_image_to_window(t_mlx, info->win, img, (bit) * (*x), (bit) * (*y));
}

void	ene_dir2(t_info *info)
{
	int		*x;
	int		*y;
	char	**mp;

	mp = info->map;
	x = &(info->n_x);
	y = &(info->n_y);
	if (40 <= (info->ani_ene / 1000) && (info->ani_ene / 1000) < 60)
	{
		if (mp[(*y)][(*x) - 1] != '0' && mp[(*y)][(*x) - 1] != 'P')
			info->ani_ene = 70000;
		else
			draw_ene(info, "./img/ene_a1.xpm", -1, 0);
	}
	else if (60 <= (info->ani_ene / 1000) && (info->ani_ene / 1000) < 80)
	{
		if (mp[(*y) + 1][*x] != '0' && mp[(*y) + 1][*x] != 'P')
			info->ani_ene = 10000;
		else
			draw_ene(info, "./img/ene_s1.xpm", 0, 1);
	}
	return ;
}

void	ene_dir1(t_info *info)
{
	int		*x;
	int		*y;
	char	**mp;

	mp = info->map;
	x = &(info->n_x);
	y = &(info->n_y);
	if ((info->ani_ene / 1000) < 20)
	{
		if (mp[(*y)][(*x) + 1] != '0' && mp[(*y)][(*x) + 1] != 'P')
			info->ani_ene = 30000;
		else
			draw_ene(info, "./img/ene_d1.xpm", 1, 0);
	}
	else if ((info->ani_ene / 1000) < 40)
	{
		if (mp[(*y) - 1][*x] != '0' && mp[(*y) - 1][*x] != 'P')
			info->ani_ene = 50000;
		else
			draw_ene(info, "./img/ene_w1.xpm", 0, -1);
	}
	ene_dir2(info);
}

int	ene_contrl(t_info *info)
{
	if (info->n_x == 0 && info->n_y == 0)
		return (0);
	if ((info->p_x == info->n_x) && (info->p_y == info->n_y))
		lose_game(info);
	info->ani_ene += 1;
	if (((info->ani_ene / 1000) * 1000) == info->ani_ene)
	{
		ene_dir1(info);
	}
	if (info->ani_ene == 100000)
		info->ani_ene = 0;
	return (0);
}
