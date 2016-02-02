CC=gcc
CFLAGS= -Wall -Werror
DEPS = list.h

#test_list: test_list.c list.c
#	gcc -o test_list test_list.c list.c

all: test_list test

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_list: test_list.o list.o
	$(CC) -o test_list test_list.o list.o -Wall -Werror

test: test_list
	./test_list

clean:
	rm -f core *.o test_list
	
	

