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

t_path		*ft_add_to_path(t_path *path, t_rooms *rooms, t_keys *keys)
{
	t_path	*node;
	t_path	*temp;

	if (ft_is_path(rooms->data, path))
		return (path);
	if (!(node = (t_path *)malloc(sizeof(t_path *))))
	{
        ft_putstr("ERROR\n");
        exit(0);
    }
	node->map = ft_strdup(rooms->data);
	node->next = NULL;
	if (!path)
		path = node;
	else
	{
		temp = path;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	keys->room_counter++;
	return (path);
}


t_path		*ft_final_path(t_path *visit, t_path *path, t_rooms *rooms, t_keys *keys)
{
	int		i;
	int		j;
	t_rooms	*temp;

	i = 0;
	while (i < keys->rooms && i > -1)
	{
		j = 0;
		temp = rooms;
		while (j < keys->rooms && temp)
		{
			if (j == visit->visits[i])
				path = ft_add_to_path(path, temp, keys);
			temp = temp->next;
			j++;
		}
		i++;
	}
	return (path);
}