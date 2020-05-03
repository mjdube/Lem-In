#include "lem_in.h"

static t_block      *ft_path_creation(t_block *links, t_block *list)
{
    t_block         *temp;

    temp = NULL;
    if (links == NULL)
        return (NULL);
    if (list == NULL)
    {
        list = links;
        return (list);
    }
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = links;
    links->prev = temp;
    return (list);
}

static t_block      *ft_path_creation_reverse(t_block *links, t_block *list)
{
    t_block         *temp;

    temp = NULL;
    if (links == NULL)
        return (NULL);
    if (list == NULL)
    {
        list = links;
        return (list);
    }
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = links;
    links = links->prev;
    links->next = links->prev;
    temp = temp->next;
    links->prev = temp;
    return (list);  
}

void                ft_path_list(char *start, char *end, int size, t_block **links, t_block **list)
{
    int             i;

    i = 0;
    if (start == NULL ||links == NULL)
        return ;
    while (i < size && ft_strcmp(start, end) != 0)
    {
        if (ft_strcmp(links[i]->nameRoom, start) == 0) 
        {
            if (links[i]->visit_2 == 0)
            {
                start = links[i]->next->nameRoom;
                links[i]->visit_2 = 1;
                links[i]->next->visit_2 = 1;
                (*list) = ft_path_creation(links[i], (*list));
                i = 0;
            }
            else 
                i++;         
        }
        else if (ft_strcmp(links[i]->next->nameRoom, start) == 0)
        {
            if (links[i]->next->visit_2 == 0)
            {   
                start = links[i]->next->prev->nameRoom;
                links[i]->next->visit_2 = 1;
                links[i]->next->prev->visit_2 = 1;
                (*list) = ft_path_creation_reverse(links[i]->next, (*list));
                i = 0;
            }
            else 
                i++;
        }
        else
            i++;
        // ft_putendl(ft_itoa(i));
    }
}