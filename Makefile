CC = g++
CFLAG = -Wall
SRC = main.cpp passworditem.cpp passwordlist.cpp mgr.cpp message.cpp tools.cpp sqlite3.c
TARGET = a
$(TARGET):$(SRC)
	$(CC) -g  -o $@ ${SRC} $(CFLAG)
clean:
	rm ${TARGET}