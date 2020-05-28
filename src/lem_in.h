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

typedef struct      s_map
{
    char    *roomName;
    int     visit;
    struct  s_map  *links;
    struct  s_map  *rooms;
}                   t_map;

typedef struct      n_node
{
    char            *note;
    struct n_node   *next;
    struct n_node   *prev;
}                   t_notes;

t_block         *ft_createNode(void);
t_block         *ft_create_links(char *s);
// t_block         **ft_create_paths(char *start, char *end, t_block **links);
// t_block         **ft_create_paths(t_map *graph, char *s, char *e);
void            ft_create_paths(t_block **paths, t_map *graph, char *s, char *e);


t_block         *ft_path_list(char *start, char *end, int size, t_block **links);

t_notes         *create_map(void);

t_map           *ft_create_graph(t_block **links);

// void            ft_path_list(char *start, char *end, int size, t_block **links, t_block **list);

// void            ft_path_visits(char *start,char *end, int size, t_block **links);
void            ft_scan(t_block **links, t_notes *map, char **s, char **e);

int             ft_path_visits(char *start, char *end, int size, t_block **links);

int             check_links(t_map *graph, t_block *link);
int             check_room(t_map *graph, t_block *link);

int             ft_checking_ants(t_notes *map);
int             ft_num_of_ants(t_notes *map);
int             ft_search_start_end(char *s);
int             ft_find_links(char *s);
int             ft_check_farm(t_notes *map);
int             ft_list_len(t_block *stack);
int             ft_links_len(t_block **links);

#endif