/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:31:59 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/14 23:07:11 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	tricorn_set(t_fract *f)
{
    int iteration;
    float zx;
    float zy;
    float xtemp;

	double zr = 1.7 * (f->x - WIDTH / 2.0) / (0.3 * f->zoom * WIDTH);
    double zi = (f->y - HEIGHT / 2.0) / (0.3 * f->zoom * HEIGHT);
    zx = 0;//M_PI;
    zy = 0;//M_LOG2E;
    iteration = 0;
    while (iteration < f->max_iter)
    {
        xtemp = zx * zx - zy * zy;
        zy = -2 * zx * zy  + zi;
        zx = xtemp + zr;
        if (zx * zx + zy * zy > 4)
        {
			return iteration;
           // printer(f, iteration * iteration);
           // break ;
        }
        iteration++;
    }
	return f->max_iter - 1;
    //if (iteration == f->max_iter - 1)
      //  printer(f, 0);
}
