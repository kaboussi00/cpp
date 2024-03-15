NAME = Span
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC = Span.hpp
SRCS = Span.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf

all : $(NAME)
$(NAME):$(OBJS) $(INC)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:clean
	@$(RM) $(NAME)

re:fclean all