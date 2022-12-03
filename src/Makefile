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

test:
	gcc $(CFLAGS) -o check_ss.out check_ss.c sscanf.c -lcheck -lm -lpthread -lsubunit
	make clean
	./check_ss.out

check:
	#cp ../materials/linters/CPPLINT.cfg ./
	#python3 ../materials/linters/cpplint.py --extensions=c *.c
	#python3 ../materials/linters/cpplint.py --extensions=h *.h
	#cppcheck --enable=all --suppress=missingIncludeSystem *.c
	#gcc $(CFLAGS) -o check_ss.out check_ss.c
	gcc $(CFLAGS) -o s21_scanf.out s21_scanf.c sscanf.c -lcheck -lm -lpthread -lsubunit
	make clean
	./s21_scanf.out

git:
	make clean
	git add *.c
	git add *.h
	#git add *.sh
	git add Makefile
	git commit -m "read_int_without_width"
	git push origin developShelacor
