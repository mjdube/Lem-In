# ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct		s_keys
{
	char			*start;
	char			*end;
	char			*read;
	int				ants;
	int				rooms;              
	int				room_counter;               
}			        t_keys;

typedef struct		s_rooms
{
	char		    *data;          
    struct s_rooms	*next;
}			        t_rooms;

typedef struct		s_links
{
	int				**links;            
}			        t_links;

typedef struct		s_path
{
	int		    	*visits;
	char			*map;
	struct  s_path	*next;
}			        t_path;

typedef struct		s_visit
{
	int				*path;
}					t_visit;

t_rooms		*ft_create_rooms(t_keys *keys, t_rooms *t_rooms);
t_rooms		*ft_rooms(t_rooms *rooms, char *room_name, t_keys *keys);

t_links		*ft_create_links(t_links *links, t_rooms *rooms, t_keys *keys);
t_links		*ft_make_links(t_links *links, int links_len);

t_path		*ft_start_path(t_path *visit, t_keys *keys, int start);
t_visit		*ft_rec_visit(t_visit *visit, t_keys *keys, int start);

t_path		*ft_final_path(t_path *visit, t_path *map, t_rooms *rooms, t_keys *keys);
t_path		*ft_display_1(t_path *map, t_keys *keys);
t_path		*ft_create_path(t_rooms *rooms, t_links *links, t_keys *keys, t_path  *visit);

char 		**ft_display_2(t_keys *keys, char **temp, int size);

int			ft_is_link(char *exist, t_rooms *rooms);
int         ft_search_start_end(char *s);
int		    ft_int_max(char *str);
int			ft_print_3(int check, char **path, t_keys *keys, int size);
int			ft_print_2(int check, char **path, t_keys *keys);
int			ft_print_1(int check, char **path, t_keys *keys);
int         ft_print_ants_2(int check, char **roomName, t_keys *keys);
int         ft_print_ants_1(int check, char **roomName, t_keys *keys);
int			ft_dup(int *visited, int v, int links_len);
int         ft_decrem_visit(int j);
int			ft_check_room(char *roomName, t_rooms *rooms);
int			ft_is_room(char *roomName);
int			ft_is_path(char *str, t_path *path);


void		empty(t_links *links, t_rooms *rooms, t_path *visit, t_keys *keys, t_path *map);
void		empty_stack(char **tmp, int x);
void	    ft_begin(t_keys *keys);
void	    ft_check_start_end(t_keys *keys);
void	    ft_num_of_ants(t_keys *keys);
void		empty_map(t_path *map);
#endif