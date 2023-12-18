/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:38 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/18 14:20:06 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*void	printer(t_fract *data, int color)
{
	char	*dst;

	dst = data->im_ad + ((int)data->y * data->line_length
		   	+ (int)data->x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

void	input_set(void)
{
	ft_putendl_fd(WRONG_SET, 2);
	ft_putendl_fd(CORRECT_SET, 2);
	ft_putendl_fd(JULIA_SET, 2);
	exit(1);
}

int	draw_fractal(t_fract *f)
{
	int		pos;
	int		iter;

	f->x = -1;
	while (++(f->x) < WIDTH)
	{
		f->y = -1;
		while (++(f->y) < HEIGHT)
		{
			if (!ft_strncmp("julia", f->name, 6))
				iter = julia_set(f);
			else if (!ft_strncmp("mandelbrot", f->name, 11))
				iter = mandelbrot_set(f);
			else if (!ft_strncmp("tricorn", f->name, 8))
				iter = tricorn_set(f);
			else
				input_set();
			pos = (f->x * 4) + (f->y * WIDTH * 4);
			psychedelic_effect(iter, f, pos);
		}
	}
	mlx_put_image_to_window(f->mlx, f->wind, f->img, 0, 0);
	return (0);
}

/* check_argv();TODO
 * if check_argv == 1; good args else input_set;
 */
int	main(int ac, char **av)
{
	t_fract	fract;

	if (ac == 2 || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		init_struct(&fract, av, ac);
		printf("f->c.r %lf\n", fract.c.r);
		printf("f->c.i %lf\n", fract.c.i);
		mlx_loop_hook(fract.mlx, &draw_fractal, &fract);
		mlx_key_hook(fract.wind, key_hook, &fract);
		mlx_hook(fract.wind, 17, 1L << 17, cleanning, &fract);
		mlx_mouse_hook(fract.wind, mouse_hook, &fract);
		mlx_loop(fract.mlx);
	}
	else
		input_set();
	return (0);
}
