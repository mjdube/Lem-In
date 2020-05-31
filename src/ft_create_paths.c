#include "lem_in.h"

void        free_path(t_block **path)
{
    t_block *p;

    ft_putendl((*path)->nameRoom);
    // p = *path;
    while ((*path)->next != NULL)
    {
        ft_putendl((*path)->nameRoom);
        p = *path;
        (*path) = (*path)->next;
        free(p);
    }
}

int         is_path(t_block *path, char *end)
{
    t_block *links;

    links = path;
    while (links)
    {
        if (ft_strcmp(links->nameRoom, end) == 0)
            return (1);
        links = links->next;
    }
    return (0);
}

int         dup_names(t_block *path)
{
    t_block *lst_1;
    t_block *lst_2;

    lst_1 = path;
    while (lst_1 != NULL)
    {
        lst_2 = lst_1->next;
        while (lst_2 != NULL)
        {
            if (ft_strcmp(lst_1->nameRoom, lst_2->nameRoom) == 0)
                return (1);
            lst_2 = lst_2->next;
        }
        lst_1 = lst_1->next;
    }
    return (0);
}

static int      next_room(t_block **path, t_map *graph, char **s, char *e)
{
    t_map           *g;
    t_block         *p;
    t_block         *temp;

    p = *path;
    g = graph;
    if (is_path(*path, e) == 1)
        return (2);
    while (g)
    {
        if (ft_strcmp(g->roomName, *s) == 0)
            break ;
        g = g->rooms;
        
    }
    
    while (p->next != NULL)
        p = p->next;
    
    temp = (t_block *)malloc(sizeof(t_block));
    g = g->links;
    temp->nameRoom = g->roomName;
    p->next = temp;
    temp->prev = p;
    
    while ((dup_names(*path) == 1) && g)
    {
        
        if (g->links == NULL)
        {
            // empty_stack(&(*path));
            // (*path) = NULL;
            return (0);
        }
        g = g->links;
        temp->nameRoom = g->roomName;

        
    }
    if (g == 0)
        return (0);

    *s = g->roomName;
    
    return (1);
}

static int          look_for_end(t_block *path, char *e)
{
    t_block     *p;

    p = path;
    while (p)
    {
        if (ft_strcmp(p->nameRoom, e) == 0)
            return (1);
        p = p->next;
    }
    return (0);
}

static int          look_for_start(t_map **graph, t_block **path, char **s)
{
    t_map           *g;
    t_block         *p;
    t_block         *temp_1;

    temp_1 = NULL;
    p = *path;
    g = *graph;
    if (*graph == NULL)
        return (0);
    
    // Look for start room
    while (g)
    {
        
        if (ft_strcmp(g->roomName, *s) == 0)
            break;
        g = g->rooms;
    }

    


    (*path) = (t_block *)malloc(sizeof(t_block));
    (*path)->nameRoom = g->roomName;
    
    
    g = g->links;
    
    
    while (g->visit == 1 && g->links != NULL)
        g = g->links;
    
    if (g && g->visit == 0)
    {
        temp_1 = (t_block *)malloc(sizeof(t_block));
        temp_1->nameRoom = g->roomName;
        g->visit = 1;
        *s = g->roomName;


        (*path)->next = temp_1;
        temp_1->prev = (*path);
        (*path)->prev = NULL;
        temp_1->next = NULL;
    }
    else
        return (0);

    return (1);
}

void                ft_create_paths(t_block **paths, t_map *graph, char *s, char *e)
{
    int             count_path;
    // t_map           *g;
    t_block         *path;
    t_block         **ps;
    char            *start;
    int             valid_1;
    int             valid_2;

    path = NULL;
    // g = graph;
    start = s;
    count_path = 0;
    while (look_for_start(&graph, &path, &start) != 0)
    {
        while ((valid_1 = next_room(&path, graph, &start, e)) == 1)
        {
            if ((valid_2 = is_path(path, e)) == 1)
                break ;
        }
        
        if (valid_1 == 0)
        {
            path = NULL;
            start = s;
        }
        else if (valid_1 == 2 || valid_2 == 1)
        {
            paths[count_path] = path;
            count_path++;
            path = NULL;
            start = s;
        }
    }
}