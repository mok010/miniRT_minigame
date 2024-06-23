#include "../include/so_long.h"

void	move_player(t_info *info, int m_x, int m_y)
{
	if (info->map[info->p_y + m_y][info->p_x + m_x] == '1')
		return ;
	if (info->map[info->p_y + m_y][info->p_x + m_x] == 'C')
	{
		draw_ali(info, info->p_x + m_x, info->p_y + m_y, 1);
		info->c_cnt--;
	}
	else if (info->map[info->p_y + m_y][info->p_x + m_x] == 'E')
	{
		if (info->c_cnt == 0)
			win_game(info);
		else
		{
			draw_f1(info, info->p_x + m_x, info->p_y + m_y, 1);
			draw_ali(info, info->p_x + m_x, info->p_y + m_y, 0);
		}
	}
	else if (info->map[info->p_y + m_y][info->p_x + m_x] == '0')
		draw_ali(info, info->p_x + m_x, info->p_y + m_y, 1);
	plyer_on_exit(info);
	(info->m_cnt)++;
	info->p_x += m_x;
	info->p_y += m_y;
	if (info->map[info->p_y - m_y][info->p_x - m_x] != 'E')
		draw_wtr(info, info->p_x - m_x, info->p_y - m_y, 0);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		set_moving(info, 'w');
		move_player(info, 0, -1);
	}
	else if (keycode == KEY_S)
	{
		set_moving(info, 's');
		move_player(info, 0, 1);
	}
	else if (keycode == KEY_A)
	{
		set_moving(info, 'a');
		move_player(info, -1, 0);
	}
	else if (keycode == KEY_D)
	{
		set_moving(info, 'd');
		move_player(info, 1, 0);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	ani_contrl(info);
	reset_str(info, 1);
	return (0);
}

void	read_map(char *filename, t_info *info)
{
	int		fd;
	char	*line;

	line = 0;
	check_file_ber(info, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_print(info, "open_error", 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		check_width(line, info);
		map_to_arry(line, info);
		free(line);
	}
	if (info->map[info->h - 1][info->w - 1] != '\0')
		error_print(info, "Wrong_map_format", 0);
	if (info->w > 81 || info->h > 43)
		error_print(info, "Map is too big", 0);
	vertical_check(info);
	horizontal_check(info);
	check_cnt_obj(info);
}

int	ani_contrl(t_info *info)
{
	if (info == 0 || info->mlx == 0 || info->done != 1)
		return (1);
	if ((info->p_x == info->n_x) && (info->p_y == info->n_y))
		lose_game(info);
	ene_contrl(info);
	info->ani += 1;
	if (info->ani == 1000 || info->ani == 3000)
	{
		ani_w_c(info);
		ani_e(info);
	}
	if (info->moving3 != '0')
	{
		if (info->moving3 == 'w')
			ani_w(info);
		else if (info->moving3 == 's')
			ani_s(info);
		else if (info->moving3 == 'd')
			ani_d(info);
		else if (info->moving3 == 'a')
			ani_a(info);
	}
	if (info->ani == 3000)
		info->ani = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		win_w;
	int		win_h;

	if (argc != 2)
		error_print(&info, "main_argc", 1);
	info_init(&info);
	info.mlx = mlx_init();
	if (info.mlx == NULL)
		error_print(&info, "main_mlx_init", 0);
	read_map(argv[1], &info);
	win_h = (info.h) * info.bt;
	win_h = (info.h) * info.bt;
	win_w = (info.w - 1) * info.bt;
	info.win = mlx_new_window(info.mlx, win_w, win_h, "alien");
	if (info.win == NULL)
		error_print(&info, "main_win", 0);
	draw_img(&info);
	info.done = 1;
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &lose_game, &info);
	mlx_loop_hook(info.mlx, &ani_contrl, &info);
	mlx_loop(info.mlx);
}
