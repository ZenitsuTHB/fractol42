/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:04:31 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/15 20:40:54 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	key_hook(int key, t_fract *f)
{
	if (key == ESC)
		cleanning(f);
	return (0);
}

//int	mouse_hook(int key )
void	psychedelic_effect(int iter, t_fract *f, int pos)
{
	int pixel_col; 
	int array_col[] = { 0x1f665F, 0x300066, 0x33CCCC };
	int max_col_idx = sizeof(array_col) / sizeof(array_col[0]);
    int col_idx = iter % max_col_idx;
	int grayscale = iter * 255 / f->max_iter;
     
	pixel_col = array_col[col_idx] + (grayscale << 8) |
		 (grayscale << 24) | (grayscale << 26) | grayscale;
     *(unsigned int*)(f->im_ad + pos) = pixel_col;
}
/*
 *  Cycling through colors, [col_idx];
 *  Get color from palette based on the index, [pixel_col];
 *  Grayscale is a way of representing images or colors using shades of gray
 *  Set color for the pixel,[pos];
 */
