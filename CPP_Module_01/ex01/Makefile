CPPC = c++
CPPFLAGS =  -Wall -Wextra -Werror -std=c++98
NAME = bank_system

SRCS = main.cpp \
		Zombie.cpp \
		ZombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CPPC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJS)