NAME					=	2048

#############################################################################
#																			#
#									COMPILER								#
#																			#
#############################################################################

CC		=		cc
CFLAGS	=		-MMD -Wall -Wextra -Werror -g3
INC		=		-I ./libft/includes\
				-I ./includes
				


#############################################################################
#																			#
#									FILES									#
#																			#
#############################################################################

SRCS	=	test.c					\
			block.c utils.c move.c
OBJS	=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEPS	=	$(OBJS:.o=.d)
LIBFT	=	$(addprefix $(LIBFT_PATH), libft.a) 


#############################################################################
#																			#
#									PATHS									#
#																			#
#############################################################################

SRCS_PATH	=	./srcs/
OBJS_PATH	=	./objects/
LIBFT_PATH	=	./libft/


#############################################################################
#																			#
#									RULES									#
#																			#
#############################################################################

all:				$(NAME)

$(NAME):			$(OBJS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) -lncurses

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
					@mkdir -p $(OBJS_PATH)
					$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
					@make -C $(LIBFT_PATH) --no-print-directory
clean:				
					@rm -rf $(OBJS_PATH)
					@echo "Objs cleaned!"

fclean:				clean
					rm -f $(NAME)

re:					fclean
					@make all --no-print-directory


test:				$(NAME)	
					./2048

aw:					
					$(CC) $(CFLAGS) aw.c -o test $(INC) $(LIBFT) -lncurses
					./test

-include $(DEPS)
.PHONY:				all clean fclean re bonus test -lncurses
