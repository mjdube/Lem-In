# ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct      s_node 
{
    char    *nameRoom;
    int     visit_1;
    int     visit_2;
    struct  s_node *next;
    struct  s_node *prev;
}                   t_block;

t_block         *ft_createNode(void);
void         ft_path_list(char *start, char *end, int size, t_block **links, t_block **list);
t_block         *ft_create_links(char *s);
void        ft_path_visits(char *start,char *end, int size, t_block **links);


int             ft_checking_ants(char *s);
int             ft_search_start_end(char *s);
int             ft_find_links(char *s);

#endif