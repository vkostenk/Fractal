/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:26:01 by vkostenk          #+#    #+#             */
/*   Updated: 2018/12/17 18:02:32 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "stdlib.h"

typedef struct			s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	double				minreal;
	double				maxreal;
	double				minimagine;
	double				maximagine;
	int					w_width;
	int					w_height;
	char				*name_of_fractol;
	int					max_iterations;
	int					x;
	int					y;
	double				int_real;
	double				int_imagine;
	double				change_x;
	double				change_y;
	int					color;
	double				zoom;
	int					mouse_x;
	int					mouse_y;
	double				int_real_change;
	double				int_imagine_change;
	double				vert[3][3];
	int					random;
	double				side;
	int					change_side;
}						t_data;

void					init_data(char *s, t_data *data);
int						chek_if_valid(char *s, int argc);
void					init_mandelbrot(t_data *data);
double					calc_real(t_data *data);
double					calc_imagine(t_data *data);
int						calc_num_mandelbrot(t_data *data);
void					draw_mandelbrot(t_data *data);
int						deal_key(int key, t_data *data);
void					move_y_down(t_data *data);
void					move_y_up(t_data *data);
void					move_x_left(t_data *data);
void					move_x_right(t_data *data);
void					change_color(t_data *data, int key);
void					zoom(int x, int y, t_data *data);
int						mouse_manage(int mousecode, int x, int y, t_data *data);
double					interpolate(double start,
		double end, double interpolation);
int						mouse_drag(int x, int y, t_data *data);
void					draw_julia(t_data *data);
void					init_julia(t_data *data);
double					calc_real_julia(t_data *data);
double					calc_imagine_julia(t_data *data);
int						calc_num_julia(t_data *data);
void					draw_fractol(t_data *data);
void					draw_chaos(t_data *data);
void					init_chaos(t_data *data);
void					ft_continue(t_data *data);
void					change_size(t_data *data, int key);
void					mouse_manage_if(int mousecode,
		int x, int y, t_data *data);

#endif
