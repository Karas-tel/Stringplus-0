#CFLAGS=-Wall -Werror -Wextra
CFLAGS=
all: test

test: main.c func.c s21_sprintf.c
	gcc -o test $(CFLAGS) main.c func.c s21_sprintf.c -lcheck -lm -lpthread
	

	

clean:
	rm -rf *.o

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

