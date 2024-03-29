/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_up_imgs_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 01:04:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:27:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_player_up_imgs(t_game *game);
static t_bool	init_player_up_imgs_28(t_game *game);
static t_bool	init_player_up_imgs_32(t_game *game);

t_bool	init_player_up_imgs(t_game *game)
{
	init_player_up_imgs_28(game);
	init_player_up_imgs_32(game);
	return (TRUE);
}

static t_bool	init_player_up_imgs_28(t_game *game)
{
	game->img->player[24] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[25] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[26] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[27] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player[24] || !game->img->player[25] || \
		!game->img->player[26] || !game->img->player[27])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player up images.\n");
	}
	return (TRUE);
}

static t_bool	init_player_up_imgs_32(t_game *game)
{
	game->img->player[28] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[29] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[30] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[31] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/up/p_up08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player[28] || !game->img->player[29] || \
		!game->img->player[30] || !game->img->player[31])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player up images.\n");
	}
	return (TRUE);
}
