/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:59:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 16:12:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_node	*init_node(int num, t_shape shape)
{
	t_node	*ret;

	ret = (t_node *) malloc(sizeof(t_node));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ft_memset(ret, 0, sizeof(t_node));
	ret->shape = shape;
	ret->next = 0;
	ret->prev = 0;
	ret->val = num;
	return (ret);
}
