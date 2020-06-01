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