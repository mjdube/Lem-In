#include "lem_in.h"

int			ft_check_room(char *roomName, t_rooms *rooms)
{
	t_rooms	*temp;

	temp = rooms;
	if (!rooms)
		return (0);
	while(temp)
	{
		if (!ft_strcmp(roomName, temp->data))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int			ft_is_room(char *roomName)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_strsplit(roomName, ' ');
	while (temp[i])
		i++;
	if (i != 3)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	i = -1;
	if (int_max(temp[1]) && int_max(temp[2]))
		j = 1;
	while(temp[++i])
		free(temp[i]);
	free(temp);
	if (j)
		return (1);
	return (0);
}

t_rooms		*ft_rooms(t_rooms *rooms, char *roomName, t_keys *keys)
{
	t_rooms	*node;
	t_rooms	*temp;
	int		i;

	if (!ft_is_room(roomName))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (ft_check_room(roomName, rooms) || roomName[0] == 'L')
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	i = ft_strchr(roomName, ' ') - roomName;
	if (!(node = (t_rooms *)malloc(sizeof(t_rooms))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	node->data = ft_strndup(roomName, i);
	node->next = NULL;
	keys->rooms++;
	if (!rooms)
		rooms = node;
	else
	{
		temp = rooms;
		while(temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return (rooms);
}
