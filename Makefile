CC=gcc
CFLAGS=-Wall
$(VERBOSE).SILENT:

ex1: exercice1.c
	$(CC) $(CFLAGS) $^ -o $@

ex2: exercice2.c
	$(CC) $(CFLAGS) $^ -o $@


ex3: exercice3.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

ex6: exercice6.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf ex1
	rm -rf ex2
	rm -rf ex3
	rm -rf ex6
