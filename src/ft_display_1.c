#include "lem_in.h"

static char		**ft_rev_path(t_path *first_block, char **temp, t_keys *keys)
{
	t_path	*path;
	int		i;

	path = first_block;
	i = 0;
	if (!(temp = (char **)malloc(sizeof(char *) * keys->room_counter)))
	{
        ft_putstr("ERROR\n");
        exit(0);
    }
	while (path)
	{
		if (!(temp[i] = (char *)malloc(sizeof(char) * ft_strlen(path->map))))
		{
        	ft_putstr("ERROR\n");
        	exit(0);
    	}
		temp[i] = ft_strcpy(temp[i], path->map);
		path = path->next;
		i++;
	}
	return (temp);
}

static int			ft_print_1(int check, char **path, t_keys *keys)
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

static int			ft_print_2(int check, char **path, t_keys *keys)
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

static int			ft_print_3(int check, char **path, t_keys *keys, int size)
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

t_path		*ft_display_1(t_path *path, t_keys *keys)
{
	int		i;
	int		size;
	int		flag;
	char	**temp;

	i = 1;
	flag = 1;
	temp = NULL;
	size = keys->ants + keys->room_counter;
	temp = ft_rev_path(path, temp, keys);
	ft_putchar('\n');
	
	if (keys->ants < keys->room_counter)
		temp = ft_display_2(keys, temp, size);
	else
	{		
		while (i < size)
		{
			if (flag == 1)
				flag = ft_print_1(i, temp, keys);
			else if (flag == 2)
				flag = ft_print_2(i, temp, keys);
			else if (flag == 3)
				flag = ft_print_3(i, temp, keys, size);
			i++;
		}	
	}
	empty_stack(temp, keys->room_counter);
	return (path);
}