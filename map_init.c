/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:30:00 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 08:41:24 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
