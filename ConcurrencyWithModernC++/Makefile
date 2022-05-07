CC	= g++
OBJECTS	= curr.o 
TARGET	= curr
LIBS	= -pthread 		

.SUFFIXES : .cpp .o

.cpp.o :
	$(CC) -std=c++17 -Wall -c $<

$(TARGET)	: $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)
		     
clean :
	rm -rf $(TARGET) $(OBJECTS) core*
