/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <yeckim@student.42seoul.kr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/10 15:34:17 by yeckim			#+#	#+#			 */
/*   Updated: 2024/02/24 00:07:28 by yeckim           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../Header/Philo.h"

void	clear_queue(t_data *data)
{
	t_node	*job;

	job = data->job_queue->pop(data->job_queue);
	while (job != NULL && job != data->job_queue->tail && data->die == false)
	{
		job->cmd->execute(job->cmd);
		free(job->cmd);
		free(job);
		job = data->job_queue->pop(data->job_queue);
	}
	if (data->state == FINISH)
	{
		while (job != NULL && job != data->job_queue->tail)
		{
			job->cmd->execute(job->cmd);
			free(job->cmd);
			free(job);
			job = data->job_queue->pop(data->job_queue);
		}
	}
}

void	occur_exception(t_data *data)
{
	free_all(data);
	exit(1);
}

void	free_all(t_data *data)
{
	t_node	*node;
	t_node	*next;

	node = data->job_queue->head;
	while (node)
	{
		next = node->next;
		free(node->cmd);
		free(node);
		node = next;
	}
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}
