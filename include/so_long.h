#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BIFFER_SIZE 42
# endif
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define BUFFER_SIZE			42

typedef struct s_info{
	char	**map;
	char	**visited;
	void	*mlx;
	void	*win;
	int		done;
	int		ani;
	int		ani_ene;
	char	moving;
	char	moving2;
	char	moving3;
	int		h;
	int		w;
	int		p_x;
	int		p_y;
	int		n_x;
	int		n_y;
	int		n_cnt;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		m_cnt;
	int		bt;
}t_info;

typedef struct s_dfs{
	int	check_coin;
	int	check_exit;
}t_dfs;

int		ft_strlen(char *str);
int		count_end_point(char *str);
char	*ft_strjoin(char *str1, char *str2, int flag);
void	clean_buff(int count, char *buff);
char	*make_substr(int start, int end, char *str);
char	*get_next_line(int fd);
void	free_2_level_arr(char **arr);
int		win_game(t_info *info);
int		lose_game(t_info *info);
void	error_print(t_info *info, char *str, int flag);
void	info_init(t_info *info);
void	ft_putstr_fd(char *s, int flag);
int		horizontal_check(t_info *info);
int		vertical_check(t_info *info);
void	check_width(char *line, t_info *info);
void	check_cnt_obj(t_info *info);
void	maze_dfs(t_info *info, int x, int y, t_dfs *dfs_tool);
void	draw_ali(t_info *info, int x, int y, int move);
int		check_hit_wall(int x_plus, int y_plus, t_info *info);
void	visited_arr_unit(t_info *info);
void	map_to_arry_util(char ***map, t_info *info, int *i);
void	map_to_arry(char *str, t_info *info);
void	draw_ali(t_info *info, int x, int y, int move);
void	draw_ali_l1(t_info *info, int x, int y, int move);
void	draw_ali_l2(t_info *info, int x, int y, int move);
void	draw_ali_l3(t_info *info, int x, int y, int move);
void	draw_ali_r3(t_info *info, int x, int y, int move);
void	draw_ali_r2(t_info *info, int x, int y, int move);
void	draw_ali_r1(t_info *info, int x, int y, int move);
void	draw_ali_s1(t_info *info, int x, int y, int move);
void	draw_ali_s2(t_info *info, int x, int y, int move);
void	draw_ali_w1(t_info *info, int x, int y, int move);
void	draw_ali_w2(t_info *info, int x, int y, int move);
void	draw_wtr(t_info *info, int x, int y, int move);
void	draw_f1(t_info *info, int x, int y, int move);
void	draw_f2(t_info *info, int x, int y, int move);
void	draw_w1(t_info *info, int x, int y, int move);
void	draw_w2(t_info *info, int x, int y, int move);
void	draw_coin1(t_info *info, int x, int y, int move);
void	draw_coin2(t_info *info, int x, int y, int move);
void	ani_w_c(t_info *info);
void	draw_img(t_info *info);
char	*gsr(t_info *info);
void	reset_str(t_info *info, int flag);
void	ani_e(t_info *info);
void	ani_d(t_info *info);
void	ani_a(t_info *info);
void	ani_s(t_info *info);
void	ani_w(t_info *info);
int		ani_contrl(t_info *info);
char	*ft_itoa(int n);
void	set_moving(t_info *info, char dir);
void	check_file_ber(t_info *info, char *filename);
void	ene_dir(t_info *info);
void	draw_ene(t_info *info, char *file, int x_p, int y_p);
int		ene_contrl(t_info *info);
void	plyer_on_exit(t_info *info);

#endif