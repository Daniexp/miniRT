NAME	= miniRT
CC	= gcc
RM	= rm -f
CFLAGS = -Wall -Werror -Wextra -Iinc -Isrc/libft -Isrc/libft/gnl -IMLX42/include/MLX42 -IMLX42/include/
LDFLAGS = -L src/libft -lft
DLIB	= ./src/libft/
DMLX	= MLX42/
NMLX	= libmlx42.a
ifeq ($(shell uname), Linux)
	LIBS = $(DMLX)$(NMLX) -ldl -lglfw -pthread -lm
else ifeq ($(findstring Darwin, $(shell uname)))
	LIBS = $(DMLX)$(NMLX) ./MLX42/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(shell uname), Arch)
	LIBS = $(DMLX)$(NMLX)
else
	$( info **** S.O no ha sido reconocido ****)
endif
#endif
NLIB	= libft.a
SRC 	= main.c
#miniRT.c
BON		=
DSRC	= $(addprefix ./src/,$(SRC))
DBON	= $(addprefix ./src/,$(DBON))
ALLC	= $(DSRC)
ALLBON	= $(ALLC) $(DBON)
OBJ 	= $(DSRC:.c=.o)

all 	:	$(NAME)

$(OBJ)	:	$(ALLC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			@make bonus -C $(DLIB)
			@make -C $(DMLX)
			@$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $(DLIB)$(NLIB)

clean	:
			@make clean -C $(DLIB)
			@make clean -C $(DMLX)
			@$(RM) $(OBJ)

fclean	:	clean
			@make fclean -C $(DLIB)
			@make fclean -C $(DMLX)
			@$(RM) $(NAME)

re	:	fclean $(NAME)

bonus	:

.PHONY	:	all clean fclean re bonus
