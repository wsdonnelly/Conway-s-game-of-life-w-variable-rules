NAME = gol
CC = g++
FLAGS = --std=c++11 -Wall -v
SRCS = main.cpp CellMap.cpp Controls.cpp 
OBJS = $(SRCS:.cpp=.o)
INCLUDES = -I SDL_binaries/include/SDL2/
DYLIB = -L SDL_binaries/osx/ -lSDL2

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(DYLIB) -o $(NAME) 

%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all