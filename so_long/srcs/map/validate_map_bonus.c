/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:39:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 00:26:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			validate_map(t_game *game);
static t_bool	border_is_not_valid(t_map *map);
static t_bool	check(t_game *game, t_chk_map **chk_map);
static t_bool	check_data(t_game *game, t_chk_map *chk_map, const char c);
static t_bool	char_is_not_valid(const char c);

t_bool	validate_map(t_game *game)
{
	t_chk_map	*chk_map;

	chk_map = 0;
	if (game->map->size.x < 3 || game->map->size.y < 3 || \
		game->map->size.x * game->map->size.y < 15)
	{
		free_all(game);
		exit_with_error("Error\nMap must be larger than 3x5.\n");
	}
	if (border_is_not_valid(game->map))
	{
		free_all(game);
		exit_with_error("Error\nBorder is not valid.\n");
	}
	check(game, &chk_map);
	if (!chk_map->exit || !chk_map->player || !chk_map->collects)
	{
		free(chk_map);
		free_all(game);
		exit_with_error("Error\nMap is not valid.\n");
	}
	game->collects = chk_map->collects;
	free(chk_map);
	return (TRUE);
}

static t_bool	border_is_not_valid(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->size.x)
	{
		if (!x || x == map->size.x - 1)
		{
			y = -1;
			while (++y < map->size.y)
				if (map->saved[x][y] != '1')
					return (TRUE);
		}
		else
		{
			if (map->saved[x][0] != '1')
				return (TRUE);
			if (map->saved[x][map->size.y - 1] != '1')
				return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	check(t_game *game, t_chk_map **chk_map)
{
	int	i;
	int	j;

	*chk_map = (t_chk_map *) malloc(sizeof(t_chk_map));
	if (!(*chk_map))
	{
		free_all(game);
		exit_with_error("Error\nFail to malloc at chk_map.\n");
	}
	(*chk_map)->collects = 0;
	(*chk_map)->exit = 0;
	(*chk_map)->player = FALSE;
	i = 0;
	while (i < game->map->size.x)
	{
		j = 0;
		while (j < game->map->size.y)
		{
			check_data(game, *chk_map, game->map->saved[i][j]);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_bool	check_data(t_game *game, t_chk_map *chk_map, const char c)
{
	if (char_is_not_valid(c))
	{
		free(chk_map);
		free_all(game);
		exit_with_error("Error\nMap character is not valid.\n");
	}
	if (c == 'P')
	{
		if (!chk_map->player)
			chk_map->player = TRUE;
		else
		{
			free(chk_map);
			free_all(game);
			exit_with_error("Error\nThere must be only one player.\n");
		}
	}
	if (c == 'E')
		chk_map->exit++;
	if (c == 'C')
		chk_map->collects++;
	return (TRUE);
}

static t_bool	char_is_not_valid(const char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'G' || c == 'E')
		return (FALSE);
	return (TRUE);
}
