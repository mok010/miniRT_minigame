#include "../include/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strjoin_free_check(int flag, char *str1, char *str2)
{
	if (flag == 1 && str1 != 0)
		free(str1);
	else if (flag == 2 && str2 != 0)
		free(str2);
	else if (flag == 3 && str1 != 0 && str2 != 0)
	{
		free(str1);
		free(str2);
	}
}

char	*ft_strjoin(char *str1, char *str2, int flag)
{
	char	*return_str;
	int		i;
	int		index;

	i = 0;
	index = 0;
	return_str = 0;
	return_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (return_str == 0)
		return (0);
	while (str1 != 0 && str1[index] != '\0')
	{
		return_str[i] = str1[index++];
		i++;
	}
	index = 0;
	while (str2 != 0 && str2[index] != '\0')
	{
		return_str[i] = str2[index++];
		i++;
	}
	return_str[i] = '\0';
	ft_strjoin_free_check(flag, str1, str2);
	return (return_str);
}

void	clean_buff(int count, char *buff)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		buff[i] = '\0';
		i++;
	}
}

char	*make_substr(int start, int end, char *str)
{
	char	*substr;
	int		i;

	i = 0;
	substr = 0;
	substr = (char *)malloc(end - start + 2);
	if (substr == 0)
		return (0);
	while (start <= end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
