Name = main
SRCS = main.cpp

INC = methodes.hpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJS)
	$(CPP) $(OBJS) $(CPPFLAGS) -o $(Name)

%.o:%.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(Name)

re: fclean all