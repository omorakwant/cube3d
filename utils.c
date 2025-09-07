/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:46:40 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 08:44:34 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_map_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return (strlen(map[0]));
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	calculate_tile_size(t_data *data)
{
	int	tile_width;
	int	tile_height;

	tile_width = MINIMAP_WIDTH / data->map_width;
	tile_height = MINIMAP_HEIGHT / data->map_height;
	if (tile_width < tile_height)
	{
		if (tile_width > 0)
			return (tile_width);
		return (1);
	}
	if (tile_height > 0)
		return (tile_height);
	return (1);
}

void	find_player_position(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'P')
			{
				data->player_x = col;
				data->player_y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

int	is_valid_move(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= data->map_width)
		return (0);
	if (new_y < 0 || new_y >= data->map_height)
		return (0);
	if (data->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	init_keys(t_data *data)
{
	data->key_w = 0;
	data->key_a = 0;
	data->key_s = 0;
	data->key_d = 0;
	data->move_timer = 0;
}
