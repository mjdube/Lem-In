#include "lem_in.h"

void	ft_begin(t_keys *keys)
{
	t_keys	*key;

	key = keys;
	key->start = NULL;
	key->end = NULL;
	key->read = NULL;
	key->ants = 0;
	key->rooms = 0;
	key->room_counter = 0;
}

void	ft_check_start_end(t_keys *keys)
{
	if (keys->start == NULL || keys->end == NULL)
	{
        ft_putstr("ERROR\n");
        exit(0);
    }
}

void	ft_num_of_ants(t_keys *keys, t_notes *map)
{
	t_notes *farm;

	farm = map;
	while (farm->next != NULL)
	{
		if (ft_int_max(farm->note) && ft_atoi(farm->note) > 0)
		{
			keys->ants = ft_atoi(farm->note);
			break ;
		}
		else 
		{
			if (farm->note[0] != '#')
			{
				ft_putstr("ERROR\n");
				exit(0);
			}
		}
		farm = farm->next;
	}
}