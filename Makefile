CC = g++
CFLAG = -Wall -g
SRC = main.cpp passworditem.cpp passwordlist.cpp mgr.cpp message.cpp tools.cpp db.cpp user.cpp
OBJ = main.o passworditem.o passwordlist.o mgr.o message.o tools.o db.o user.o
TARGET = a

$(TARGET):$(OBJ) sqlite3.o
	$(CC)  -o $@ ${OBJ} sqlite3.o $(CFLAG)
	rm $(OBJ)

sqlite3.o:sqlite3.c
	gcc -c -o $@ $< $(CFLAG)

%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAG)

clean:
	rm *.o ${TARGET} 