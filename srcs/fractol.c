/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:38 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/14 13:46:06 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	printer(t_fract *data, int color)
{
	char	*dst;

	dst = data->im_ad + ((int)data->y * data->line_length
		   	+ (int)data->x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	input_set(void)
{
	ft_putendl_fd(WRONG_SET ,2);
	ft_putendl_fd(CORRECT_SET , 2);
	ft_putendl_fd(JULIA_SET , 2);
	exit(1);
}

int draw_fractal(t_fract *f)
{
	f->x = 0;
    while (f->x++ < WIDTH)
	{
		f->y = 0;
        while (f->y++ < HEIGHT)
		{
			//printer(fract, 32);
			if (!ft_strncmp("julia", f->name, 5))
				julia_set(f);
			else if (!ft_strncmp("mandelbrot", f->name, 10))
				mandelbrot_set(f);
			else if (!ft_strncmp("tricorn", f->name, 7))
				tricorn_set(f);
		}
	}
	mlx_put_image_to_window(f->mlx, f->wind, f->img, 0, 0);
	return 0;
}

int	main(int ac, char **av)
{
	t_fract	fract;
	
	if (ac == 2 || (ac == 4 && !ft_strncmp(av[1], "julia", 5 )))
	{
		init_struct(&fract, av);
	//	mlx_key_hook(fractal.win, key_hook, &fractal);
	//	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	//	mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop_hook(fract.mlx, &draw_fractal, &fract);
		mlx_loop(fract.mlx);
	}
	else
		input_set();
	return (0);
}
