LEM_IN = lem-in.c
LIBFT = libft.a

SRC = execute.c ft_rooms.c ft_create_rooms.c ft_final_path.c ft_create_links.c ft_display_1.c ft_create_path.c \
empty.c ft_display_2.c ft_int_max.c ft_print.c ft_validate_links.c ft_print_ants.c ft_search_start_end.c ft_validate_path.c \
ft_validate_room_visits.c ft_validate_room.c ft_visit_path.c ft_create_map.c \
ft_display_map.c

OBJ = execute.o ft_rooms.o ft_create_rooms.o ft_final_path.o ft_create_links.o ft_display_1.o ft_create_path.o \
empty.o ft_display_2.o ft_int_max.o ft_print.o ft_validate_links.o ft_print_ants.o ft_search_start_end.o ft_validate_path.o \
ft_validate_room_visits.o ft_validate_room.o ft_visit_path.o ft_create_map.o \
ft_display_map.o

DIRSRC = ./src
DIRLIBFT = ./libft

LIBRARY = lem-in.a

FLAGS = -Wall -Werror -Wextra

all: libft_com lem-in_lib lem-in clean

lem-in_lib:
	@cd $(DIRSRC)
	@gcc -c $(DIRSRC)/*.c -g
	@ar rc $(DIRSRC)/lem-in.a *.o
	@rm -fr *.o

libft_com:
	$(MAKE) -C $(DIRLIBFT)
	$(MAKE) clean -C $(DIRLIBFT)

lem-in:
	@gcc $(LEM_IN) -o lem-in $(DIRSRC)/lem-in.a libft/libft.a $(FLAGS)

clean:
	@rm -fr $(DIRSRC)/*.o
	@rm -fr $(DIRLIBFT)/*.o
	@echo "cleaning object files..."

fclean: clean 
	@rm -fr $(DIRSRC)/$(LIBRARY)
	@$(MAKE) fclean -C $(DIRLIBFT)
	@rm lem-in
	@rm -fr $(DIRSRC)/*.o
	@rm -fr $(DIRLIBFT)/*.o
	@echo "library deleted..."

re: fclean all