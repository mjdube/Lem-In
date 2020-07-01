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
	if (ft_int_max(temp[1]) && ft_int_max(temp[2]))
		j = 1;
	while(temp[++i])
		free(temp[i]);
	free(temp);
	if (j)
		return (1);
	return (0);
}