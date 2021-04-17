CC = gcc
TARGET = main
DTARGET = main_debug
OBJECTS = main.c manager.o product.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) -DDEBUG -o $@ $^
clean :
	rm *.o
	rm main main_debug
