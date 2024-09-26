/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:23:12 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/26 15:13:30 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "parsing.h"
# include "struct.h"
# include "utils.h"
# include "library.h"
# include "graphics.h"

# define PI 3.1415926535

# define WIDTH 8
# define HEIGHT	8

# define ARG "Too many or not enough arguments"
# define MALLOC "malloc failed"

# define FILE_ISDIR "Argument is a directory, not a file"
# define FILE_DE "File doesn't exist"
# define FILE_INVE "Filename or extension is invalid"

# define MISSING_COORD "Missing coordinates"
# define MISSING_TPATH "Missing texture path"
# define MISSING_COLOR "Missing color"

# define RGB_FORMAT "The colour isn't in the rgb format"
# define COLOR_FORMAT "The colour line isn't formatted properly"

# define MAP_OPEN "Map not closed"
# define MAP_BIG "Map size is too big"

# define INV_CHAR "Invalid Character/s in the map"
# define NO_PLAYER "Player not found"

#endif
