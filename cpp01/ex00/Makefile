
NAME = main
SRCS = main.cpp\
	Zombie.cpp\
	newZombie.cpp\
	randomChump.cpp\

INC = Zombie.hpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) $(CPPFLAGS) -o $(NAME)

%.o: %.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all