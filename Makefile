CC=gcc
CFLAGS=-Wall
$(VERBOSE).SILENT:

ex1: exercice1.c
	rm -rf ex1
	$(CC) $(CFLAGS) $^ -o $@
	printf "\n"
	./ex1
ex2: exercice2.c
	rm -rf ex2
	$(CC) $(CFLAGS) $^ -o $@
	printf "\n";
	./ex2

ex3: exercice3.c
	rm -rf ex3
	$(CC) $(CFLAGS) $^ -o $@ -lm
	printf "\n";
	./ex3

clean:
	rm -rf ex1
	rm -rf ex2
	rm -rf ex3
