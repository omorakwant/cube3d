/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:33:42 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 08:53:29 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <mlx.h>

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define MOVE_DELAY 8000

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		tile_size;
	int		player_x;
	int		player_y;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		move_timer;
}			t_data;

void	render_minimap(t_data *data);
void	init_map_data(t_data *data);
int		get_map_width(char **map);
int		get_map_height(char **map);
int		calculate_tile_size(t_data *data);
int		handle_key(int keycode, void *param);
int		handle_close(void *param);
void	find_player_position(t_data *data);
int		is_valid_move(t_data *data, int new_x, int new_y);
int		handle_key_press(int keycode, void *param);
int		handle_key_release(int keycode, void *param);
int		update_game(void *param);
void	init_keys(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);

#endif