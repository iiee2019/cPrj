CC = gcc
CFLAGS = -g -Wall
LIBS = -lm  -lpthread -ldl 
OBJS = main.o \
	sha256.o \
	md5.o \
	crc_crc32.o 
TARGET = calculate

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS) 

.PHONY: clean
clean:
	rm -rf *.o *.swp 

