NAME	:= serializer

CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    := main.cpp \
           A.cpp \
           B.cpp \
           C.cpp \
           Base.cpp

OBJS    := $(SRCS:.cpp=.o)

DEPS    := Base.hpp \
			A.hpp \
			B.hpp \
			C.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re