OBJS = engine/sprite.cpp engine/scene.cpp engine/game.cpp behaviors/eight_directions.cpp main.cpp

CC = g++

COMPILER_FLAGS = -w -std=c++2a

LINKER_FLAGS = -lSDL2 -lSDL2_image -lfmt

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
