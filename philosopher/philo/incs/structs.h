/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:53:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/25 20:24:53 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "stddef.h"
# include "sys/time.h"

typedef enum	ebool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef struct	s_philo
{
	size_t			id;
	struct timeval	time_ate;
}	t_philo;

typedef struct	s_info
{
	size_t	num_of_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	num_to_eat;
	t_philo	*philos;
}	t_info;

#endif