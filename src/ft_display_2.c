#include "lem_in.h"

char		**ft_display_2(t_keys *keys, char **roomName, int size)
{
	int i;
	int flag;

	i = 1;
	flag = 1;
	while(i < size)
	{
		if (flag == 1)
			flag = ft_print_ants_1(i, roomName, keys);
		else if (flag == 2)
			flag = ft_print_ants_2(i, roomName, keys);
		else if (flag == 3)
			flag = ft_print_3(i, roomName, keys, size);
		i++;
	}
	return(roomName);
}
