all: logger.o
	gcc -g main.c logger.o -o main -w
logger.o:
	gcc -c logger/logger.c
