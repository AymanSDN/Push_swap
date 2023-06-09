SRCS			=	push_swap.c \
					instractions_a.c \
					instractions_b.c \
					instractions_both.c \
					parsing.c \
					parsing_2.c \
					small_sort.c \
					large_sort.c \
					tools_1.c \
					tools_2.c \
					tools_3.c \
					tools_4.c 
# test.c

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap

all:			shifuuu $(NAME)
				@echo "\033[1m\033[32mCompilation has completed"

$(NAME) : $(OBJS) push_swap.h
	@${CC} ${CFLAGS} ${OBJS} -o $(NAME)

clean:
				$(RM) $(OBJS) 
				@echo "\033[1m\033[31mObject files removed"

fclean:			
				$(RM) $(OBJS)
				$(RM) $(NAME)
				@echo "\033[1m\033[31mThe executable file and object files have been successfully removed"

re:				fclean all

shifuuu:
			clear
			@echo "	\033[37m░██████╗██╗░░██╗██╗███████╗██╗░░░██╗██╗░░░██╗██╗░░░██╗"
			@echo "	\033[37m██╔════╝██║░░██║██║██╔════╝██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m╚█████╗░███████║██║█████╗░░██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m░╚═══██╗██╔══██║██║██╔══╝░░██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m██████╔╝██║░░██║██║██║░░░░░╚██████╔╝╚██████╔╝╚██████╔╝"
			@echo "	\033[37m╚═════╝░╚═╝░░╚═╝╚═╝╚═╝░░░░░░╚═════╝░░╚═════╝░░╚═════╝░"
			@echo "	\033[37m														 "
			@echo "	\033[37m███╗░░░███╗░█████╗░░██████╗████████╗███████╗██████╗░"
			@echo "	\033[37m████╗░████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗"
			@echo "	\033[37m██╔████╔██║███████║╚█████╗░░░░██║░░░█████╗░░██████╔╝"
			@echo "	\033[37m██║╚██╔╝██║██╔══██║░╚═══██╗░░░██║░░░██╔══╝░░██╔══██╗"
			@echo "	\033[37m██║░╚═╝░██║██║░░██║██████╔╝░░░██║░░░███████╗██║░░██║"
			@echo "	\033[37m╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝"
			@echo "															 "
