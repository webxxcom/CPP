#include "ex01/include/InputValidator.h"
# Compiler and flags
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -Iinclude
CXXFLAGS += -std=c++98

# Directories
SRC_DIR  := src
OBJ_DIR  := obj
INC_DIR  := include

# Files
SRCS     := $(SRC_DIR)/main.cpp $(SRC_DIR)/ClapTrap.cpp $(SRC_DIR)/ScavTrap.cpp
OBJS     := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
NAME     := scavTrap

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
