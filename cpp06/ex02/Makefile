Name = main
SRCS = Base.cpp\
	A.cpp\
	B.cpp\
	C.cpp\
	main.cpp

INC = Base.hpp\
	A.hpp\
	B.hpp\
	C.hpp

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