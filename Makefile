CC=`which gcc`
CFLAGS=--std=c11

all: yoloswag

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

yoloswag: yoloswag.o yolomalloc.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
	rm -f yoloswag
