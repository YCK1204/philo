/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yeckim <yeckim@student.42seoul.kr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/10 15:34:17 by yeckim			#+#	#+#			 */
/*   Updated: 2024/02/24 00:09:13 by yeckim           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../Header/Philo.h"

int	main(int ac, char *av[])
{
	t_data	data;
	t_queue	job_queue;

	if (ac != 5 && ac != 6)
	{
		printf("Input count have to be 5 or 6, but only %d \
				inputs were provided", ac);
		return (1);
	}
	init(&data, &job_queue, av);
	create_philos(&data);
	clear_queue(&data);
	free_all(&data);
	return (0);
}
