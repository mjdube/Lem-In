#include "lem_in.h"

void    	ft_room(char *line, t_keys *keys, int check_start_end)
{
	int		i;
	char	**name;

	if (!ft_strchr(line, ' ') || ft_strchr(line, '#') || line[0] == 'L')
	{
		ft_putstr("ERROR\n");
		exit(0);
	} 
	name = ft_strsplit(line, ' ');
	i = 0;
	while (name[i])
		i++;
	if (i != 3)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (check_start_end == 1)
		keys->start = ft_strdup(name[0]);
	if (check_start_end == 2)
		keys->end = ft_strdup(name[0]);
	i = 0;
	while (name[i])
	{
		free(name[i]);
		i++;
	}
	free(name);
}

t_rooms    *ft_create_rooms(t_keys *keys, t_rooms *rooms)
{
	char	*line;
	char	*temp;
	int		check_start_end;

	check_start_end = 0;
	while (get_next_line(0, &line) == 1)
	{
		temp = ft_strdup(line);
		if (check_start_end > 0)
			ft_room(temp, keys, check_start_end);
		check_start_end = ft_search_start_end(line);
		if (line[0] != '#' && ft_strchr(line, ' '))
			rooms = ft_rooms(rooms, line, keys);
		if (!ft_strchr(line, ' ') && line[0] != '#')
		{
			keys->read = ft_strdup(line);
			break ;
		}
		free(line);
		free(temp);
	}
	if (ft_strlen(line) == 0)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	free(line);
	free(temp);
	return (rooms);
}
