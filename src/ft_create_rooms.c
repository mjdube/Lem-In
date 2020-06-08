#include "lem_in.h"

int			ft_only_one(t_notes *map)
{
	int		i;
	int		j;
	int		x;
	t_notes	*farm;

	i = 0;
	j = 0;
	x = 0;
	farm = map;
	while (farm->next != NULL)
	{
		if (ft_search_start_end(farm->note) == 1)
		{
			if (j == 0)	
			{
				i++;
				j = 1;
			}
			else 
				i++;
		}
		if (ft_search_start_end(farm->note) == 2)
		{
			if (x == 0)
			{
				i++;
				x = 1;
			}
			else 
				i++;		
		}		
		farm = farm->next;
	}
	if ((i == 2) && (x == 1) && (j == 1))
		return (1);
	return (0);
}

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
	{
		keys->start = ft_strdup(name[0]);
	}
	if (check_start_end == 2)
	{
		keys->end = ft_strdup(name[0]);
	}
	i = 0;
	while (name[i])
	{
		free(name[i]);
		i++;
	}
	free(name);
}

t_rooms		*ft_create_rooms(t_keys *keys, t_rooms *rooms, t_notes *map)
{
	char	*temp;
	int		check_start_end;
	t_notes	*farm;
	int		status;
	int		i; 

	check_start_end = 0;
	farm = map;
	status = 0;
	if (!ft_only_one(farm))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	while (farm->next != NULL)
	{
		if (ft_strchr(farm->note, ' ') && farm->note[0] != '#')
		{
			if (!ft_strcmp(farm->note, "##start"))
				status = 1;
			if (!ft_strcmp(farm->note, "##end"))
				status = 2;
			if (farm->note[0] != '#')
			{
				i = ft_strchr(farm->note, ' ') - farm->note;
				rooms = ft_rooms(rooms, farm->note, keys, i);
				if (status == 1)
					keys->start = ft_strndup(farm->note, i);
				if (status == 2)
					keys->end = ft_strndup(farm->note, i);
				status = 0;
			}
		}
		/*
		temp = ft_strdup(farm->note);
		if (check_start_end > 0)
			ft_room(temp, keys, check_start_end);
		check_start_end = ft_search_start_end(farm->note);
		if (farm->note[0] != '#' && ft_strchr(farm->note, ' '))
			rooms = ft_rooms(rooms, farm->note, keys);
		if (!ft_strchr(farm->note, ' ') && farm->note[0] != '#')
		{
			if (ft_strchr(farm->note, '-'))
				break ;
		}
		farm = farm->next;
		free(temp);*/
	}
	if (ft_strlen(farm->note) == 0)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	free(temp);
	/*
	while (get_next_line(0, &env->line) > 0)
	{
		if (!ft_strchr(env->line, ' ') && env->line[0] != '#')
			break ;
		if (!ft_strcmp(env->line, "##start"))
			status = 1;
		if (!ft_strcmp(env->line, "##end"))
			status = 2;
		if (env->line[0] != '#')
		{
			// hello
			i = ft_strchr(env->line, ' ') - env->line;
			room = add_room(room, env, i);
			if (status == 1)
				env->start = ft_strndup(env->line, i);
			if (status == 2)
				env->end = ft_strndup(env->line, i);
			status = 0;
		}
		ft_putendl(env->line);
		free(env->line);
	}
	*/
	return (rooms);
}
