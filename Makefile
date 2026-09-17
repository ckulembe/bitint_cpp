
NAME	= bigint
CXX	= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
HEARDERS = header/BigInt.hpp

SRCS_DIR = src/
SRCS = $(SRCS_DIR)main.cpp \
	$(SRCS_DIR)BigInt.cpp
	
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.o: .cpp $(HEARDERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re