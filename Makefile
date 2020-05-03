LEM_IN = lem-in.c
LIBFT = libft.a

SRC = ft_checking_ants.c ft_createNode.c ft_search_start_end.c ft_find_links.c ft_path_list.c ft_path_visits.c

OBJ = ft_checking_ants.o ft_createNode.o ft_search_start_end.o ft_find_links.o ft_path_list.o ft_path_visits.o

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