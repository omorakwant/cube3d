/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:30:00 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 01:19:23 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	handle_movement_keys(t_data *data, int keycode,
				int *new_x, int *new_y)
{
	if (keycode == W_KEY)
		(*new_y)--;
	else if (keycode == S_KEY)
		(*new_y)++;
	else if (keycode == A_KEY)
		(*new_x)--;
	else if (keycode == D_KEY)
		(*new_x)++;
}

static void	update_player_position(t_data *data, int new_x, int new_y)
{
	data->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[data->player_y][data->player_x] = 'P';
	mlx_clear_window(data->mlx, data->win);
	render_minimap(data);
}

int	handle_key(int keycode, void *param)
{
	t_data	*data;
	int		new_x;
	int		new_y;

	data = (t_data *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	new_x = data->player_x;
	new_y = data->player_y;
	handle_movement_keys(data, keycode, &new_x, &new_y);
	if (is_valid_move(data, new_x, new_y))
		update_player_position(data, new_x, new_y);
	return (0);
}

int	handle_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
