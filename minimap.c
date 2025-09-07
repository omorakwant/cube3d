/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:29:49 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 01:08:49 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->tile_size)
	{
		j = 0;
		while (j < data->tile_size)
		{
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_data *data)
{
	int	row;
	int	col;
	int	x;
	int	y;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			x = col * data->tile_size;
			y = row * data->tile_size;
			if (data->map[row][col] == '1')
				draw_square(data, x, y, 0xFFFFFF);
			else if (data->map[row][col] == '0')
				draw_square(data, x, y, 0x000000);
			else if (data->map[row][col] == 'P')
				draw_square(data, x, y, 0xFF0000);
			col++;
		}
		row++;
	}
}
