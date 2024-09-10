
#include "includes/cube.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_printf(2, "not enough or too many arguments");
		exit(1);
	}
	else
		do_parsing(argv);
}
