all: s21_string

CC = gcc -Wall -Werror -Wextra

s21_grep: s21_string
	$(CC) -o s21_string s21_string.c


clean:
	rm -rf *.o s21_string

rebuild: clean all
