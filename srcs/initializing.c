/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:41 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/16 19:55:45 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * f = fractal;
 */

/*
 *	check_arg function;TODO
 */

int	cleanning(t_fract *f)
{
	if (f && f->wind)
		mlx_destroy_window(f->mlx, f->wind);
	exit (1);
}

void	init_struct(t_fract *fract, char **av, int ac)
{
	fract->name = av[1];
	fract->zoom = 1.0;
	if (!ft_strncmp(fract->name, "julia", 6))
	{
		if (ac == 4)
		{
			fract->c.r = ft_atod(av[2], 1.0, 0.1, 0);
			fract->c.i = ft_atod(av[3], 1.0, 0.1, 0);
			printf("f->c.r %lf\n", fract->c.r);
			printf("f->c.i %lf\n", fract->c.i);
			printf("av2 %s\n", av[2]);
			printf("av3 %s\n", av[3]);
		}	
		else
		{
			fract->c.r = -0.7;
			fract->c.i = 0.27015;
		}
	}
	fract->max_iter = 100;
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


