#include "../include/so_long.h"

void	draw_coin1(t_info *info, int x, int y, int move)
{
	void	*ig_c1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/coin1.xpm";
	ig_c1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_c1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_c1, (bit) * x, (bit) * y);
}

void	draw_coin2(t_info *info, int x, int y, int move)
{
	void	*ig_c2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/coin2.xpm";
	ig_c2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_c2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_c2, (bit) * x, (bit) * y);
}

void	draw_f1(t_info *info, int x, int y, int move)
{
	void	*ig_f1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/flag1.xpm";
	ig_f1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_f1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = 'E';
	mlx_put_image_to_window(t_mlx, t_win, ig_f1, (bit) * x, (bit) * y);
}

void	ani_w_c(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < (info->h))
	{
		while (++j < (info->w))
		{
			if (info->map[i][j] == 'C')
				draw_wtr(info, j, i, 0);
			if (info->map[i][j] == 'C' && info->ani == 1000)
				draw_coin1(info, j, i, 0);
			else if (info->map[i][j] == 'C' && info->ani == 3000)
				draw_coin2(info, j, i, 0);
		}
		j = -1;
	}
	if (info->ani == 3000)
		info->ani = 0;
}
