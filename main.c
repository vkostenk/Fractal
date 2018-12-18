/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:25:31 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 18:01:29 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_data(char *s, t_data *data)
{
	data->name_of_fractol = s;
	data->w_width = 900;
	data->w_height = 900;
	data->change_x = 0;
	data->change_y = 0;
	data->color = 0xff5ff1;
	data->zoom = 1;
	data->minreal = -2.05;
	data->minimagine = -1.3;
	data->maxreal = 1.2;
	data->maximagine = 1.2;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->int_real_change = 0;
	data->int_imagine_change = 0;
	data->change_side = 0;
}

int			chek_if_valid(char *s, int argc)
{
	if (argc < 2 || argc > 2)
	{
		write(1, "Usage: ./fractol [name_of_fractol]\n", 35);
		return (0);
	}
	if ((ft_strcmp(s, "mandelbrot") != 0) &&
			(ft_strcmp(s, "julia") != 0) && (ft_strcmp(s, "chaos") != 0))
	{
		write(1, "Bro, you entered something wrong =(\n", 36);
		write(1, "-> mandelbrot\n", 14);
		write(1, "-> julia\n", 9);
		write(1, "-> chaos\n", 9);
		return (0);
	}
	return (1);
}

void		draw_fractol(t_data *data)
{
	if (ft_strcmp(data->name_of_fractol, "mandelbrot") == 0)
		draw_mandelbrot(data);
	if (ft_strcmp(data->name_of_fractol, "julia") == 0)
		draw_julia(data);
	if (ft_strcmp(data->name_of_fractol, "chaos") == 0)
		draw_chaos(data);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (!chek_if_valid(argv[1], argc))
		return (0);
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "Fractol");
	init_data(argv[1], data);
	draw_fractol(data);
	mlx_hook(data->win_ptr, 2, 5, deal_key, data);
	mlx_mouse_hook(data->win_ptr, mouse_manage, data);
	mlx_hook(data->win_ptr, 6, 5, mouse_drag, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
