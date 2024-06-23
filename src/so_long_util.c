#include "../include/so_long.h"

int	lose_game(t_info *info)
{
	write(1, "LOSE:(\n", 7);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

int	win_game(t_info *info)
{
	write(1, "WIN!\n", 4);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

void	ft_putstr_fd(char *s, int flag)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	if (flag == 1 && s != 0)
		free(s);
}

void	error_print(t_info *info, char *str, int flag)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 0);
	write(1, "\n", 1);
	if (flag == 0 && info->mlx != 0 && info->win != 0)
		mlx_destroy_window(info->mlx, info->win);
	exit(1);
}

void	info_init(t_info *info)
{
	info->map = 0;
	info->visited = 0;
	info->mlx = 0;
	info->win = 0;
	info->done = 0;
	info->ani = 0;
	info->ani_ene = 0;
	info->moving = '0';
	info->moving2 = '0';
	info->moving3 = '0';
	info->h = 0;
	info->w = 0;
	info->p_x = 0;
	info->p_y = 0;
	info->n_x = 0;
	info->n_y = 0;
	info->n_cnt = 0;
	info->p_cnt = 0;
	info->c_cnt = 0;
	info->e_cnt = 0;
	info->m_cnt = 0;
	info->bt = 32;
}
