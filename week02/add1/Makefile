all: add1

add1_c.o: add1_c.c
	gcc -g -c -o add1_c.o add1_c.c

add1_s.o: add1_s.s
	as -g -o add1_s.o add1_s.s

add1.o: add1.c
	gcc -g -c -o add1.o add1.c

add1: add1_c.o add1_s.o add1.o
	gcc -g -o add1 $^


clean:
	rm -rf *.o add1
