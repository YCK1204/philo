#include "../Header/Philo.h"

void	set_queue(t_data *data, t_queue *job_queue)
{
	job_queue->head = NULL;
	job_queue->tail = NULL;
	job_queue->head = (t_node *)malloc(sizeof(t_node));
	if (!job_queue->head)
		occur_exception(data);
	job_queue->tail = (t_node *)malloc(sizeof(t_node));
	if (!job_queue->tail)
		occur_exception(data);
	job_queue->head->next = job_queue->tail;
	job_queue->head->prev = NULL;
	job_queue->tail->next = NULL;
	job_queue->tail->prev = job_queue->head;
	job_queue->pop = &pop;
	job_queue->push = &push;
}

void	set_philo(t_data *data)
{
	int	i;

	data->philos = NULL;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philos)
		occur_exception(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].eat_cnt = 0;
		data->philos[i].last_eat_time = 0;
		data->philos[i].state = ALIVE;
		data->philos[i].left = i;
		data->philos[i].right = i + 1;
		if (i == data->num_of_philo - 1)
			data->philos[i].right = 0;
		i++;
	}
}

void	set_forks(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(\
		sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->forks)
		occur_exception(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			occur_exception(data);
		i++;
	}
}

void	init(t_data *data, t_queue *job_queue, char *av[])
{
	check_exception(av);
	data->num_of_philo = ft_atoi(av[1]);
	data->time.die = ft_atoi(av[2]);
	data->time.eat = ft_atoi(av[3]);
	data->time.sleep = ft_atoi(av[4]);
	data->least_eat_cnt = -1;
	data->die = false;
	if (av[5])
		data->least_eat_cnt = ft_atoi(av[5]);
	data->start_time = get_time();
	data->job_queue = job_queue;
	data->state = ALIVE;
	data->forks = NULL;
	data->ate_philo_cnt = 0;
	if (pthread_mutex_init(&data->push, NULL) != 0)
		occur_exception(data);
	set_queue(data, job_queue);
	set_philo(data);
	set_forks(data);
}
