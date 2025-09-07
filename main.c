/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:33:06 by odahriz           #+#    #+#             */
/*   Updated: 2025/09/07 08:43:35 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	t_data	data;

	init_map_data(&data);
	init_keys(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cube3d");
	if (data.win == NULL)
		return (1);
	mlx_hook(data.win, 2, 1L << 0, handle_key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, handle_key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, handle_close, &data);
	mlx_loop_hook(data.mlx, update_game, &data);
	render_minimap(&data);
	mlx_loop(data.mlx);
}
