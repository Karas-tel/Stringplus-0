#CFLAGS=-Wall -Werror -Wextra
CFLAGS = -Wall -Werror -Wextra -std=c11

all: test

test: main.c s21_string.a
	gcc -o test $(CFLAGS) main.c s21_string.a -lcheck -lm -lpthread
	
s21_string.a: s21_sprintf.o s21_string.o
	ar r s21_string.a s21_string.o s21_sprintf.o

s21_sprintf.o: s21_sprintf.c
	gcc $(CFLAGS) -c s21_sprintf.c

s21_string.o: s21_string.c
	gcc $(CFLAGS) -c s21_string.c

clean:
	rm -rf *.o *.a

check:
	cp ../../materials/linters/.clang-format ../../src/.clang-format
	clang-format -i *.c
	clang-format -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	

	
	
git:
	git add *.c
	git add *.h
	git add Makefile
	git commit -m "add from make"
	git push

