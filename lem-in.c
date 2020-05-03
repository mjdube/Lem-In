#include "src/lem_in.h"

int                 main(int argc, char **argv)
{
    char            *line;
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
    return (0);
}
