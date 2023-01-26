NAME = gol
CC = g++
FLAGS = --std=c++11 -Wall
SRCS = main.cpp cellmap.cpp controls.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = include/cellmap.hpp include/controls.hpp
INCLUDES = -I SDL_binaries/include/SDL2/ -I include/
DYLIB = -L SDL_binaries/osx/ -lSDL2
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(DYLIB) -o $(NAME) 

%.o: %.cpp $(HDRS)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean fclean run debug

run: $(NAME)
	./$(NAME)

debug: FLAGS += -g
debug: re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all