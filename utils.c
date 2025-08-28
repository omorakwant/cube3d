/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:46:40 by odahriz           #+#    #+#             */
/*   Updated: 2025/08/28 09:51:59 by odahriz          ###   ########.fr       */
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

int	handle_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	init_map_data(t_data *data)
{
	char	**map_data;

	map_data = malloc(sizeof(char *) * 17);
	map_data[0] = "11111111111111111111";
	map_data[1] = "10000000000000000001";
	map_data[2] = "10110000000000011001";
	map_data[3] = "10100000000000010001";
	map_data[4] = "10110000000000011001";
	map_data[5] = "10000000000000000001";
	map_data[6] = "10000011111100000001";
	map_data[7] = "10000010000100000001";
	map_data[8] = "10000010P00100000001";
	map_data[9] = "10000010000100000001";
	map_data[10] = "10000011111100000001";
	map_data[11] = "10000000000000000001";
	map_data[12] = "10110000000000011001";
	map_data[13] = "10100000000000010001";
	map_data[14] = "10110000000000011001";
	map_data[15] = "11111111111111111111";
	map_data[16] = NULL;
	data->map = map_data;
	data->map_width = get_map_width(map_data);
	data->map_height = get_map_height(map_data);
	data->tile_size = calculate_tile_size(data);
}
