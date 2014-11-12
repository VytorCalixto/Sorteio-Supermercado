all: logger.o search.o sort.o
	gcc -g main.c logger.o search.o sort.o -o main -w
logger.o:
	gcc -c logger/logger.c
sort.o:
	gcc -c sort.c
search.o:
	gcc -c search.c
clean:
	rm -fr *.o
