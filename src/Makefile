CFLAGS = -Wall -Wextra -Werror -g

all:
	#hello there

s21_sscanf:
	gcc $(CFLAGS) -o s21_sscanf.out sscanf.c
	make clean
	./s21_sscanf.out

main:
	gcc $(CFLAGS) -o main.out main.c
	make clean
	./main.out

sscanf: 
	gcc -o s21_sscanf.out sscanf.c
	make clean
	./s21_sscanf.out

clean:
	rm -f *.o

check:
	#cp ../materials/linters/CPPLINT.cfg ./
	#python3 ../materials/linters/cpplint.py --extensions=c *.c
	#python3 ../materials/linters/cpplint.py --extensions=h *.h
	#cppcheck --enable=all --suppress=missingIncludeSystem *.c

git:
	make clean
	git add *.c
	git add *.h
	#git add *.sh
	git add Makefile
	git commit -m "read_double"
	git push origin developShelacor
