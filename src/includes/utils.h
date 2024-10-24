/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:35:16 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/18 13:05:17 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

void	print_texture(t_data *data);
void	print_tab(char **tab);
int		print_error(char *str);
int		free_tab_print_err(char *str, char **tab);

#endif
