NAME	= miniRT
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Werror -Wextra -Iinc -Isrc/libft -Isrc/libft/gnl
LDFLAGS = -L src/libft -lft
DLIB	= ./src/libft/
NLIB	= libft.a
SRC 	= miniRT.c
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
			@$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean	:
			@make clean -C $(DLIB)
			@$(RM) $(OBJ)

fclean	:	clean
			@make fclean -C $(DLIB)
			@$(RM) $(NAME)

re	:	fclean $(NAME)

bonus	:

.PHONY	:	all clean fclean re bonus
