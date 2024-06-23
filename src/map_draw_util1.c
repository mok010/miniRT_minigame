#include "../include/so_long.h"

void	draw_ali(t_info *info, int x, int y, int move)
{
	void	*ig_p;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	t_mlx = info->mlx;
	t_win = info->win;
	bit = info->bt;
	name = "./img/ali.xpm";
	ig_p = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_p == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = 'P';
	mlx_put_image_to_window(t_mlx, t_win, ig_p, (bit) * x, (bit) * y);
}

void	draw_ali_l1(t_info *info, int x, int y, int move)
{
	void	*ig_pl1;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	t_mlx = info->mlx;
	t_win = info->win;
	bit = info->bt;
	name = "./img/ali_l1.xpm";
	ig_pl1 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pl1 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pl1, (bit) * x, (bit) * y);
}

void	draw_ali_l2(t_info *info, int x, int y, int move)
{
	void	*ig_pl2;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	t_mlx = info->mlx;
	t_win = info->win;
	bit = info->bt;
	name = "./img/ali_l2.xpm";
	ig_pl2 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pl2 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pl2, (bit) * x, (bit) * y);
}

void	draw_ali_l3(t_info *info, int x, int y, int move)
{
	void	*ig_pl3;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	t_mlx = info->mlx;
	t_win = info->win;
	bit = info->bt;
	name = "./img/ali_l3.xpm";
	ig_pl3 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pl3 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pl3, (bit) * x, (bit) * y);
}

void	draw_ali_r3(t_info *info, int x, int y, int move)
{
	void	*ig_pr3;
	void	*t_mlx;
	void	*t_win;
	char	*name;
	int		bit;

	t_mlx = info->mlx;
	t_win = info->win;
	bit = info->bt;
	name = "./img/ali_r3.xpm";
	ig_pr3 = mlx_xpm_file_to_image(t_mlx, name, &(bit), &(bit));
	if (ig_pr3 == NULL)
		error_print(info, "draw_img", 0);
	if (move == 1)
		info->map[y][x] = '0';
	mlx_put_image_to_window(t_mlx, t_win, ig_pr3, (bit) * x, (bit) * y);
}
