OBJECTS	= curr.o 
CC	= g++
TARGET	= curr
LIBS	= -pthread 		

.SUFFIXES : .c .o

.c.o :
	$(CC) -std=c++17 -O2 -Wall -c $<

$(TARGET)	: $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)

	
clean :
	rm -rf $(TARGET) $(OBJECTS) core*
