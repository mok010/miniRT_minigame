#include "../include/so_long.h"

static int	ft_countword(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (n > -10)
			count--;
		n = n / 10;
		count += 2;
	}
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		i;

	i = 0;
	count = ft_countword(n);
	result = (char *)malloc((count) * (sizeof(char)));
	if (result == NULL)
		return (0);
	result[count - 1] = '\0';
	while (count - 2 - i >= 0)
	{
		result[count - 2 - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (result);
}

char	*gsr(t_info *info)
{
	char	*get_string;
	char	*tmp;

	get_string = 0;
	tmp = 0;
	tmp = ft_strjoin("rest coin : ", ft_itoa(info->c_cnt), 2);
	get_string = ft_strjoin(tmp, " move : ", 1);
	tmp = 0;
	tmp = ft_strjoin(get_string, ft_itoa(info->m_cnt), 3);
	get_string = 0;
	return (tmp);
}

void	reset_str(t_info *info, int flag)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while ((i) < (info->w - 1))
	{
		if (info->ani == 3000)
			draw_w1(info, i, 0, 0);
		else
			draw_w2(info, i, 0, 0);
		i++;
	}
	if (flag == 1)
	{
		info->moving = '0';
		write(1, "rest coin : ", 13);
		ft_putstr_fd(ft_itoa(info->c_cnt), 1);
		write(1, " move : ", 9);
		ft_putstr_fd(ft_itoa(info->m_cnt), 1);
		write(1, "\n", 1);
	}
	tmp = gsr(info);
	mlx_string_put(info->mlx, info->win, 10, 10, 0xFFFFFF, tmp);
	free(tmp);
}
