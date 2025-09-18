CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook

SRCS = main.cpp \
		phonebook.cpp
		
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