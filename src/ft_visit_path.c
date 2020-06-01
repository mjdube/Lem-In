#include "lem_in.h"

t_path		*ft_start_path(t_path *visit, t_keys *keys, int start)
{
	if (!(visit = (t_path *)malloc(sizeof(t_path))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(visit->visits = (int *)malloc(sizeof(int) * keys->rooms + 1)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	visit->visits[0] = start;
	return (visit);
}

t_visit		*ft_rec_visit(t_visit *visit, t_keys *keys, int start)
{
	if (!(visit = (t_visit *)malloc(sizeof(t_visit))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(visit->path = (int *)malloc(sizeof(int) * keys->rooms + 1)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	visit->path[0] = start;
	return (visit);
}