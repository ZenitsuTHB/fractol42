/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:41 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/14 13:46:15 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * f = fractal;
 */

void	init_struct(t_fract *fract, char **av)
{
	fract->name = av[1];
	fract->zoom = 1.0;
	fract->max_iter = 100;
	fract->z.r = 1.5 * (fract->x - WIDTH / 2.0) / (0.5 * fract->zoom * WIDTH);
    fract->z.i = (fract->y - HEIGHT / 2.0) / (0.5 * fract->zoom * HEIGHT);
	fract->mlx = mlx_init();
	//if (fract->mlx == NULL)
		//cleanning();//TODO;
	fract->wind = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	//if (fract->mlx == NULL)
	//	mlx = mlx_destroy_image
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->im_ad = mlx_get_data_addr(fract->img, &fract->bits_per_pixel,
		   	&fract->line_length, &fract->endian);
}


