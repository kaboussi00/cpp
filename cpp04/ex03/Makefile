NAME = main
SRCS = main.cpp \
				AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				MateriaSource.cpp

INC = AMateria.hpp \
				Character.hpp \
				ICharacter.hpp \
				Cure.hpp \
				Ice.hpp \
				MateriaSource.hpp \
				IMateriaSource.hpp \


OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) $(CPPFLAGS) -o $(NAME)

%.o:%.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all 
