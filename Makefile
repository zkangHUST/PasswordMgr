CC = g++
CFLAG = -Wall
SRC = main.cpp passworditem.cpp passwordlist.cpp mgr.cpp message.cpp tools.cpp db.cpp
OBJ = main.o passworditem.o passwordlist.o mgr.o message.o tools.o db.o
DEPS = sqlite3.h
OBJS = $(OBJ) sqlite3.o
TARGET = a
%.o: %.c 
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET):$(OBJ) sqlite3.o
	$(CC) -g  -o $@ ${OBJ} sqlite3.o $(CFLAG)
clean:
	rm ${OBJ} ${TARGET}