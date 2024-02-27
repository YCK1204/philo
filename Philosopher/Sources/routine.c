/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   routine.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/24 00:02:57 by yeckim			#+#	#+#			 */
/*   Updated: 2024/02/28 00:25:58 by yeckim           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../Header/Philo.h"
#include <sys/wait.h>
#include <unistd.h>

void	_push_job(t_data *data, t_cmd *cmd)
{
	pthread_mutex_lock(&data->push);
	data->job_queue->push(data->job_queue, cmd);
	pthread_mutex_unlock(&data->push);
}

void	check_time(t_data *data, t_philo *philo, long time_of_wait, \
long last_eat_time)
{
	long	start;
	long	cur_time;

	start = get_time();
	while (1)
	{
		cur_time = get_time();
		if (time_of_wait <= cur_time - start)
			break ;
		if (cur_time - last_eat_time >= data->time.die)
			break ;
		usleep(100);
	}
	if (cur_time - last_eat_time >= data->time.die)
	{
		philo->state = DIE;
		_push_1(data, get_time(), philo->id, DIED);
		_push_3(data);
	}
}

void	t_philo_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->left]);
	_push_1(data, get_time(), philo->id, FORK);
	pthread_mutex_lock(&data->forks[philo->right]);
	_push_1(data, get_time(), philo->id, FORK);
	_push_1(data, get_time(), philo->id, EAT);
	philo->last_eat_time = get_time();
	check_time(data, philo, data->time.eat, philo->last_eat_time);
	pthread_mutex_unlock(&data->forks[philo->right]);
	pthread_mutex_unlock(&data->forks[philo->left]);
	philo->eat_cnt++;
	if (philo->eat_cnt == data->least_eat_cnt)
		philo->state = FINISH;
}

void	t_philo_sleep(t_data *data, t_philo *philo)
{
	if (philo->state != ALIVE)
		return ;
	_push_1(data, get_time(), philo->id, SLEEP);
	check_time(data, philo, data->time.sleep, philo->last_eat_time);
}

void	t_philo_think(t_data *data, t_philo *philo)
{
	if (philo->state != ALIVE)
		return ;
	_push_1(data, get_time(), philo->id, THINK);
}
