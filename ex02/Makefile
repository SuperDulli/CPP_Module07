CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic-errors

NAME	= array
# CLASSES	= Array.cpp
TMPLATES= Array.hpp
HEADERS	= $(patsubst %.cpp,%.hpp,$(CLASSES)) $(TMPLATES)
SRCS	= main.cpp $(CLASSES)
OBJDIR	= obj
OBJS	= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

TEST_INTRA= main_intra
INTRA_MAIN= main_intra.cpp

all: $(NAME) test_intra

clean:
	rm -rf $(OBJDIR)
	rm -rf $(NAME).dSYM
	rm -f $(INTRA_MAIN)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_INTRA)

re: fclean
	make all

show:
	@echo HEADERS=$(HEADERS)
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)
	@echo $(TEST_INTRA) $(INTRA_MAIN)

debug: fclean
debug: CXXFLAGS := $(CXXFLAGS) -g
debug: all

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test: $(NAME)
	./$(NAME)

test_intra: $(TEST_INTRA)
	./$(TEST_INTRA)

$(NAME): $(OBJS) $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp $(TMPLATES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

$(TEST_INTRA): $(INTRA_MAIN) $(TMPLATES)
	$(CXX) $(CXXFLAGS) $< -I. -o $@

$(INTRA_MAIN):
	curl https://projects.intra.42.fr/uploads/document/document/9237/main.cpp > $@

.PHONY: all clean fclean re show debug leaks test valgrind test_intra
