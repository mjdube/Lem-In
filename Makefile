LEM_IN = checker.c
LIBFT = libft.a

SRC = rb_sb_rrb.c int_max.c dup_nums.c three_nums.c more_nums.c loop_stack_1.c top_bottom.c\
small_number.c is_sorted.c compare_numbers.c ft_checking_numbers.c \
is_verify.c reading_instr.c ft_instr.c ft_instr_both.c push.c pop_number.c \
push_to_stack.c push_list.c create_node.c create_stack.c \
rotate_normal.c rotate_reverse.c list_length.c swap_data.c loop_stack_2.c\
big_number.c is_sorted_b.c

OBJ = rb_sb_rrb.o int_max.o dup_nums.o three_nums.o more_nums.o loop_stack_1.o top_bottom.o \
small_number.o is_sorted.o compare_numbers.o ft_checking_numbers.o \
is_verify.o reading_instr.o ft_instr.o ft_instr_both.o push.o pop_number.o \
push_to_stack.o push_list.o create_node.o create_stack.o \
rotate_normal.o rotate_reverse.o list_length.o swap_data.o loop_stack_2.o\
big_number.o is_sorted_b.o

DIRSRC = ./src
DIRLIBFT = ./libft

LIBRARY = lem_in.a

#FLAGS = -Wall -Werror -Wextra

all: libft_com lem_in_lib push_swap checker clean

lem_in_lib:
	@gcc -c src/*.c
	@ar rc lem_in.a *.o
	@$(MAKE) clean

libft_com:
	$(MAKE) -C $(DIRLIBFT)
	$(MAKE) clean -C $(DIRLIBFT)

lem_in:
	gcc $(LEM_IN) -o lem-in lem_in.a libft/libft.a 
#push_swap: 
	#@gcc $(PUSH_SWAP) -o push_swap push_swap.a libft/libft.a $(FLAGS) 
	
#checker: 
	#@gcc $(CHECKER) -o checker push_swap.a libft/libft.a $(FLAGS) 

clean :
	rm -fr *.o
	#@echo "cleaning object files..."

fclean: clean 
	@rm -fr $(LIBRARY)
	@$(MAKE) fclean -C $(DIRLIBFT)
	@rm lem_in
	@echo "library deleted..."

re: fclean all