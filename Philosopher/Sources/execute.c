#include "../Header/Philo.h"

void	print_msg(t_cmd *_cmd)
{
	t_print_msg	*cmd;

	cmd = (t_print_msg *)_cmd;
	printf("%ld %ld ", cmd->time - cmd->data->start_time, cmd->id);
	if (cmd->type == FORK)
		printf("has taken a fork\n");
	else if (cmd->type == EAT)
		printf("is eating\n");
	else if (cmd->type == SLEEP)
		printf("is sleeping\n");
	else if (cmd->type == THINK)
		printf("is thinking\n");
	else if (cmd->type == DIED)
	{
		cmd->data->die = true;
		printf("die\n");
	}
}

void	check_finished_philo_state(t_cmd *_cmd)
{
	t_check_state	*cmd;

	cmd = (t_check_state *)_cmd;
	if (cmd->state == FINISH)
		cmd->data->ate_philo_cnt++;
	if (cmd->data->ate_philo_cnt == cmd->data->num_of_philo)
		cmd->data->state = FINISH;
}

void	change_state_to_die(t_cmd *_cmd)
{
	t_change_state_to_die	*cmd;

	cmd = (t_change_state_to_die *)_cmd;
	cmd->data->state = DIE;
}
