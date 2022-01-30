CFLAGS=-g -fsanitize=address -fsanitize=leak -fsanitize=undefined

all: add_two_num_in_C

add_two_num_in_C: ./add_two_num.c
	gcc $(CFLAGS) add_two_num.c -o add_two_num_in_C

clean:
	rm -f add_two_num_in_C
