/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:32:23 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/14 23:07:09 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * madelbrot parameters and tricorn to set up;TODO
 */
int	mandelbrot_set(t_fract *f)
{
    int iteration;
    float zx;
    float zy;
    float xtemp;
 	
	double zr = 1.5 * (f->x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
    double zi = (f->y - HEIGHT / 2.0) / (0.3 * f->zoom  * HEIGHT);
    zx = 0;//M_PI;
    zy = 0;//M_LOG2E;
    iteration = 0;
    while (iteration < f->max_iter)
    {
        xtemp = zx * zx - zy * zy;
        zy = 2 * zx * zy + zi;//y / 300;
        zx = xtemp + zr;//x / 300;
        if (zx * zx + zy * zy > 4)
        {
			return iteration;
          //  printer(f, iteration * iteration);
        //    break ;
        }
        iteration++;
    }
	return f->max_iter - 1;
    //if (iteration == f->max_iter - 1)
      //  printer(f, 0);
}
