PATH_SFML = src/libraries/SFML-2.5.1/bin
CFLAGS =  -c -Wall -Werror
LIBS = -L $(PATH_SFML) -Wl,-rpath=src/libraries/SFML-2.5.1/bin -lsfml-graphics-2 \
 -lsfml-window-2 -lsfml-audio-2 -lsfml-system-2
CPPFLAGS = -MMD -I src/libraries/SFML-2.5.1/include -I src/tag -I src

BIN = bin
OBJ = obj
SRC = src
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CC = g++

APP_NAME = tag
LIB_NAME = libraries

PATH_TO_APP = $(BIN)/$(APP_NAME)
PATH_TO_LIB = $(OBJ)/$(SRC)/$(LIB_NAME)/$(LIB_NAME).a

APP_SRCS = $(shell find $(SRC)/$(APP_NAME) -name "*.cpp")
APP_OBJS = $(APP_SRCS:$(SRC)/%.cpp=$(OBJ)/$(SRC)/%.o)

LIB_SRCS = $(shell find $(SRC)/$(LIB_NAME) -name "*.cpp")
LIB_OBJS = $(LIB_SRCS:$(SRC)/%.cpp=$(OBJ)/$(SRC)/%.o)

DEP =  $(APP_OBJS:.o=.d) $(LIB_OBJS:.o=.d)

.PHONY: all

all: $(PATH_TO_APP) 

$(PATH_TO_APP): $(APP_OBJS) $(PATH_TO_LIB)
	$(CC) $(CFLAGS) $(DEBUG)  -o $@ $^ $(LIBS)

$(PATH_TO_LIB): $(LIB_OBJS)
	ar rcs $@ $^

$(OBJ)/$(SRC)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $< $(LIBS)

.PHONY: all clean	
clean: 
	rm -f $(PATH_TO_APP) $(PATH_TO_LIB) 
	rm -rf $(DEP) $(APP_OBJS) $(LIB_OBJS) 
