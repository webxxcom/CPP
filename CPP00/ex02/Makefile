#include "ex01/include/InputValidator.h"
# Compiler and flags
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror 
CXXFLAGS += -std=c++98

# Directories
OBJ_DIR  := obj

# Files
SRCS     := Account.cpp tests.cpp
OBJS     := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))
NAME     := prog

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
