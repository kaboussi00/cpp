NAME = main
SRCS = main.cpp\
	HumanA.cpp\
	HumanB.cpp\
	Weapon.cpp\


INC = HumanA.hpp\
	HumanB.hpp\
	Weapon.hpp\


OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) $(CPPFLAGS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all