#include "lem_in.h"

int			ft_dup(int *visited, int v, int links_len)
{
	int	i;

	i = 0;
	while(i < links_len)
	{
		if (visited[i] == v)
			return (1);
		i++;
	}
	return (0);
}

int        ft_decrem_visit(int j)
{
	j = j - 1;
	if (j < 0)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	return (j);
}