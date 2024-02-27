/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <yeckim@student.42seoul.kr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/10 15:34:17 by yeckim			#+#	#+#			 */
/*   Updated: 2024/02/28 00:28:56 by yeckim           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

typedef struct s_cmd
{
	void	(*execute)(struct s_cmd *);
}	t_cmd;

typedef struct s_node
{
	t_cmd			*cmd;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_q
{
	void	(*push)(struct s_q *, t_cmd *);
	t_node	*(*pop)(struct s_q *);
	t_node	*head;
	t_node	*tail;
}	t_queue;

void	print_msg(t_cmd *cmd);
void	push(t_queue *job_queue, t_cmd *cmd);
t_node	*pop(t_queue *job_queue);

#endif
