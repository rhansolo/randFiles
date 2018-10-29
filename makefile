all: files.o
	gcc files.o
random.o: files.c
	gcc -c files.c
run:
	./a.out