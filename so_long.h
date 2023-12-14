/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auysal <auysal@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:03 by auysal            #+#    #+#             */
/*   Updated: 2023/11/28 13:44:07 by auysal           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

# define RES 64
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct l_index
{
	int	i;
	int	j;
	int	k;
}	t_index;

typedef struct l_game
{
	int		map_height;
	int		map_width;
	int		collectables;
	int		counter;
	int		player_x;
	int		player_y;

	char	**map;
	char	*maplocation;

	void	*wall;
	void	*player;
	void	*player_img;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
	t_index	index;
}	t_game;

int		exit_point(t_game *data);
int		controls_working(int command, t_game *data);

void	ber_control(char *mapname);
void	txt_control(char *mapname);
void	map_control(char *mapname, t_game *data);
void	wall_control(t_game *data);
void	map_processing(t_game *data);
void	map_reading(t_game *data);
void	error_message(char *msg);
void	images_in_game(t_game *data);
void	image_control(t_game *data);
void	placeholder(t_game *data, int x, int y);
void	adding_graphics(t_game *data);
void	place_player(t_game *data, int width, int height);
void	map_bug(t_game *data);
void	escape_line(t_game *data);
void	mlx_images_free(t_game *data);

#endif
