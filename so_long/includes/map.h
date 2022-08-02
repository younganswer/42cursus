/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:17:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/02 12:15:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_tiletype
{
	ROAD = '0',
	WALL = '1',
	COLLECT = 'C',
	PLAYER = 'P',
	EXIT = 'E'
}	t_tiletype;

typedef struct s_tile_img
{
	void	*road_img;
	void	*wall_img;
	void	*collects_img;
	void	*player_img;
	void	*exit_img;
}	t_tile_img;

typedef struct s_tile
{
	t_tiletype	type;
	void		*img;
}	t_tile;

typedef struct s_map
{
	t_coord		size;
	char		**char_map;
	t_tile		**tile_map;
	t_tile_img	*img;
}	t_map;

// init_map.c
t_bool	init_map(t_map *map, int argc, char **argv);
t_bool	file_is_not_valid(char *file);
t_bool	parse_map(t_tile **tile_map, char **char_map);
t_bool	init_img(t_tile_img *img);

// read_map.c
t_bool			read_map_file(char **char_map, char *file);
static t_bool	malloc_file(char **char_map, char *file);
static int		cnt_file_line(char *file);

// map_is_not_valid.c
t_bool	map_is_not_valid(char **char_map);

#endif