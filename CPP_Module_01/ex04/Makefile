CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98
NAME = sed_is_for_losers

SRCS = main.cpp \
		utils.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJS)