/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:41 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/20 19:24:04 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	else
	{
		f->c.r = -0.7;
		f->c.i = 0.27015;
	}
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		cleanning(f);
	f->wind = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->im_ad = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
}

static	int	flag_adjust(char *s)
{
	size_t	j;
	int		flag;

	j = 0;
	flag = 0;
	if ((s[j] == '-' || s[j] == '+') && s[j + 1])
		j++;
	while (j < ft_strlen(s))
	{
		if (!ft_isdigit(s[j]))
		{
			if (s[j] == '.' && flag == 0 && ft_isdigit(s[j + 1]))
			{
				flag = 1;
				j++;
			}
			else
				return (0);
		}
		j++;
	}
	return (1);
}

static	int	check_avector(char **av, int i)
{
	char	*s;
	double	num;

	while (i < 4)
	{
		s = av[i];
		if (ft_strlen(av[i]) == 0)
			return (0);
		if (flag_adjust(s) == 0)
			return (0);
		num = ft_atod(av[i], 0, 0.1, 0);
		if (num < -2 || num > 2)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac == 1)
		return (0);
	else if (!ft_strncmp("julia", av[1], 6) && ac == 2)
		return (1);
	else if (!ft_strncmp("julia", av[1], 6) && ac == 4)
	{
		if (check_avector(av, 2) == 1)
			return (1);
		return (0);
	}
	else if (!ft_strncmp("mandelbrot", av[1], 11) && ac == 2)
		return (1);
	else if (!ft_strncmp("tricorn", av[1], 8) && ac == 2)
		return (1);
	return (0);
}
