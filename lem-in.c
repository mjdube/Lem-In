#include "src/lem_in.h"

int                 main(int argc, char **argv)
{
    char            *start;
    char            *end;
    int             i;
    t_notes         *map;
    t_notes         *farm;
    t_block         *paths[1024];
    t_block         *links[1024];

    /* It replicates the map, saves as a linked list */ 
    map = create_map();
    farm = map;

    /* This checks if the farm has a ants, 
    rooms/links and the commands... still working the 
    solution to make a path */
    if (ft_check_farm(farm))
    {
        /* This function FT_SCAN scans for ##start room name, ##end room name
         and create links */
        ft_scan(&(*links), farm, &start, &end);

        /* This function FT_PATH_VISITS goes thru the links array variable 
        and look for room names that can create a path. The most important
        variable in this function is "visit_1", all visit by default is equal
        to 0 and are then changed to 1 if the room name is found and matched
        */
        ft_path_visits(start, end, ft_links_len(links), &(*links));

        /* This function FT_PATH_LIST does a similar thing like FT_PATH_VISIT
        function, it looks for the same thing but if "visit_1 = 1" and name is 
        found/matched. Once that is found and matched then we mark name room
        by changing "visit_2" to 1 because by default "visit_2 = 0" and then it
        creates a new linked list with a path
        */
        ft_path_list(start, end, ft_links_len(links), &(*links), &(*paths));

            if (ft_num_of_ants(farm) > 0)
            {

            }
            else 
                ft_putendl("Error");
    }
    else 
        ft_putendl("Error");
    /*
    char            **start;
    char            **end;
    int             count_links;
    int             count_paths;
    int             ants;
    int             fd;
    
    int i = 0;

    t_block         *pre_paths;
   
    t_block  *links[1024];
    t_block  *paths[1024];
    
    fd = 0;
    count_links = 0;
    count_paths = 0;

    get_next_line(fd, &line);
    ft_putendl(line);
    if (ft_checking_ants(line))
    {
        ants = ft_atoi(line);
        if (0 < ants)
        {
            while (get_next_line(fd, &line) == 1)
            {
                ft_putendl(line);
                if(ft_find_links(line) == 1)
                {
                    links[count_links] = ft_create_links(line);
                    count_links++;      
                }
                if (ft_search_start_end(line) == 1)
                {
                    get_next_line(fd, &line);
                    start = ft_strsplit(line, ' ');
                    ft_putendl(line);
                }
                else if (ft_search_start_end(line) == 2)
                {
                    get_next_line(fd, &line);
                    end = ft_strsplit(line, ' ');
                    ft_putendl(line);
                }
            }
           
                    ft_path_visits(start[0], end[0], count_links, &(*links));
                    ft_path_list(start[0], end[0], count_links, links, &(pre_paths));
                    while (pre_paths->next != NULL)
                    {
                        ft_putendl(pre_paths->nameRoom);
                        pre_paths = pre_paths->next;
                    }
                    paths[count_paths] = pre_paths;
                    count_paths++;
            
            // ft_path_list(start[0], end[0], count_links, &(*links), &pre_paths);
        }
        else 
            ft_putstr("ERROR\n");
    }
    else
        ft_putstr("ERROR\n");
        */    
    return (0);
}
