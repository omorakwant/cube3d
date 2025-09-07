/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:30:00 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 08:53:29 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	handle_movement(t_data *data)
{
	int	new_x;
	int	new_y;
	int	moved;

	if (data->move_timer > 0)
	{
		data->move_timer--;
		return ;
	}
	new_x = data->player_x;
	new_y = data->player_y;
	moved = 0;
	if (data->key_w && !moved)
	{
		new_y--;
		moved = 1;
	}
	else if (data->key_s && !moved)
	{
		new_y++;
		moved = 1;
	}
	else if (data->key_a && !moved)
	{
		new_x--;
		moved = 1;
	}
	else if (data->key_d && !moved)
	{
		new_x++;
		moved = 1;
	}
	if (moved && is_valid_move(data, new_x, new_y))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_x = new_x;
		data->player_y = new_y;
		data->map[data->player_y][data->player_x] = 'P';
		data->move_timer = MOVE_DELAY;
		mlx_clear_window(data->mlx, data->win);
		render_minimap(data);
	}
}

int	handle_key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == W_KEY)
		data->key_w = 1;
	else if (keycode == S_KEY)
		data->key_s = 1;
	else if (keycode == A_KEY)
		data->key_a = 1;
	else if (keycode == D_KEY)
		data->key_d = 1;
	return (0);
}

int	handle_key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == W_KEY)
		data->key_w = 0;
	else if (keycode == S_KEY)
		data->key_s = 0;
	else if (keycode == A_KEY)
		data->key_a = 0;
	else if (keycode == D_KEY)
		data->key_d = 0;
	return (0);
}

int	update_game(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	handle_movement(data);
	return (0);
}

int	handle_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
