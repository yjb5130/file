CFLAGS=-g3
#INCLUDES=../../include
TARGET=file

$(TARGET):ly_file.c main.c
	gcc -o $@ $^ $(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(TARGET) *.o
