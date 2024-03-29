/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:15:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/02 14:48:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_exit_with_error(const char *str, const int exit_flag)
{
	ft_putstr_fd("\033[31mError\033[0m\n", 2);
	if (str)
	{
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m\n", 2);
	}
	exit(exit_flag);
}
