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

static int      next_room(t_block **path, t_map *graph, char **s)
{
    t_map           *g;
    t_block         *p;
    t_block         *temp;

    p = *path;
    g = graph;
    ft_putendl("next room ->> g->roomName");
    ft_putendl(g->roomName);
    ft_putendl("next room ->> start one");
        ft_putendl(*s);
        sleep(3);
    while (g)
    {
        if (ft_strcmp(g->roomName, *s) == 0)
            break ;
        g = g->rooms;
        ft_putendl("g->roomName");
        ft_putendl(g->roomName);
        ft_putendl("*sstart one");
        ft_putendl(*s);
        sleep(3);
    }
    ft_putstr("broke");
    ft_putendl("g->roomName");
    ft_putendl(g->roomName);
    ft_putendl("*sstart one");
    ft_putendl(*s);
    ft_putendl("found room name");
    while (p->next != NULL)
        p = p->next;
    sleep(3);
    temp = (t_block *)malloc(sizeof(t_block));
    g = g->links;
    temp->nameRoom = g->roomName;
    p->next = temp;
    temp->prev = p;
    ft_putstr("dup_name ->> ");
    ft_putnbr(dup_names(*path));
    ft_putchar('\n');
    sleep(3);
    while ((dup_names(*path) == 1) && g)
    {
        ft_putstr("dup_name ->> ");
        ft_putnbr(dup_names(*path));
        ft_putchar('\n');
        ft_putstr("roomName Before ");
        ft_putendl(g->roomName);
        if (g->links == NULL)
        {
            // free_path(&(*path));
            return (0);
        }
        g = g->links;
        temp->nameRoom = g->roomName;

        ft_putstr("roomName After ");
        ft_putendl(g->roomName);
        sleep(3);
    }
    if (g == 0)
        return (0);

    *s = g->roomName;
    ft_putendl("start two");
    ft_putendl(*s);
    // return (path);
    sleep(3);
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
        ft_putstr("*s ->>");
        ft_putendl(*s);
        ft_putstr("g->roomName ->> before ");
        ft_putendl(g->roomName);
        if (ft_strcmp(g->roomName, *s) == 0)
            break;
        g = g->rooms;
    }

    ft_putstr("g->roomName ->> after ");
        ft_putendl(g->roomName);


    (*path) = (t_block *)malloc(sizeof(t_block));
    (*path)->nameRoom = g->roomName;
    
    ft_putstr("g->roomName ->> ");
    ft_putendl(g->roomName);
    g = g->links;
    
    ft_putstr("visit 1\n");
    ft_putnbr(g->visit);
    ft_putchar('\n');
    while (g->visit == 1 && g->links != NULL)
        g = g->links;
    
    ft_putstr("visit 2\n");
    ft_putnbr(g->visit);
    ft_putchar('\n');
    if (g && g->visit == 0)
    {
        temp_1 = (t_block *)malloc(sizeof(t_block));
        temp_1->nameRoom = g->roomName;
        g->visit = 1;
        *s = g->roomName;
        
        ft_putstr("*s two ->>");
        ft_putendl(*s);


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

    path = NULL;
    // g = graph;
    start = s;
    count_path = 0;
    ft_putendl("beginning graph");
    ft_putendl(graph->roomName);
    while (look_for_start(&graph, &path, &start) != 0)
    {
        ft_putendl("Next room function");
        ft_putendl("checking graph");
        ft_putendl(graph->roomName);
        sleep(3);
        while (next_room(&path, graph, &start) == 1)
        {
            sleep(3);
            ft_putendl("is_path ->> ");
            ft_putnbr(is_path(path, e));
            ft_putchar('\n');
            if (is_path(path, e) == 1)
                break ;
        }
        ft_putendl("just");
        paths[count_path] = path;
        count_path++;
        path = NULL;
        start = s;
    }
}