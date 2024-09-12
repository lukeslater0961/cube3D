/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:51 by lslater           #+#    #+#             */
/*   Updated: 2024/09/12 15:17:04 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	map_flood(t_data *data, int y, int x, int rows, int cols)
{
	ft_printf("i:%d\n", y);
	ft_printf("j:%d\n", x);
	ft_printf("data->flood_fill[%d][%d]: %c\n", y, x, data->flood_fill[y][x]);
	if (x < 0 || y < 0 || y >= rows || x >= cols || !data->flood_fill[y][x])
		return;
	if (data->flood_fill[y][x] != '0')
		return;

	data->flood_fill[y][x] = '7';

	// Assurez-vous d'appeler les fonctions avec les bons paramètres (y pour lignes, x pour colonnes)
	map_flood(data, y + 1, x, rows, cols);
	map_flood(data, y - 1, x, rows, cols);
	map_flood(data, y, x + 1, rows, cols);
	map_flood(data, y, x - 1, rows, cols);
}
