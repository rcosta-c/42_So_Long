################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
NAME_BONUS  := so_long_bonus
CC        := cc
FLAGS    := -Wall -Wextra -Werror -ggdb3 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      lib/ft_printf/ft_printstr.c \
                          lib/ft_printf/ft_printu.c \
                          lib/ft_printf/ft_p_strlen.c \
                          lib/ft_printf/libft/ft_lstlast.c \
                          lib/ft_printf/libft/ft_isalpha.c \
                          lib/ft_printf/libft/ft_strdup.c \
                          lib/ft_printf/libft/ft_strnstr.c \
                          lib/ft_printf/libft/ft_memchr.c \
                          lib/ft_printf/libft/ft_substr.c \
                          lib/ft_printf/libft/ft_strchr.c \
                          lib/ft_printf/libft/ft_strlcpy.c \
                          lib/ft_printf/libft/ft_strncmp.c \
                          lib/ft_printf/libft/ft_tolower.c \
                          lib/ft_printf/libft/ft_memmove.c \
                          lib/ft_printf/libft/ft_strmapi.c \
                          lib/ft_printf/libft/ft_lstiter.c \
                          lib/ft_printf/libft/ft_strlcat.c \
                          lib/ft_printf/libft/ft_strlen.c \
                          lib/ft_printf/libft/ft_lstmap.c \
                          lib/ft_printf/libft/ft_isprint.c \
                          lib/ft_printf/libft/ft_atoi.c \
                          lib/ft_printf/libft/ft_isdigit.c \
                          lib/ft_printf/libft/ft_memset.c \
                          lib/ft_printf/libft/ft_lstnew.c \
                          lib/ft_printf/libft/ft_strrchr.c \
                          lib/ft_printf/libft/ft_itoa.c \
                          lib/ft_printf/libft/ft_strtrim.c \
                          lib/ft_printf/libft/ft_putnbr_fd.c \
                          lib/ft_printf/libft/ft_isalnum.c \
                          lib/ft_printf/libft/ft_putstr_fd.c \
                          lib/ft_printf/libft/ft_lstsize.c \
                          lib/ft_printf/libft/ft_isascii.c \
                          lib/ft_printf/libft/ft_lstdelone.c \
                          lib/ft_printf/libft/ft_strjoin.c \
                          lib/ft_printf/libft/ft_memcpy.c \
                          lib/ft_printf/libft/ft_lstclear.c \
                          lib/ft_printf/libft/ft_charjoin2str.c \
                          lib/ft_printf/libft/ft_memcmp.c \
                          lib/ft_printf/libft/ft_bzero.c \
                          lib/ft_printf/libft/ft_putendl_fd.c \
                          lib/ft_printf/libft/ft_striteri.c \
                          lib/ft_printf/libft/ft_calloc.c \
                          lib/ft_printf/libft/ft_putchar_fd.c \
                          lib/ft_printf/libft/ft_split.c \
                          lib/ft_printf/libft/ft_lstadd_front.c \
                          lib/ft_printf/libft/ft_lstadd_back.c \
                          lib/ft_printf/libft/ft_toupper.c \
                          lib/ft_printf/ft_printf.c \
                          lib/ft_printf/ft_printchar.c \
                          lib/ft_printf/ft_printx_ubase.c \
                          lib/ft_printf/ft_printptr.c \
                          lib/ft_printf/ft_printnbr_base.c \
                          lib/ft_printf/ft_printx_lbase.c \
                          lib/ft_printf/ft_printnbr.c \
                          lib/gnl/get_next_line_utils.c \
                          lib/gnl/get_next_line.c \
                          src/so_long.c \
                          src/error.c \
                          src/measure_map.c \
                          src/check_utils.c \
                          src/check_map.c \
                          src/map.c \
                          src/flood_map.c \
                          src/validate.c \
                          src/hooks.c \
                          src/place_graphics.c \
                          src/graphic.c
                          
SRCS_BONUS        :=      lib/ft_printf/ft_printstr.c \
                          lib/ft_printf/ft_printu.c \
                          lib/ft_printf/ft_p_strlen.c \
                          lib/ft_printf/libft/ft_lstlast.c \
                          lib/ft_printf/libft/ft_isalpha.c \
                          lib/ft_printf/libft/ft_strdup.c \
                          lib/ft_printf/libft/ft_strnstr.c \
                          lib/ft_printf/libft/ft_memchr.c \
                          lib/ft_printf/libft/ft_substr.c \
                          lib/ft_printf/libft/ft_strchr.c \
                          lib/ft_printf/libft/ft_strlcpy.c \
                          lib/ft_printf/libft/ft_strncmp.c \
                          lib/ft_printf/libft/ft_tolower.c \
                          lib/ft_printf/libft/ft_memmove.c \
                          lib/ft_printf/libft/ft_strmapi.c \
                          lib/ft_printf/libft/ft_lstiter.c \
                          lib/ft_printf/libft/ft_strlcat.c \
                          lib/ft_printf/libft/ft_strlen.c \
                          lib/ft_printf/libft/ft_lstmap.c \
                          lib/ft_printf/libft/ft_isprint.c \
                          lib/ft_printf/libft/ft_atoi.c \
                          lib/ft_printf/libft/ft_isdigit.c \
                          lib/ft_printf/libft/ft_memset.c \
                          lib/ft_printf/libft/ft_lstnew.c \
                          lib/ft_printf/libft/ft_strrchr.c \
                          lib/ft_printf/libft/ft_itoa.c \
                          lib/ft_printf/libft/ft_strtrim.c \
                          lib/ft_printf/libft/ft_putnbr_fd.c \
                          lib/ft_printf/libft/ft_isalnum.c \
                          lib/ft_printf/libft/ft_putstr_fd.c \
                          lib/ft_printf/libft/ft_lstsize.c \
                          lib/ft_printf/libft/ft_isascii.c \
                          lib/ft_printf/libft/ft_lstdelone.c \
                          lib/ft_printf/libft/ft_strjoin.c \
                          lib/ft_printf/libft/ft_memcpy.c \
                          lib/ft_printf/libft/ft_lstclear.c \
                          lib/ft_printf/libft/ft_charjoin2str.c \
                          lib/ft_printf/libft/ft_memcmp.c \
                          lib/ft_printf/libft/ft_bzero.c \
                          lib/ft_printf/libft/ft_putendl_fd.c \
                          lib/ft_printf/libft/ft_striteri.c \
                          lib/ft_printf/libft/ft_calloc.c \
                          lib/ft_printf/libft/ft_putchar_fd.c \
                          lib/ft_printf/libft/ft_split.c \
                          lib/ft_printf/libft/ft_lstadd_front.c \
                          lib/ft_printf/libft/ft_lstadd_back.c \
                          lib/ft_printf/libft/ft_toupper.c \
                          lib/ft_printf/ft_printf.c \
                          lib/ft_printf/ft_printchar.c \
                          lib/ft_printf/ft_printx_ubase.c \
                          lib/ft_printf/ft_printptr.c \
                          lib/ft_printf/ft_printnbr_base.c \
                          lib/ft_printf/ft_printx_lbase.c \
                          lib/ft_printf/ft_printnbr.c \
                          lib/gnl/get_next_line_utils.c \
                          lib/gnl/get_next_line.c \
                          src_bonus/so_long_bonus.c \
                          src_bonus/error_bonus.c \
                          src_bonus/measure_map_bonus.c \
                          src_bonus/check_utils_bonus.c \
                          src_bonus/check_map_bonus.c \
                          src_bonus/map_bonus.c \
                          src_bonus/flood_map_bonus.c \
                          src_bonus/validate_bonus.c \
                          src_bonus/hooks_bonus.c \
                          src_bonus/place_graphics_bonus.c \
                          src_bonus/graphic_bonus.c
OBJS        := $(SRCS:.c=.o)

OBJS_BONUS  := $(SRCS_BONUS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx/minilibx_linux/configure
			@ $(MAKE) -C mlx/minilibx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -L ./mlx/minilibx_linux -lmlx -Ilmlx -lXext -lX11
			@echo "$(GREEN)$(NAME) created[0m ✔️"

$(NAME_BONUS): ${OBJS_BONUS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME_BONUS) ${CLR_RMV}..."
			@chmod 777 mlx/minilibx_linux/configure
			@ $(MAKE) -C mlx/minilibx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME_BONUS) $(OBJS_BONUS) -L ./mlx/minilibx_linux -lmlx -Ilmlx -lXext -lX11
			@echo "$(GREEN)$(NAME_BONUS) created[0m ✔️"

all:		${NAME}

bonus:      $(NAME_BONUS)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ rm -rf $(NAME_BONUS) .dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(NAME_BONUS) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ $(RM) $(NAME_BONUS)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(NAME_BONUS) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all bonus clean fclean re


