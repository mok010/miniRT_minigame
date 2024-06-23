#include "../include/so_long.h"

void	draw_ali_w2(t_info *info, int x, int y, int move)
{
	void	*ig_pw2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/ali_w2.xpm";
	ig_pw2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pw2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pw2, (bit) * x, (bit) * y);
}

void	draw_wtr(t_info *info, int x, int y, int move)
{
	void	*ig_w;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/water.xpm";
	ig_w = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_w == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_w, (bit) * x, (bit) * y);
}

void	draw_f2(t_info *info, int x, int y, int move)
{
	void	*ig_f2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/flag2.xpm";
	ig_f2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_f2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_f2, (bit) * x, (bit) * y);
}

void	draw_w1(t_info *info, int x, int y, int move)
{
	void	*ig_w1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/wall1.xpm";
	ig_w1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_w1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_w1, (bit) * x, (bit) * y);
}

void	draw_w2(t_info *info, int x, int y, int move)
{
	void	*ig_w2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/wall1.xpm";
	ig_w2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_w2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_w2, (bit) * x, (bit) * y);
}
