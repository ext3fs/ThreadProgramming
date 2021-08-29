OBJECTS	= curr.o 
CC	= nvcc
TARGET	= curr
LIBS	= -pthread 		

.SUFFIXES : .cu .o

.c.o :
	$(CC) -Wall -c $<

$(TARGET)	: $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)

	
clean :
	rm -rf $(TARGET) $(OBJECTS) core*
