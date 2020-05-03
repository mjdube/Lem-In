#include "lem_in.h"

t_block     *ft_createNode(void)
{
    t_block *node;

    node = (t_block*)ft_memalloc(sizeof(t_block));
    node->nameRoom = NULL;
    node->visit_1 = 0;
    node->visit_2 = 0;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}