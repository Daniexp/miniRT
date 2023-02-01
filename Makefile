NAME	= miniRT
CC	= gcc
RM	= rm -f
CFLAGS = -Wall -Werror -Wextra -I inc -I src/libft -I src/libft/gnl -I MLX42/include/MLX42
#LDFLAGS = -L src/libft -L src/libft/gnl -L MLX42/include/MLX42 -L MLX42/include -lft
DLIB	= ./src/libft/
DMLX	= ./MLX42/
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
endif
NLIB	= libft.a
SRC	= main \
	  kaaa
PX	= px_size \
	  vector
TEST = testsphere
INTS =  sphere
BON	=
FILES	= $(SRC) $(PX) $(INTS)
DTEST	= $(addprefix test/,$(TEST))
DINTS	= $(addprefix intersec/,$(INTS))
DPX		= $(addprefix pixel/,$(PX))
DSRC	= $(addprefix ./src/,$(SRC) $(DPX) $(DINTS) $(DTEST))
DBON	= $(addprefix ./src/,$(BON))
ALLC	= $(addsuffix .c,$(DSRC))
ALLBON	= $(ALLC)
DOBJ	= $(addprefix ./obj/,$(FILES))
OBJ 	= $(addsuffix .o,$(DOBJ))

all 	:	$(NAME)

$(OBJ)	:	$(ALLC)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			make bonus -C $(DLIB)
			make -C $(DMLX)
			$(CC) $(CFLAGS) $(ALLC) $(DMLX)$(NMLX) $(DLIB)$(NLIB) -o $(NAME) $(LIBS)

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
