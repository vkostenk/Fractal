/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:02:08 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 17:24:40 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_size(t_data *data, int key)
{
	if (key == 43)
		data->change_side--;
	else
		data->change_side++;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
}

void		move_x_right(t_data *data)
{
	data->change_x = data->change_x - 0.01;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
}

void		move_x_left(t_data *data)
{
	data->change_x = data->change_x + 0.01;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
}

void		move_y_up(t_data *data)
{
	data->change_y = data->change_y + 0.01;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
}

void		move_y_down(t_data *data)
{
	data->change_y = data->change_y - 0.01;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
}
