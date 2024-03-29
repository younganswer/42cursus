/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_2_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:14:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool	push_2_a_to_b(t_var *var, t_shape shape)
{
	pb(var);
	pb(var);
	if ((var->b->tail->val < var->b->tail->prev->val && shape == REVERSED) \
		|| (var->b->tail->prev->val < var->b->tail->val && shape == NORMAL))
		sb(var);
	return (TRUE);
}
