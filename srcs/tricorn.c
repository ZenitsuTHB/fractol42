/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:31:59 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/14 13:45:58 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	tricorn_set(t_fract *f)
{
    int iteration;
    float zx;
    float zy;
    int max_iteration;
    float xtemp;

	double zr = 1.5 * (f->x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
    double zi = (f->y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);
    zx = 0;//M_PI;
    zy = 0;//M_LOG2E;
    iteration = 0;
    max_iteration = 50;
    while (iteration < max_iteration)
    {
        xtemp = zx * zx - zy * zy;
        zy = -2 * zx * zy  + zi;//y / 300;
        zx = xtemp + zr;//x / 300;
        if (zx * zx + zy * zy > 4)
        {
            printer(f, iteration * iteration);
            break ;
        }
        iteration = iteration + 1;
    }
    if (iteration == max_iteration - 1)
        printer(f, 0);
}
