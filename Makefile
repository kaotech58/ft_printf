SRCS				= ft_printf.c \
					ft_numbers.c \
					ft_characters.c

OBJS_DIR			= objs/
OBJS				= $(SRCS:.c=.o)
OBJECTS_PREFIXED	= $(addprefix $(OBJS_DIR), $(OBJS))
DEPS				= ft_printf.h

NAME				= libftprintf.a

CC					= gcc
RMDIR				= rm -rf
RM					= rm -f
CCFLAGS				= -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c $(DEPS)
					@mkdir -p $(OBJS_DIR)
					@echo "Compiling: $<"
					@gcc $(CC_FLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJECTS_PREFIXED)
					ar rcs $(NAME) $(OBJECTS_PREFIXED)
					@echo "*** ft_printf has compiled successfully ***"

clean:
					$(RMDIR) $(OBJS_DIR)
					@echo "*** All Object files have been deleted ***"

fclean:				clean
					$(RM) $(NAME)
					@echo "*** ft_printf has been deleted ***"

re:					fclean all

.PHONY:				all clean fclean re
