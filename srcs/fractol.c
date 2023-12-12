/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:38 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/12 20:00:26 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	printer(t_fract *data, int color)
{
	char	*dst;

	dst = data->im_ad + ((int)data->y * data->line_length + (int)data->x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	input_set(void)
{
	ft_putendl_fd(WRONG_SET ,2);
	ft_putendl_fd(CORRECT_SET , 2);
	ft_putendl_fd(JULIA_SET , 2);
	exit(1);
}

static int	print_to_screen(t_fract *fract)
{
	fract->x = 0;
	while (fract->x++ < WIDTH)
	{
		fract->y = 0;
		while (fract->y++ < HEIGHT)
		{
			printer(fract, 32);
			if(!ft_strncmp(fract->name, "julia", 5))
				julia_set(fract, fract->x - WIDTH / 2, fract->y - HEIGHT / 2);
			//else if(!ft_strncmp(fract->name, "mandelbrot", 5))
			//	mandelbrot_set(fract, fract->x - WIDTH / 2, fract->y - HEIGHT / 2);
			//if(!ft_strncmp(fract->name, julia, 5))
			//	julia_set(fract, fract->x - WIDTH / 2, fract->y - HEIGHT / 2);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->wind, fract->img, 0, 0);
	return 0;
}

int	main(int ac, char **av)
{
	t_fract	fract;
	
	if (ac == 2 || (ac == 4 && !ft_strncmp(av[1], "julia", 5 )))
	{
		init_struct(&fract, av);
//		if (ft_strncmp("julia", av[1], 5) == 0)
//			fractol_set(&fract);
//		else if (ft_strncmp("mandelbrot", av[1], 10) == 0)
//			mandelbrot(&fract);
//		else if (ft_strncmp("burning", av[1], 7) == 0)
//			bonus_set(&fract);
		//fract.mlx = mlx_init();
	//	mlx_key_hook(fractal.win, key_hook, &fractal);
	//	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	//	mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop_hook(fract.mlx, &print_to_screen, &fract);
		mlx_loop(fract.mlx);
	}
	else
		input_set();
	return (0);
}
