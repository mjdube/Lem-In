# ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct      s_node 
{
    char    *nameRoom;
    int     visit;
    struct  s_node *next;
    struct  s_node *prev;
}                   t_block;


t_block         ft_createNode(void);

#endif