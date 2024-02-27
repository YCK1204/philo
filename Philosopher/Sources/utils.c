/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <yeckim@student.42seoul.kr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/10 15:34:17 by yeckim			#+#	#+#			 */
/*   Updated: 2023/02/21 16:49:58 by yeckim		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../Header/Philo.h"

int	ft_atoi(char *n)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (n[i])
	{
		if (!(48 <= n[i] && n[i] <= 57))
			exit(1);
		ret = ret * 10 + (n[i] - '0');
		i++;
	}
	return (ret);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		exit(1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*space_trim(char *str)
{
	int		start;
	int		end;
	int		i;
	char	*ret;

	start = 0;
	end = (int)(ft_strlen(str) - 1);
	while (str[start] && start < end && str[start] == ' ')
		start++;
	while (end > 0 && end > start && str[end] == ' ')
		end--;
	ret = (char *)malloc(end - start + 2);
	if (!ret)
		exit(1);
	i = 0;
	while (str[start] && start <= end)
		ret[i++] = str[start++];
	ret[i] = 0;
	return (ret);
}

void	check_exception(char *av[])
{
	av[1] = space_trim(av[1]);
	av[2] = space_trim(av[2]);
	av[3] = space_trim(av[3]);
	av[4] = space_trim(av[4]);
	if (av[5])
		av[5] = space_trim(av[5]);
}

long long	get_time(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return (temp.tv_sec * 1000 + temp.tv_usec / 1000);
}
