#include "../Header/Philo.h"

void	push(t_queue *job_queue, t_cmd *cmd)
{
	t_node	*prev;
	t_node	*job;

	job = (t_node *)malloc(sizeof(t_node));
	if (!job)
		exit(1);
	job->cmd = cmd;
	prev = job_queue->tail->prev;
	prev->next = job;
	job->prev = prev;
	job->next = job_queue->tail;
	job_queue->tail->prev = job;
}

t_node	*pop(t_queue *job_queue)
{
	t_node	*ret;

	ret = job_queue->head->next;
	if (ret == job_queue->tail)
		return (NULL);
	job_queue->head->next = ret->next;
	ret->next->prev = job_queue->head;
	return (ret);
}
