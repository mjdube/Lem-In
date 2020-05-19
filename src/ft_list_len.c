#include "lem_in.h"

// returns the length of the list

int         ft_list_len(t_block *stack)
{
    int     i;
    t_block *lst;

    i = 0;
    lst = stack;
    if (lst == NULL)
        return (0);
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}