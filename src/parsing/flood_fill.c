/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:51 by lslater           #+#    #+#             */
/*   Updated: 2024/09/12 11:44:00 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	map_flood(t_data *data, int y, int x, int rows, int cols)
{
	if (data->flood_fill[y][x] == '7')
		return ;
	data->flood_fill[y][x] = '7';
	if (y + 1 < rows - 1 && data->flood_fill[y + 1][x] != '1')
		map_flood(data, y + 1, x, rows, cols);
	if (x + 1 < cols - 1 && data->flood_fill[y][x + 1] != '1')
		map_flood(data, y, x + 1, rows, cols);
	if (y - 1 >= 1 && data->flood_fill[y - 1][x] != '1')
		map_flood(data, y - 1, x, rows, cols);
	if (x - 1 >= 1 && data->flood_fill[y][x - 1] != '1')
		map_flood(data, y, x - 1, rows, cols);
}
