#include "../include/so_long.h"

void	maze_dfs_util(t_info *info, int i, int j, t_dfs *dfs_tool)
{
	if ((i < 1) || (i > (info->h - 1)))
		return ;
	if ((j > ((info->w) - 2)) || (j < 1))
		return ;
	if ((info->map[i][j] != '1') && (info->visited[i][j] == '0'))
	{
		info->visited[i][j] = '1';
		maze_dfs(info, i, j, dfs_tool);
	}
}

void	maze_dfs(t_info *info, int x, int y, t_dfs *dfs_tool)
{
	if (info->map[x][y] == 'C')
	{
		dfs_tool->check_coin += 1;
	}
	else if (info->map[x][y] == 'E')
	{
		dfs_tool->check_exit += 1;
	}
	maze_dfs_util(info, (x + 1), (y), dfs_tool);
	maze_dfs_util(info, (x - 1), (y), dfs_tool);
	maze_dfs_util(info, (x), (y + 1), dfs_tool);
	maze_dfs_util(info, (x), (y - 1), dfs_tool);
}

void	dfs_test(t_info *info)
{
	t_dfs	dfs_tool;

	dfs_tool.check_coin = 0;
	dfs_tool.check_exit = 0;
	maze_dfs(info, info->p_y, info->p_x, &dfs_tool);
	if (dfs_tool.check_coin != info->c_cnt)
		error_print(info, "no route coin", 0);
	else if (dfs_tool.check_exit != info->e_cnt)
		error_print(info, "no route exit", 0);
}

void	check_cnt_obj_util(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'C')
		info->c_cnt++;
	else if (info->map[i][j] == 'P')
	{
		info->p_cnt++;
		info->p_x = j;
		info->p_y = i;
	}
	else if (info->map[i][j] == 'E')
		info->e_cnt++;
	else if (info->map[i][j] == 'N')
	{
		info->n_cnt++;
		info->n_x = j;
		info->n_y = i;
	}
	else if (info->map[i][j] != '1' && info->map[i][j] != '0')
		error_print(info, "Wrong word in map!", 0);
}

void	check_cnt_obj(t_info *info)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	j = -1;
	while ((++i) < info->h)
	{
		while ((++j) < (info->w - 1))
		{
			cnt = 0;
			free_2_level_arr(info->visited);
			visited_arr_unit(info);
			check_cnt_obj_util(info, i, j);
		}
		j = -1;
	}
	if ((info->c_cnt < 1))
		error_print(info, "cnt_coin_or_ene", 0);
	if ((info->e_cnt != 1) || (info->n_cnt > 1) || (info->p_cnt != 1))
		error_print(info, "please enter one exit, one enermy, one player", 0);
	dfs_test(info);
}
