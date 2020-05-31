#include "lem_in.h"

t_ants      *ft_ants(int ants)
{
    t_ants  *head;
    t_ants  *temp;
    t_ants  *node;
    int     i;

    i = 1;
    if (ants == 0)
        return (NULL);
    
    head = (t_ants *)malloc(sizeof(t_ants));
    head->number = 1;
    head->next = NULL;
    head->prev = NULL;
    i++;
    while (i <= ants)
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        node = (t_ants *)malloc(sizeof(t_ants));
        node->number = i;
        temp->next = node;
        node->prev = temp;
        node->next = NULL;
        i++;
    }
    free(temp);
    return (head);
}