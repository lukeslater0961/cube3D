/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:22:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/24 16:48:46 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"
#include "libs/MacroLibX/includes/mlx.h"

void	set_textures(t_mlx *mlx)
{
	mlx->texture->size = 16;
	printf("img: %s\n", mlx->data->textures[0]);
	mlx->texture->north = mlx_png_file_to_image(mlx->mlx, mlx->data->textures[0], &mlx->texture->size, &mlx->texture->size);
	mlx->texture->south = mlx_png_file_to_image(mlx->mlx, mlx->data->textures[1], &mlx->texture->size, &mlx->texture->size);
	mlx->texture->west = mlx_png_file_to_image(mlx->mlx, mlx->data->textures[2], &mlx->texture->size, &mlx->texture->size);
	mlx->texture->east = mlx_png_file_to_image(mlx->mlx, mlx->data->textures[3], &mlx->texture->size, &mlx->texture->size);
}
