#include "../include/so_long.h"

void	draw_ali_r2(t_info *info, int x, int y, int move)
{
	void	*ig_pr2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	t_mlx = info->mlx;
	t_win = info->win;
	bit = info->bt;
	name = "./img/ali_r2.xpm";
	ig_pr2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pr2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pr2, (bit) * x, (bit) * y);
}

void	draw_ali_r1(t_info *info, int x, int y, int move)
{
	void	*ig_pr1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/ali_r1.xpm";
	ig_pr1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pr1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pr1, (bit) * x, (bit) * y);
}

void	draw_ali_s1(t_info *info, int x, int y, int move)
{
	void	*ig_ps1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/ali_s1.xpm";
	ig_ps1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_ps1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_ps1, (bit) * x, (bit) * y);
}

void	draw_ali_s2(t_info *info, int x, int y, int move)
{
	void	*ig_ps2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/ali_s2.xpm";
	ig_ps2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_ps2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_ps2, (bit) * x, (bit) * y);
}

void	draw_ali_w1(t_info *info, int x, int y, int move)
{
	void	*ig_pw1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	bit = info->bt;
	t_mlx = info->mlx;
	t_win = info->win;
	name = "./img/ali_w1.xpm";
	ig_pw1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pw1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pw1, (bit) * x, (bit) * y);
}
