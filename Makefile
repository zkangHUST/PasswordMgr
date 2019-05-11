CC = g++
CFLAG = -Wall
SRC = main.cpp passworditem.cpp passwordlist.cpp mgr.cpp message.cpp tools.cpp
TARGET = a
$(TARGET):$(SRC)
	$(CC) -g  -o $@ ${SRC} $(CFLAG)
clean:
	rm ${TARGET}