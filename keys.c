/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:44:19 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 18:01:18 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deal_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	else if (key == 124)
		move_x_right(data);
	else if (key == 123)
		move_x_left(data);
	else if (key == 126)
		move_y_up(data);
	else if (key == 125)
		move_y_down(data);
	else if (key == 43 || key == 47)
		change_size(data, key);
	else if (key == 13 || key == 11 || key == 15)
		change_color(data, key);
	return (0);
}

int			mouse_drag(int x, int y, t_data *data)
{
	if ((x < 900 && x > 0) && (y < 900 && y > 0))
	{
		if (x > data->mouse_x)
			data->int_real_change += 0.01;
		else
			data->int_real_change -= 0.01;
		if (y > data->mouse_y)
			data->int_imagine_change += 0.001;
		else
			data->int_imagine_change -= 0.001;
	}
	data->mouse_x = x;
	data->mouse_y = y;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
	return (0);
}

void		mouse_manage_if(int mousecode, int x, int y, t_data *data)
{
	double mouse_re;
	double mouse_im;

	mouse_re = (double)x / (data->w_width / (data->maxreal - data->minreal))
	+ data->minreal;
	mouse_im = (double)y / (data->w_height / (data->maximagine
	- data->minimagine)) + data->minimagine;
	if (mousecode == 1 || mousecode == 5)
	{
		data->zoom = 1.05;
		zoom(mouse_re, mouse_im, data);
	}
	else if (mousecode == 2 || mousecode == 4)
	{
		data->zoom = 1.0 / 1.05;
		zoom(mouse_re, mouse_im, data);
	}
}

int			mouse_manage(int mousecode, int x, int y, t_data *data)
{
	if (ft_strcmp(data->name_of_fractol, "mandelbrot") == 0)
	{
		mouse_manage_if(mousecode, x, y, data);
	}
	else if (ft_strcmp(data->name_of_fractol, "julia") == 0)
	{
		if (mousecode == 1 || mousecode == 5)
			data->zoom *= 1.05;
		else if (mousecode == 2 || mousecode == 4)
			data->zoom /= 1.05;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
	return (0);
}
