/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:40:40 by jilin             #+#    #+#             */
/*   Updated: 2025/04/25 16:52:47 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

s_struct s_philo
{
	int				id;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*die_mutex;
	pthread_t		thread_id;
}	t_philo;





#endif