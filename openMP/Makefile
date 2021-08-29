OBJECTS	= curr.o 
CC	= g++
TARGET	= curr
LIBS	= -fopenmp -pthread 		

.SUFFIXES : .c .o

.c.o :
	$(CC) -std=c++17 -Wall -c -fopenmp $<
#	$(CC) -std=c++17 -Wall -c $<

$(TARGET)	: $(OBJECTS)
#	$(CC) -o $(TARGET) $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)
	
clean :
	rm -rf $(TARGET) $(OBJECTS) core*
