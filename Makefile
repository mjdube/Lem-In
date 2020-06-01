LEM_IN = lem-in.c
LIBFT = libft.a

SRC = execute.c ft_rooms.c ft_create_rooms.c ft_final_path.c ft_create_links.c ft_display_1.c ft_create_path.c \
empty.c ft_display_2.c int_max.c ft_print.c

OBJ = execute.o ft_rooms.o ft_create_rooms.o ft_final_path.o ft_create_links.o ft_display_1.o ft_create_path.o \
empty.o ft_display_2.o int_max.o ft_print.o

DIRSRC = ./src
DIRLIBFT = ./libft

LIBRARY = lem-in.a

#FLAGS = -Wall -Werror -Wextra

all: libft_com lem-in_lib lem-in clean

lem-in_lib:
	@cd $(DIRSRC)
	@gcc -c $(DIRSRC)/*.c
	@ar rc $(DIRSRC)/lem-in.a *.o
	@rm -fr *.o

libft_com:
	$(MAKE) -C $(DIRLIBFT)
	$(MAKE) clean -C $(DIRLIBFT)

lem-in:
	@gcc $(LEM_IN) -o lem-in $(DIRSRC)/lem-in.a libft/libft.a  

clean:
	@rm -fr $(DIRSRC)/*.o
	@echo "cleaning object files..."

fclean: clean 
	@rm -fr $(DIRSRC)/$(LIBRARY)
	@$(MAKE) fclean -C $(DIRLIBFT)
	@rm lem-in
	@rm -fr $(DIRSRC)/*.o
	@echo "library deleted..."

re: fclean all