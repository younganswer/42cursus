/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_left_imgs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 01:10:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:27:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_player_left_imgs(t_game *game);
static t_bool	init_player_left_imgs_04(t_game *game);
static t_bool	init_player_left_imgs_08(t_game *game);

t_bool	init_player_left_imgs(t_game *game)
{
	init_player_left_imgs_04(game);
	init_player_left_imgs_08(game);
	return (TRUE);
}

static t_bool	init_player_left_imgs_04(t_game *game)
{
	game->img->player[0] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[1] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[2] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[3] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player[0] || !game->img->player[1] || \
		!game->img->player[2] || !game->img->player[3])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player left images.\n");
	}
	return (TRUE);
}

static t_bool	init_player_left_imgs_08(t_game *game)
{
	game->img->player[4] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[5] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[6] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[7] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/left/p_left08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player[4] || !game->img->player[5] || \
		!game->img->player[6] || !game->img->player[7])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player left images.\n");
	}
	return (TRUE);
}
