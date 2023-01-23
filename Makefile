NAME = gol
CC = g++
#CFLAGS = --std=c++11 -Wall -fsanatize=address
CFLAGS = --std=c++11 -Wall
SRCS = main.cpp CellMap.cpp Controls.cpp 
OBJS = main.o CellMap.o Controls.o 
#INCLUDES = -I /Library/Frameworks/SDL2.framework/Headers
#FRAMEWORK = -F /Library/Frameworks -framework SDl2
INCLUDES = -I SDL_binaries/include/SDL2/
LIB_OSX = -L SDL_binaries/osx/ -lSDL2

all: $(NAME)

$(NAME): $(OBJS)
#	$(CC) -o gol $(OBJS) $(FRAMEWORK)
	$(CC) -o $(NAME) $(OBJS) $(LIB_OSX) 

$(OBJS): $(SRCS) CellMap.hpp Controls.hpp
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all