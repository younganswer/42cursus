/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:23:20 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 01:23:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int				end_game(t_game *game);
t_bool			free_all(t_game *game);
static t_bool	free_img(t_objs_img *img);
static t_bool	free_map(t_map *map);

int	end_game(t_game *game)
{
	free_all(game);
	exit(0);
	return (1);
}

t_bool	free_all(t_game *game)
{
	if (!game)
		return (TRUE);
	free_img(game->img);
	free_map(game->map);
	if (game->player)
		free(game->player);
	free(game);
	return (TRUE);
}

static t_bool	free_img(t_objs_img *img)
{
	if (!img)
		return (TRUE);
	free(img);
	return (TRUE);
}

static t_bool	free_map(t_map *map)
{
	int	i;

	if (!map)
		return (TRUE);
	if (map->saved)
	{
		i = 0;
		while (i < map->size.x && map->saved[i])
			free(map->saved[i++]);
		free(map->saved);
	}
	if (map->board)
	{
		i = 0;
		while (i < map->size.x && map->board[i])
			free(map->board[i++]);
		free(map->board);
	}
	free(map);
	return (TRUE);
}
