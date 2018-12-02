CC = gcc
CFLAGS = -c -Wall -Wextra -Wpedantic

all: dciDecoder

dciDecoder: dci0decoder.o dci0decoderMain.o
	$(CC) dci0decoder.o dci0decoderMain.o -o dciDecoder -lcriterion -lm 

dci0decoderMain.o: dci0decoderMain.c 
	$(CC) $(CFLAGS) dci0decoderMain.c -lcriterion -lm

dci0decoder.o: dci0decoder.c 
	$(CC) $(CFLAGS) dci0decoder.c

clean:
	rm -f *.out *o dciDecoder
move:
	mv dciDecoder ~/eclipse-workspace/dci0bitfield
