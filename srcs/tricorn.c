/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:43:22 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/18 18:50:54 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	tricorn_set(t_fract *f)
{
	double	zr;
	double	zi;
	double	xtemp;
	int		iteration;

	f->zx = 0;
	f->zy = 0;
	zr = 1.6 * (f->x - WIDTH / 2.0) / (0.3 * f->zoom * WIDTH);
	zi = (f->y - HEIGHT / 2.0) / (0.3 * f->zoom * HEIGHT);
	iteration = 0;
	while (iteration < f->max_iter)
	{
		xtemp = f->zx * f->zx - f->zy * f->zy;
		f->zy = -2 * f->zx * f->zy + zi;
		f->zx = xtemp + zr;
		if (f->zx * f->zx + f->zy * f->zy > 4)
			return (iteration);
		iteration++;
	}
	return (f->max_iter - 1);
}
