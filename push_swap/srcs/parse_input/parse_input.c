/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:26:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/14 21:11:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

t_bool			parse_input(t_stack *a, int argc, char **argv);
static char		**split_argv(char *input);
static void		push_arguments_to_stack(t_stack *a, char **splited_argv);
static t_bool	is_not_integer(const char *input);

t_bool	parse_input(t_stack *a, int argc, char **argv)
{
	char	**splited_argv;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (is_not_integer(argv[i]))
			ft_exit_with_error(0, EXIT_SUCCESS);
		splited_argv = split_argv(argv[i]);
		push_arguments_to_stack(a, splited_argv);
		j = 0;
		while (splited_argv[j])
		{
			free(splited_argv[j]);
			j++;
		}
		free(splited_argv);
	}
	return (TRUE);
}

static char	**split_argv(char *input)
{
	char		**ret;
	size_t		i;

	if (is_not_integer(input))
		ft_exit_with_error(0, EXIT_SUCCESS);
	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	ret = ft_split(&input[i], ' ');
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	return (ret);
}

static void	push_arguments_to_stack(t_stack *a, char **splited_argv)
{
	int	i;

	i = 0;
	while (splited_argv[i])
	{
		push_front(a, init_node(ft_atoi(splited_argv[i]), NORMAL, 0));
		i++;
	}
	return ;
}

static t_bool	is_not_integer(const char *input)
{
	size_t	len;
	size_t	i;
	size_t	num_of_integer;

	len = ft_strlen(input);
	i = 0;
	num_of_integer = 0;
	while (i < len)
	{
		if (input[i] == ' ' || input[i] == '+' || input[i] == '-')
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(input[i]))
			return (TRUE);
		num_of_integer++;
		i++;
	}
	return (!num_of_integer);
}
