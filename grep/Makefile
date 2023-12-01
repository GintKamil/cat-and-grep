CC=gcc
CFLAGS=-Wall -Werror -Wextra

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

s21_grep: s21_grep.o parser.o conclusion.o
	$(CC) -o s21_grep s21_grep.o parser.o conclusion.o
	rm *.o

test: clean s21_grep
	sh test_grep.sh

clean:
	rm -rf *.o
