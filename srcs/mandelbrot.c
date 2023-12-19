/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:32:23 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/19 19:19:16 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * madelbrot parameters and tricorn to set up;TODO
 */

int	mandelbrot_set(t_fract *f)
{
	double	zr;
	double	zi;
	double	xtemp;
	int		iteration;

	f->zx = 0;
	f->zy = 0;
	zr = 1.68 * (f->x - WIDTH / 1.9) / (0.5 * f->zoom * WIDTH);
	zi = (f->y - HEIGHT / 2.0) / (0.3 * f->zoom * HEIGHT);
	iteration = 0;
	while (iteration < f->max_iter)
	{
		xtemp = f->zx * f->zx - f->zy * f->zy;
		f->zy = 2 * f->zx * f->zy + zi;
		f->zx = xtemp + zr;
		if (f->zx * f->zx + f->zy * f->zy > 4)
			return (iteration);
		iteration++;
	}
	return (f->max_iter - 1);
}
