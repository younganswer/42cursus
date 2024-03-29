/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:48:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/10 00:50:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

t_bool		has_duplicated(t_stack *a);
static int	*stack_to_arr(t_stack *a);

t_bool	has_duplicated(t_stack *a)
{
	int		*arr;
	size_t	i;

	arr = stack_to_arr(a);
	sort_arr(arr, 0, a->sz_ - 1);
	i = 0;
	while (i < a->sz_ - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (TRUE);
		}
		i++;
	}
	free(arr);
	return (FALSE);
}

static int	*stack_to_arr(t_stack *a)
{
	t_node	*tmp;
	int		*ret;
	int		i;

	ret = (int *) malloc(sizeof(int) * (a->sz_));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	i = 0;
	tmp = a->head;
	while (tmp)
	{
		ret[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (ret);
}
