CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -Iinclude
# Uncomment to force C++98
# CXXFLAGS += -std=c++98

SRCS     := megaphone.cpp
NAME     := megaphone

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@echo "Nothing to clean (no object files)."

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
