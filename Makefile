NAME	= miniRT
CC	= gcc
RM	= rm -f
CFLAGS = -Wall -Werror -Wextra -I inc -I src/libft -I src/libft/gnl -I MLX42/include/MLX42 -fsanitize=address -g
#LDFLAGS = -L src/libft -L src/libft/gnl -L MLX42/include/MLX42 -L MLX42/include -lft
DLIB	= ./src/libft/
DMLX	= ./MLX42/
NMLX	= libmlx42.a

ifeq ($(shell uname), Linux)
	LIBS = $(DMLX)$(NMLX) -ldl -lglfw -pthread -lm
else ifeq ($(findstring Darwin, $(shell uname)), Darwin)
	LIBS = $(DMLX)$(NMLX) ./MLX42/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
else
	$( info **** S.O no ha sido reconocido ****)
endif

NLIB	= libft.a
SRC	=	main			\
	 	miniRT
RAYTR = raytracing
PX	=	px_size			\
	 	vector
TEST =	testsphere		\
	  	testvector		\
	  	testxpm			\
	  	testxpm1		\
		testcolor		\
		testplane
INTS =  sphere			\
		plane			\
		vector			\
		cylinder		
CLS	=	rf_ambient		\
		rf_difuse		\
		colors			\
		phong
XPM =	xpm				\
		utils_xpm		\
		utils1_xpm		\
		colorxpm		\
		modify_dfclr	\
		map_xpm			\
		addclr_utils
PARSE	= open_file		\
		  atof parse	\
		  fill_scene	\
		  save_data		\
		  figures		\
		  check_vec3d	\
		  pre_read
UTILS	= input_error	\
		  error_msg		\
		  vcpy			\
		  quit_n		\
		  check_range	\
		  free_arg
VECTOR	= calculus	\
		  plane_calculus

BON	=

FILES	= $(SRC) $(PX) $(INTS) $(TEST) $(CLS) $(XPM) $(PARSE) $(UTILS) $(RAYTR) $(VECTOR)
DPARSE	= $(addprefix parse/, $(PARSE))
DRAYTR	= $(addprefix raytr/, $(RAYTR))
DUTILS = $(addprefix utils/, $(UTILS))
DXPM	= $(addprefix xpm/,$(XPM))
DCLS	= $(addprefix colors/,$(CLS))
DTEST	= $(addprefix test/,$(TEST))
DINTS	= $(addprefix intersec/,$(INTS))
DVEC	= $(addprefix vector/,$(VECTOR))
DPX		= $(addprefix pixel/,$(PX))
DSRC	= $(addprefix ./src/,$(SRC) $(DPX) $(DINTS) $(DTEST) $(DCLS) $(DXPM) $(DPARSE) $(DUTILS) $(DRAYTR) $(DVEC))
DBON	= $(addprefix ./src/,$(BON))
ALLC	= $(addsuffix .c,$(DSRC))
ALLBON	= $(ALLC)
DOBJ	= $(addprefix ./obj/,$(FILES))
OBJ 	= $(addsuffix .o,$(DOBJ))

all 	:	$(NAME)

$(OBJ)	:	$(ALLC)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			@make bonus -C $(DLIB)
			@make -C $(DMLX)
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
