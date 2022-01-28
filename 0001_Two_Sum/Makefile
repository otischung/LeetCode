CFLAGS=-g

all: Two_Sum_in_C test

Two_Sum_in_C: ./Two_Sum.c
	gcc $(CFLAGS) Two_Sum.c -o Two_Sum_in_C

test: ./test.c
	gcc $(CFLAGS) test.c -o test

clean:
	rm -f Two_Sum_in_C test input.txt output.txt
