/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:30:16 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/11 21:05:13 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia_set(t_fract *fract, float x, float y)
{
	int iteration;
	float zx;
	float zy;
    int	max_iteration;
	float xtemp;

	zx = 0;//M_PI;
	zy = 0;//M_LOG2E;
    iteration = 0;
    max_iteration = 50;
    while (iteration < max_iteration) 
    {
        xtemp = zx * zx - zy * zy;
        zy = -2 * zx * zy  + y / 300;
        zx = xtemp + x / 300;
		if (zx * zx + zy * zy > 4)
		{
			printer(fract, iteration * iteration);
			break ;
		}
		iteration = iteration + 1;
    }
	if (iteration == max_iteration - 1)
		printer(fract, 0);
}

