/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <yeckim@student.42seoul.kr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/10 15:34:17 by yeckim			#+#	#+#			 */
/*   Updated: 2024/02/24 00:09:39 by yeckim           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../Header/Philo.h"

void	*start_routine(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	philo->last_eat_time = get_time();
	if (philo->id % 2 == 0)
		usleep(data->time.eat * 800);
	while (philo->state == ALIVE)
	{
		t_philo_eat(data, philo);
		t_philo_sleep(data, philo);
		t_philo_think(data, philo);
		usleep(200);
	}
	_push_2(data, philo->state);
	return (NULL);
}

void	finish_routine(t_data *data, pthread_t *philos)
{
	long	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
}

void	check_philos(t_data *data)
{
	t_node	*job;

	while (data->state == ALIVE)
	{
		usleep(100);
		pthread_mutex_lock(&data->push);
		job = data->job_queue->pop(data->job_queue);
		pthread_mutex_unlock(&data->push);
		if (job == NULL)
			continue ;
		job->cmd->execute(job->cmd);
		free(job->cmd);
		free(job);
	}
}

void	create_philos(t_data *data)
{
	pthread_t	*philos;
	int			i;

	philos = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!philos)
		occur_exception(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&philos[i], NULL, (void *)start_routine, \
					&data->philos[i]) != 0)
			occur_exception(data);
		i++;
	}
	check_philos(data);
	finish_routine(data, philos);
	free(philos);
}
