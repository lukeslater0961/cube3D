/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:39:26 by bananabread       #+#    #+#             */
/*   Updated: 2024/09/11 15:39:28 by bananabread      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "data.h"

int	check_file(char *filename, t_data *data);
int	do_parsing(char **argv, t_data *data);
int	check_file_content(t_data *data);

#endif
