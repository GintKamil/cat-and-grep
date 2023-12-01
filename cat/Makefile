CC=gcc
CFLAGS=-I -Wall -Werror -Wextra

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

s21_cat: s21_cat.o parser.o conclusion.o
	$(CC) -o s21_cat s21_cat.o parser.o conclusion.o
	rm *.o

clean:
	rm *.o