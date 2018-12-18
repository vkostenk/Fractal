/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:36:15 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 18:01:07 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_julia(t_data *data)
{
	data->int_real = -0.7 + data->int_real_change;
	data->int_imagine = 0.27015 + data->int_imagine_change;
	data->max_iterations = 250;
	data->x = 100;
	data->y = 100;
}

double		calc_real_julia(t_data *data)
{
	double res;

	res = 1.5 * (data->x - data->w_width / 2) /
		(0.5 * data->zoom * data->w_width) + data->change_x;
	return (res);
}

double		calc_imagine_julia(t_data *data)
{
	double res;

	res = (data->y - data->w_height / 2) /
		(0.5 * data->zoom * data->w_height) + data->change_y;
	return (res);
}

int			calc_num_julia(t_data *data)
{
	int i;

	i = 0;
	while (i < data->max_iterations && data->maxreal * data->maxreal +
			data->maximagine * data->maximagine < 4.0)
	{
		data->minreal = data->maxreal;
		data->minimagine = data->maximagine;
		data->maxreal = data->minreal * data->minreal -
			data->minimagine * data->minimagine + data->int_real;
		data->maximagine = 2 * data->minreal *
			data->minimagine + data->int_imagine;
		i++;
	}
	return (i);
}

void		draw_julia(t_data *data)
{
	int num;

	init_julia(data);
	while (data->y < data->w_height)
	{
		while (data->x < data->w_width)
		{
			data->maxreal = calc_real_julia(data);
			data->maximagine = calc_imagine_julia(data);
			num = calc_num_julia(data);
			if (num < data->max_iterations)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr,
						data->x, data->y, data->color * num);
			data->x++;
		}
		data->x = 100;
		data->y++;
	}
}
