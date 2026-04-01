NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
ALG        ?= adaptive
SIZE       ?= 500
ARG        := $(shell seq 1 $(SIZE) | shuf | tr '\n' ' ')

LIBFT_DIR   = ft_libft
LIBFT       = $(LIBFT_DIR)/libft.a
 
SRCS        = ps_parser.c push_swap.c ps_utils.c ps_utils_2.c ps_benchmark.c \
              	ps_ops.c ps_ops_2.c ps_ops_3.c ps_medium_alg.c ps_alg.c ps_lst_to_index.c

BONUS_SRCS  = ps_parser.c ps_checker.c ps_utils.c ps_utils_2.c ps_ops.c ps_ops_2.c ps_ops_3.c \
              	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ps_medium_alg.c ps_alg.c 

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

alg: all bonus
	@./$(NAME) --bench --$(ALG) $(ARG) 2> bench.txt > ops.txt
	@echo "My Checker: "
	@./$(BONUS_NAME) $(ARG) < ops.txt
	@echo "Original Checker: "
	@./checker_linux $(ARG) < ops.txt
	@cat bench.txt

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) bench.txt ops.txt
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus alg