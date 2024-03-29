/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:28:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/16 20:01:44 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	ra(t_var *var);
t_bool	rb(t_var *var);
t_bool	rr(t_var *var);

t_bool	ra(t_var *var)
{
	if (var->a->sz_ < 2)
		return (TRUE);
	push_front(var->a, pop_back(var->a));
	if (var->exec_st->sz_ && var->exec_st->tail->exec == RB)
	{
		free(pop_back(var->exec_st));
		push_back(var->exec_st, init_node(0, 0, RR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RA));
	return (TRUE);
}

t_bool	rb(t_var *var)
{
	if (var->b->sz_ < 2)
		return (TRUE);
	push_front(var->b, pop_back(var->b));
	if (var->exec_st->sz_ && var->exec_st->tail->exec == RA)
	{
		free(pop_back(var->exec_st));
		push_back(var->exec_st, init_node(0, 0, RR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RB));
	return (TRUE);
}

t_bool	rr(t_var *var)
{
	if (2 <= var->a->sz_)
		ra(var);
	if (2 <= var->b->sz_)
		rb(var);
	return (TRUE);
}
