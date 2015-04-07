CC = clang
TARGET = nopesh
CFLAGS = -pipe -Wall

all: $(TARGET)

$(TARGET): clean
	$(CC) $(CFLAGS) -o $(TARGET) src/*.c

clean:
	rm -f *.o *.a *.out *.la *.lo *.so $(TARGET)
