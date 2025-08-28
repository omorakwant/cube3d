/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:33:06 by odahriz           #+#    #+#             */
/*   Updated: 2025/08/28 09:50:05 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	t_data	data;

	init_map_data(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cube3d");
	if (data.win == NULL)
		return (1);
	mlx_key_hook(data.win, handle_key, &data);
	render_minimap(&data);
	mlx_loop(data.mlx);
}
