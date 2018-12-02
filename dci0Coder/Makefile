CC = gcc
CFLAGS = -c -Wall -Wextra -Wpedantic

all: dciCoder

dciCoder: dci0.o dci0coder.o
	$(CC) dci0coder.o dci0.o -o dciCoder -lcriterion -lm | mv dciCoder ~/eclipse-workspace/dci0bitfield

dci0coder.o: dci0coder.c 
	$(CC) $(CFLAGS) dci0coder.c -lcriterion -lm

dci0.o: dci0.c 
	$(CC) $(CFLAGS) dci0.c

clean:
	rm -f *.out *o dciDecoder 
