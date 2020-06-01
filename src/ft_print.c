#include "lem_in.h"

int			ft_print_1(int check, char **path, t_keys *keys)
{
	int		search;
	char	**roomName;
	int		ants;

	roomName = path;
	search = 0;
	while (search < check && roomName[search])
		search++;
	ants = 1;
	if (check == (keys->room_counter - 1))
		return (2);
	while (ants <= check)
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
	if (check >= keys->ants)
		return (2);
	return (1);
}

int			ft_print_2(int check, char **path, t_keys *keys)
{
	int		search;
	int		i;
	int		ants;
	char	**roomName;

	roomName = path;
	search = keys->room_counter - 1;
	ants = check - keys->room_counter + 1;
	i = 1;
	while(i < keys->room_counter)
	{
		ft_putchar('L');
		ft_putnbr(ants);
		ft_putchar('-');	
		ft_putstr(roomName[search]);
		ft_putchar(' ');
		search--;
		i++;
		ants++;
	}
	ft_putchar('\n');
	if (check >= keys->ants)
		return (3);
	return (2);
}

int			ft_print_3(int check, char **path, t_keys *keys, int size)
{
	int		i;
	int		j;
	int		ants;
	int		search;
	char	**roomName;

	j = size - check;
	ants = check - keys->room_counter + 1;
	roomName = path;
	i = 1;
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