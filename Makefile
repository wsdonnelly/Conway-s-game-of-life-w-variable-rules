NAME = g_o_l
CC = g++
#CFLAGS = --std=c++11 -Wall -fsanatize=address
CFLAGS = --std=c++11 -Wall
SRCS = main.cpp gol_functions.cpp controls.cpp events.cpp
OBJS = main.o gol_functions.o controls.o events.o
#INCLUDES = -I /Library/Frameworks/SDL2.framework/Headers
#FRAMEWORK = -F /Library/Frameworks -framework SDl2
INCLUDES = -I lib/include/SDL2/
LIB = -L lib/ -lSDL2

all: $(NAME)

$(NAME): $(OBJS)
#	$(CC) -o g_o_l $(OBJS) $(FRAMEWORK)
	$(CC) -o g_o_l $(OBJS) $(LIB) 

$(OBJS): $(SRCS) gol.hpp
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

clean:
	rm *.o
fclean: clean
	rm $(NAME)
re: fclean all