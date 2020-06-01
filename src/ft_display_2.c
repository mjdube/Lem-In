#include "lem_in.h"

static int         ft_print_ants_1(int check, char **roomName, t_keys *keys)
{
	int ants;
	int search;

	ants = 1;
	search = 0;
	if (check >= keys->ants)
		return (2);
	while (search < check && roomName[search])
		search++;
	while (ants <= check && check < keys->ants)
	{
		ft_putchar('L');
		ft_putnbr(ants);
		ft_putchar('-');
		ft_putstr(roomName[search]);
		ft_putchar(' ');
		search--;
		ants++;
	}
	ft_putchar('\n');
	return (1);
}

static int         ft_print_ants_2(int check, char **roomName, t_keys *keys)
{
	int search;
	int i;
	int ants;
	int j;

	search = check - 1;
	i = 1;
	ants = 1;
	j = 1;
	if (search >= keys->room_counter)
		return (3);
	while(i <= keys->ants)
	{
		if (!ft_strcmp(roomName[search], keys->end))
			j = 2;
		ft_putchar('L');
		ft_putnbr(ants);
		ft_putchar('-');
		ft_putstr(roomName[search]);
		ft_putchar(' ');
		search--;
		ants++;
		i++;
	}
	ft_putchar('\n');
	if (j == 2)
		return (3);
	return (2);
}

static int		    ft_print_ants_3(int check, char **map, t_keys *keys, int size)
{
	int     i;
	int     j;
	int     ants;
	int     search;
	char	**roomName;

	i = 1;
	j = size - check;
	ants = check - keys->room_counter + 1;
	roomName = map;
	search = keys->room_counter - 1;
	while (i <= j && j <= keys->ants)
	{
		ft_putchar('L');
		ft_putnbr(ants);
		ft_putchar('-');
		ft_putstr(roomName[search]);
		ft_putchar(' ');
		i++;
		ants++;
		search--;
	}
	ft_putchar('\n');
	return (3);
}

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
			flag = ft_print_ants_3(i, roomName, keys, size);
		i++;
	}
	return(roomName);
}
