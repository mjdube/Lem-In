#include "lem_in.h"

void        print(t_block *path, int ant)
{
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(path->nameRoom);
}

void        ft_display(t_ants *ants, t_block *path)
{
    int     i;
    t_block *p;
    t_ants  *a;

    i = 1;
    p = path;
    a = ants;
    while (a->next != NULL)
    {
        a->link->ants = p;
        while (p->next != NULL)
        {
            p = p->next;
        }
        a = a->next;
    }
}