#include "lem_in.h"


t_rooms		*ft_rooms(t_rooms *rooms, char *roomName, t_keys *keys, int i)
{
	t_rooms	*node;
	t_rooms	*temp;

	if (!(node = (t_rooms *)malloc(sizeof(t_rooms))))
	{ 
		ft_putstr("ERROR\n");
		exit(0);
	}
	keys->rooms++;
	node->data = ft_strndup(roomName, i);
	node->link = NULL;
	node->next = NULL;
	node->id_number = 0;
	if (!rooms)
		return (node);
	else
	{
		temp = rooms;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		return (rooms);
	}
}
