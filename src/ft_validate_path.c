
#include "lem_in.h"

int			ft_is_path(char *str, t_path *path)
{
	t_path	*temp;

	temp = path;
	while(temp)
	{
		if (ft_strequ(str, path->map))
			return (1);
		temp = temp->next;
	}
	return (0);
}