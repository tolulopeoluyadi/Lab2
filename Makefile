CC = gcc
CFLAGS = -Wall -g
TARGET = my3proc

all: $(TARGET)

$(TARGET): main3.c
	$(CC) $(CFLAGS) -o $(TARGET) main3.c

clean:
	rm -f $(TARGET)
