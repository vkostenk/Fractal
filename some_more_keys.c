/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_more_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:17:51 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 18:01:55 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_color(t_data *data, int key)
{
	if (key == 15)
		data->color = 0xfdd0028;
	if (key == 13)
		data->color = 0xffffff;
	if (key == 11)
		data->color = 0xa050ff;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_fractol(data);
}

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		zoom(int mouse_re, int mouse_im, t_data *data)
{
	double interpolation;

	interpolation = 1.0 / data->zoom;
	data->minreal = interpolate(mouse_re, data->minreal, interpolation);
	data->minimagine = interpolate(mouse_im, data->minimagine, interpolation);
	data->maxreal = interpolate(mouse_re, data->maxreal, interpolation);
	data->maximagine = interpolate(mouse_im, data->maximagine, interpolation);
}
