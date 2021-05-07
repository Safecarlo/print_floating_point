CC=verificarlo-c
CFLAGS=-Wall -Wextra
OFLAGS=

TARGET=print_floating_point

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@

clean:
	rm -Rf *~ *.o .vfc* $(TARGET)


