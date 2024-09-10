#ifndef PARSING_H
#define PARSING_H

# include "data.h"

int	check_file(char *filename, t_data *data);
int	do_parsing(char **argv, t_data *data);
int	check_file_content(t_data *data);

#endif
