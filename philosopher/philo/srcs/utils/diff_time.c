/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:04:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 17:10:16 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"
#include <stdio.h>

size_t	diff_time(struct timeval *tv);

size_t	diff_time(struct timeval *tv)
{
	struct timeval	cur;
	size_t			ret;

	gettimeofday(&cur, NULL);
	ret = (cur.tv_sec - tv->tv_sec) * 1000;
	ret += (cur.tv_usec - tv->tv_usec) / 1000;
	printf("ret: %zu\n", ret);
	return (ret);
}
