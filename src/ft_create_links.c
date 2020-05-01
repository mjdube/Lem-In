#include "lem_in.h"

t_block         *ft_create_links(char *s)
{
    t_block     *node_1;
    t_block     *node_2;
    char        **link_node;
    static int  i = 0;
    
    link_node = ft_strsplit(s, '-');
    node_1 = ft_createNode();
    node_2 = ft_createNode();
    node_1->nameRoom = link_node[0];
    node_2->nameRoom = link_node[1];
    node_1->next = node_2;
    node_2->prev = node_1;
    return (node_1);
}