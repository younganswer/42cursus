/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:45:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 01:03:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include "so_long.h"

t_bool	init_img(t_game *game);
t_bool	init_collect_imgs(t_game *game);
t_bool	init_exit_imgs(t_game *game);
t_bool	init_player_imgs(t_game *game);
t_bool	init_player_down_imgs(t_game *game);
t_bool	init_player_left_imgs(t_game *game);
t_bool	init_player_right_imgs(t_game *game);
t_bool	init_player_up_imgs(t_game *game);

#endif