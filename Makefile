NAME       = push_swap
BONUS_NAME = checker

CC         = cc
CFLAGS     = -Wall -Wextra -Werror
SIZE      ?= 500
ARG       := $(shell seq 1 $(SIZE) | shuf | tr '\n' ' ')

LIBFT_DIR  = ft_libft
LIBFT      = $(LIBFT_DIR)/libft.a

# 1. ORTAK DOSYALAR (Her iki program da parser, utils ve opr dosyalarını kullanacak)
# Not: ps_main.c içinde parser olduğu için onu ortaklara aldık.
COMMON_SRCS = ps_main.c ps_utils.c ps_utils_2.c ps_error.c ps_opr.c ps_opr_2.c

# 2. PUSH_SWAP ÖZEL (İçinde push_swap main'i, router ve algoritmalar var)
PS_SRCS     = push_swap.c ps_benchmark.c ps_medium_sort.c ps_simple_sort.c ps_complex.c

# 3. CHECKER ÖZEL (İçinde checker main'i ve gnl var)
CHECKER_SRCS= ps_checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)
PS_OBJS     = $(PS_SRCS:.c=.o)
CHECKER_OBJS= $(CHECKER_SRCS:.c=.o)

all: $(LIBFT) $(NAME)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(COMMON_OBJS) $(PS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(PS_OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(COMMON_OBJS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJS) $(LIBFT) -o $(BONUS_NAME)

adaptive: all bonus
	@./$(NAME) --bench $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

simple: all bonus
	@./$(NAME) --bench --simple $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

medium: all bonus
	@./$(NAME) --bench --medium $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

complex: all bonus
	@./$(NAME) --bench --complex $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

clean:
	rm -f $(COMMON_OBJS) $(PS_OBJS) $(CHECKER_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) bench.txt
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus adaptive simple medium complex