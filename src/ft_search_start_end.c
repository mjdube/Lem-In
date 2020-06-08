#include "lem_in.h"

int     	ft_search_start_end(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	else if (!ft_strcmp(line, "##end"))
		return (2);
	return (0);
}