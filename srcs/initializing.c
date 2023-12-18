/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:41 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/18 18:52:10 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 *	check_arg function;TODO
 */

int	cleanning(t_fract *f)
{
	if (f && f->wind)
		mlx_destroy_window(f->mlx, f->wind);
	exit (1);
}

void	init_struct(t_fract *f, char **av, int ac)
{
	f->zoom = 1;
	f->name = av[1];
	f->max_iter = 100;
	if (!ft_strncmp(f->name, "julia", 6) && ac == 4)
	{
		f->c.r = ft_atod(av[2], 0, 0.1, 0);
		f->c.i = ft_atod(av[3], 0, 0.1, 0);
	}
	f->c.r = -0.7;
	f->c.i = 0.27015;
	f->z.r = 1.5 * (f->x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
	f->z.i = (f->y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		cleanning(f);
	f->wind = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->im_ad = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
}
