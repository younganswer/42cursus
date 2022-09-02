/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 16:27:10 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		sz_;

	if (argc < 3)
		ft_exit_with_error(0, EXIT_SUCCESS);
	a = init_stack();
	b = init_stack();
	arr = parse_input(a, argc, argv);
	sz_ = a->sz_;
	for (int i=0; i<sz_; i++) {
		ft_printf("%d ", arr[i]);
	}
	ft_printf("\n");
	print_stack(a);
	(void) arr;
	(void) b;
	return (0);
}
