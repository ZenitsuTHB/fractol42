/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:04:31 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/20 19:18:26 by avolcy           ###   ########.fr       */
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
	int	col_idx;
	int	gray_sc;
	int	pixel_col;
	int	max_col_idx;
	int	arr_col[3];

	arr_col[0] = 0x9944FF;
	arr_col[1] = 0x301166;
	arr_col[2] = 0x03AACC;
	max_col_idx = sizeof(arr_col) / sizeof(arr_col[2]);
	col_idx = iter % max_col_idx;
	gray_sc = (iter) * 250 / f->max_iter;
	if (!ft_strncmp(f->name, "julia", 6))
		pixel_col = arr_col[col_idx] + (gray_sc << 8)
			| (gray_sc << 24) | (gray_sc << 26) | gray_sc;
	else if (!ft_strncmp(f->name, "mandelbrot", 11))
		pixel_col = arr_col[col_idx] + (gray_sc << 12)
			| (gray_sc << 26) | (gray_sc << 30) | gray_sc;
	else
		pixel_col = arr_col[col_idx] + (gray_sc << 24)
			| (gray_sc << 20) | (gray_sc << 10) | gray_sc;
	*(unsigned int *)(f->im_ad + pos) = pixel_col;
}
/*
 *  Cycling through colors, [col_idx];
 *  Get color from palette based on the index, [pixel_col];
 *  gray_sc is a way of representing images or colors using shades of gray
 *  Set color for the pixel,[pos];
 */
