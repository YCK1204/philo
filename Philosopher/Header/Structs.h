#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "Queue.h"
# include <stdbool.h>

typedef struct s_cmd	t_cmd;
typedef struct s_q		t_queue;

typedef enum s_s
{
	ALIVE,
	DIE,
	FINISH,
}	t_state;

typedef struct s_t
{
	long	die;
	long	eat;
	long	sleep;
}	t_time;

typedef struct s_data	t_data;

typedef struct s_p
{
	long	id;
	long	eat_cnt;
	long	last_eat_time;
	long	left;
	long	right;
	t_state	state;
	t_data	*data;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	push;
	pthread_mutex_t	lock;
	pthread_mutex_t	*forks;
	t_time			time;
	t_state			state;
	long			num_of_philo;
	long			start_time;
	long			least_eat_cnt;
	long			ate_philo_cnt;
	t_queue			*job_queue;
	t_philo			*philos;
	bool			die;
}	t_data;

typedef enum s_type
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED,
}	t_msg_type;

// print state of philo
typedef struct s_t1
{
	t_cmd		base;
	long		time;
	long		id;
	t_msg_type	type;
	t_data		*data;
}	t_print_msg;

// if philo finish, data->ate_philo_cnt++
typedef struct s_t2
{
	t_cmd	base;
	t_state	state;
	t_data	*data;
}	t_check_state;

// change data state to die
typedef struct s_t3
{
	t_cmd	base;
	t_data	*data;
}	t_change_state_to_die;

#endif
