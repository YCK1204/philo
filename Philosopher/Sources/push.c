#include "../Header/Philo.h"

void	_push(t_data *data, t_cmd *cmd)
{
	pthread_mutex_lock(&data->push);
	data->job_queue->push(data->job_queue, (t_cmd *)cmd);
	pthread_mutex_unlock(&data->push);
}

void	_push_1(t_data *data, long time, long id, t_msg_type type)
{
	t_print_msg	*cmd;

	cmd = (t_print_msg *)malloc(sizeof(t_print_msg));
	if (!cmd)
		exit(1);
	cmd->base.execute = print_msg;
	cmd->id = id;
	cmd->time = time;
	cmd->type = type;
	cmd->data = data;
	_push(data, (t_cmd *)cmd);
}

void	_push_2(t_data *data, t_state state)
{
	t_check_state	*cmd;

	cmd = (t_check_state *)malloc(sizeof(t_check_state));
	if (!cmd)
		exit(1);
	cmd->base.execute = check_finished_philo_state;
	cmd->state = state;
	cmd->data = data;
	_push(data, (t_cmd *)cmd);
}

void	_push_3(t_data *data)
{
	t_change_state_to_die	*cmd;

	cmd = (t_change_state_to_die *)malloc(sizeof(t_change_state_to_die));
	if (!cmd)
		exit(1);
	cmd->base.execute = change_state_to_die;
	cmd->data = data;
	_push(data, (t_cmd *)cmd);
}
