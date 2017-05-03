CC = gcc

all: target read_elf

target: hello_world

hello_world: hello_world.o
	$(CC) -o $@  $^

hello_world.o: hello_world.c

read_elf: read_elf.o
	$(CC) -o $@ $^

read_elf.o: read_elf.c

clean:
	-rm -rf *.o hello_world read_elf


