CC = g++
CFLAG = -Wall -g
SRC = main.cpp passworditem.cpp passwordlist.cpp mgr.cpp message.cpp tools.cpp db.cpp
OBJ = main.o passworditem.o passwordlist.o mgr.o message.o tools.o db.o
DEPS = sqlite3.h
TARGET = a
%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET):$(OBJ) sqlite3.o
	# gcc -g -c  sqlite3.c -o sqlite3.o -Wall
	$(CC)  -o $@ ${OBJ} sqlite3.o $(CFLAG)
clean:
	rm ${OBJ} ${TARGET}