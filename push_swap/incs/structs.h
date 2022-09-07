/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:18:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 21:44:34 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	sz_;
}	t_stack;

typedef struct s_arr
{
	int		*chunk;
	size_t	sz_;
}	t_arr;

typedef struct s_var
{
	t_stack	*a;
	t_stack	*b;
	t_arr	*arr;
}	t_var;

#endif