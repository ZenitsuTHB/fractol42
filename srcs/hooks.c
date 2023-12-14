/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:04:31 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/14 22:08:16 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	key_hook(int key, t_fract *f)
{
	if (key == ESC)
		cleanning(f);
	return (0);
}

void	psychedelic_effect(int iter, t_fract *f)
{
	int colorPalette[] = { 0x1f665F, 0x300066, 0x33CCCC }; // Red, Green, Blue
    int maxColorIndex = sizeof(colorPalette) / sizeof(colorPalette[0]);
	int pixelColor; 
    int colorIndex = iter % maxColorIndex; // Cycling through colors
	int grayscale = iter * 255 / f->max_iter;
        // Get color from palette based on the index
     pixelColor = colorPalette[colorIndex] + (grayscale << 8) /*| grayscale*/ |
		 (grayscale << 24) /*| grayscale*/ | (grayscale << 26) | grayscale;
        // Set color for the pixel
     int pos = (f->x * 4) + (f->y * WIDTH * 4);
     *(unsigned int*)(f->im_ad + pos) = pixelColor;

//	return (pixelColor);
}

