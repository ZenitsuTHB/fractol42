/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:04:31 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/17 21:53:18 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	key_hook(int key, t_fract *f)
{
	if (key == ESC)
		cleanning(f);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fract *f)
{
	(void)x;
	(void)y;
	if (key == ZOOM_IN)
		f->zoom *= 0.8;
	if (key == ZOOM_OUT)
		f->zoom *= 1.2;
	mlx_clear_window(f->mlx, f->wind);
	draw_fractal(f);
	return (0);
}

void	psychedelic_effect(int iter, t_fract *f, int pos)
{
	int	pixel_col;
	int	array_col[3];
	int	max_col_idx;
	int	col_idx;
	int	grayscale;

	array_col[0] = 0x1f665F;
	array_col[1] = 0x300066;
	array_col[2] = 0x33CCCC;
	max_col_idx = sizeof(array_col) / sizeof(array_col[0]);
	col_idx = iter % max_col_idx;
	grayscale = iter * 255 / f->max_iter;
	if (!ft_strncmp(f->name, "julia", 6))
	{
		pixel_col = array_col[col_idx] + (grayscale << 8)
			| (grayscale << 24) | (grayscale << 26) | grayscale;
	}
	else if (!ft_strncmp(f->name, "mandelbrot", 11))
	{
		pixel_col = array_col[col_idx] + (grayscale << 24)
			| (grayscale << 20) | (grayscale << 16) | grayscale;
	}
	else
		pixel_col = array_col[col_idx] + (grayscale << 24)
			| (grayscale << 8) | (grayscale << 30) | grayscale;
	*(unsigned int *)(f->im_ad + pos) = pixel_col;
}
/*
 *  Cycling through colors, [col_idx];
 *  Get color from palette based on the index, [pixel_col];
 *  Grayscale is a way of representing images or colors using shades of gray
 *  Set color for the pixel,[pos];
 */
