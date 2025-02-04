SRC = main.c \
      parsing.c \
	  parsing_utils.c \
	  quicksort.c \
	  quartils.c \
	  push_swap.c \
	  best_move.c \
	  finds.c \
	  push.c \
	  swap.c \
	  rotate.c \
	  reverse_rotate.c \
	  push_stack.c \
	  remove_stack.c \
	  stack_utils.c \
	#   push_swap_utils.c \
	#   insert.c \

CFLAGS = -Wall -Wextra -Werror -g3
HEADER = push_swap.h
NAME = push_swap
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
