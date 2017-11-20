all:
	gcc -o piping pipe.c

run: all
	./piping

clean:
	rm piping
	rm *~
