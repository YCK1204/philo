/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Philo.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/24 00:02:30 by yeckim			#+#	#+#			 */
/*   Updated: 2024/02/28 00:30:30 by yeckim           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "Structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum s_s		t_state;
typedef enum s_type		t_msg_type;
typedef struct s_t		t_time;
typedef struct s_data	t_data;
typedef struct s_p		t_philo;
typedef struct s_data	t_data;
typedef struct s_t2		t_check_state;
typedef struct s_t1		t_print_msg;

void		free_all(t_data *data);
long long	get_time(void);
int			ft_atoi(char *n);
void		create_philos(t_data *data);
void		check_exception(char *av[]);
void		occur_exception(t_data *data);
void		init(t_data *data, t_queue *job_queue, char *av[]);
void		t_philo_eat(t_data *data, t_philo *philo);
void		t_philo_sleep(t_data *data, t_philo *philo);
void		t_philo_think(t_data *data, t_philo *philo);
void		check_finished_philo_state(t_cmd *_cmd);
void		change_state_to_die(t_cmd *_cmd);
void		_push_1(t_data *data, long time, long id, t_msg_type type);
void		_push_2(t_data *data, t_state state);
void		_push_3(t_data *data);
void		clear_queue(t_data *data);

#endif
