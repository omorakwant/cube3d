/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:46:40 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 01:19:23 by odahriz          ###   ########.fr       */
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

static void	init_map_rows(char **rows)
{
	rows[0] = "11111111111111111111";
	rows[1] = "10000000000000000001";
	rows[2] = "10110000000000011001";
	rows[3] = "10100000000000010001";
	rows[4] = "10110000000000011001";
	rows[5] = "10000000000000000001";
	rows[6] = "10000011111100000001";
	rows[7] = "10000010000100000001";
	rows[8] = "10000010000100000001";
	rows[9] = "10000010000100000001";
	rows[10] = "10000011111100000001";
	rows[11] = "10000000000000000001";
	rows[12] = "10110000000000011001";
	rows[13] = "10100000000000010001";
	rows[14] = "10110000P00000011001";
	rows[15] = "10000000000000000001";
	rows[16] = "10000011111100000001";
	rows[17] = "10000010000100000001";
	rows[18] = "10000010000100000001";
	rows[19] = "10000010000100000001";
	rows[20] = "10000011111100000001";
	rows[21] = "10000000000000000001";
	rows[22] = "10110000000000011001";
	rows[23] = "11111111111111111111";
}

static void	allocate_map_strings(char **map_data, char **rows)
{
	int	i;

	i = 0;
	while (i < 24)
	{
		map_data[i] = malloc(strlen(rows[i]) + 1);
		strcpy(map_data[i], rows[i]);
		i++;
	}
	map_data[24] = NULL;
}

void	init_map_data(t_data *data)
{
	char	**map_data;
	char	*rows[24];

	init_map_rows(rows);
	map_data = malloc(sizeof(char *) * 25);
	allocate_map_strings(map_data, rows);
	data->map = map_data;
	data->map_width = get_map_width(map_data);
	data->map_height = get_map_height(map_data);
	data->tile_size = calculate_tile_size(data);
	find_player_position(data);
}
	rows[3] = "10100000000000010001";
	rows[4] = "10110000000000011001";
	rows[5] = "10000000000000000001";
	rows[6] = "10000011111100000001";
	rows[7] = "10000010000100000001";
	rows[8] = "10000010000100000001";
	rows[9] = "10000010000100000001";
	rows[10] = "10000011111100000001";
	rows[11] = "10000000000000000001";
	rows[12] = "10110000000000011001";
	rows[13] = "10100000000000010001";
	rows[14] = "10110000P00000011001";
	rows[15] = "10000000000000000001";
	rows[16] = "10000011111100000001";
	rows[17] = "10000010000100000001";
	rows[18] = "10000010000100000001";
	rows[19] = "10000010000100000001";
	rows[20] = "10000011111100000001";
	rows[21] = "10000000000000000001";
	rows[22] = "10110000000000011001";
	rows[23] = "11111111111111111111";
}

static void	allocate_map_strings(char **map_data, char **rows)
{
	int	i;

	i = 0;
	while (i < 24)
	{
		map_data[i] = malloc(strlen(rows[i]) + 1);
		strcpy(map_data[i], rows[i]);
		i++;
	}
	map_data[24] = NULL;
}

void	init_map_data(t_data *data)
{
	char	**map_data;
	char	*rows[24];

	init_map_rows(rows);
	map_data = malloc(sizeof(char *) * 25);
	allocate_map_strings(map_data, rows);
	data->map = map_data;
	data->map_width = get_map_width(map_data);
	data->map_height = get_map_height(map_data);
	data->tile_size = calculate_tile_size(data);
	find_player_position(data);
}
