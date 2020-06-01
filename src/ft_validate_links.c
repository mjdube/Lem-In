#include "lem_in.h"

t_links		*ft_make_links(t_links *links, int links_len)
{
	int	i;

	i = 0;
	if (!(links = (t_links *)malloc(sizeof(t_links))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(links->links = (int **)malloc(sizeof(int*) * links_len)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	while (i < links_len)
	{
		if (!(links->links[i] = (int *)malloc(sizeof(int) * links_len)))
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		i++;
	}
	return (links);
}

int			ft_is_link(char *roomName, t_rooms *rooms)
{
	int		i;
	t_rooms	*temp;

	i = 0;
	temp = rooms;
	while (temp)
	{
		if (ft_strequ(roomName, temp->data))
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}