/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:02:04 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 18:00:52 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "time.h"

void		init_chaos(t_data *data)
{
	int i;

	data->side = 400.0 + data->change_side;
	data->max_iterations = 100000;
	i = 0;
	while (i < 3)
	{
		data->vert[i][0] = data->w_height / 2 +
			data->side * cos(i * 2 * M_PI / 3);
		data->vert[i][1] = data->w_height / 2 +
			data->side * sin(i * 2 * M_PI / 3);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				data->vert[i][0], data->vert[i][1], data->color);
		i++;
	}
}

void		ft_continue(t_data *data)
{
	int i;

	i = 0;
	while (i < data->max_iterations)
	{
		data->random = rand() % 3;
		data->maxreal = (data->maxreal + data->vert[data->random][0]) / 2;
		data->minreal = (data->minreal + data->vert[data->random][1]) / 2;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				data->maxreal, data->minreal, data->color);
		i++;
	}
}

void		draw_chaos(t_data *data)
{
	time_t	t;

	init_chaos(data);
	srand((unsigned)time(&t));
	data->maxreal = rand() % (int)(data->vert[0][0] / 2
			+ (data->vert[1][0] + data->vert[2][0]) / 4);
	data->minreal = rand() % (int)(data->vert[0][1] / 2
			+ (data->vert[1][1] + data->vert[2][1]) / 4);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			data->maxreal, data->minreal, data->color);
	ft_continue(data);
}
