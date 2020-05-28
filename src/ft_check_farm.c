#include "lem_in.h"

/*Checks the max and min int value */
static int		int_max(char *str)
{
	int		len;
	char	*max;
	char	*min;

	len = ft_strlen(str);
	min = "2147483648";
	max = "2147483647";
	str = (len == 11 && *str == '-') ? str + 1 : str;
	while (*str && len >= 10)
	{
		if (len == 10)
		{
			if (ft_strncmp(str, max, 1) > 0)
				return (1);
			max++;
		}
		else
		{
			if (ft_strncmp(str, min, 1) > 0)
				return (1);
			min++;
		}
		str++;
	}
	return (0);
}

/*Looks for commands ##start and ##end, if it finds both
it will return (2) 
 */
static int         ft_commands(t_notes *map)
{
    int     i;
    t_notes         *farm;
    
    i = 0;
    farm = map;
    if (!farm)
        return (0);
    while (farm->next != NULL)
    {
        if (ft_search_start_end(farm->note) == 1)
            i++;
        if (ft_search_start_end(farm->note) == 2)
            i++;
        farm = farm->next;
    }
    return (i);
}

/*Checks  the number of ants*/
static int      ft_ants_map(t_notes *map)
{
    t_notes *farm;

    farm = map;
    if (ft_num_of_ants(farm) > 0)
        return (1);
    if (int_max(farm->note) == 0)
        return (1);
    return (0);
}

/* */
int         ft_check_farm(t_notes *map)
{
    t_notes *farm;
    
    farm = map;
    if (farm == NULL)
        return (0);
    if (ft_commands(farm) != 2)
        return (0);
    if (!ft_ants_map(farm))
        return (0);
    return (1); 
}