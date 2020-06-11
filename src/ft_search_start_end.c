#include "lem_in.h"

int     	ft_search_start_end(char *line)
{
	int 	len;

	len = ft_strlen(line);
	if (len == 7 && !ft_strncmp(line, "##start", 7))
		return (1);
	else if (len == 5 && !ft_strncmp(line, "##end", 5))
		return (2);
	return (0);
}