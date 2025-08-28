/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:33:42 by odahriz           #+#    #+#             */
/*   Updated: 2025/08/28 09:51:15 by odahriz          ###   ########.fr       */
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
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		tile_size;
}			t_data;

void	render_minimap(t_data *data);
void	init_map_data(t_data *data);
int		get_map_width(char **map);
int		get_map_height(char **map);
int		calculate_tile_size(t_data *data);
int		handle_key(int keycode, void *param);

#endif