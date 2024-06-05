NAME = fdf

CC = gcc

CFLAGS =  -Werror -Wall -Wextra

RM = rm -rf

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c read_file.c main.c paint_line.c help_functions.c \
		help_functions_2.c help_functions_3.c main_blocks.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx

MLX_LIB = $(MLX_DIR)/libmlx.a

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C ft_printf
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBFT) ft_printf/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# rotate.o: rotate.c
# 	$(CC) $(CFLAGS) -c rotate.c

all : $(NAME)

fclean: clean
	$(RM) $(NAME)
#	make clean -C $(LIBFT_DIR)
#	make clean -C ft_printf
#	make clean -C $(MLX_DIR)

clean :
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C ft_printf
	make clean -C $(MLX_DIR)

re : fclean all

.PHONY: all fclean