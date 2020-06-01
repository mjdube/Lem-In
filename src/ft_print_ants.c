#include "lem_in.h"

int         ft_print_ants_1(int check, char **roomName, t_keys *keys)
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

int         ft_print_ants_2(int check, char **roomName, t_keys *keys)
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