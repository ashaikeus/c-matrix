FLAGS = -Wall -Werror -Wextra -std=c11
LIB_FLAGS = -lcheck -lgcov
CODE_FILES = s21_*.c
TEST_FILES = tests.c

all:
	gcc $(CODE_FILES) $(TEST_FILES) -lcheck
	./a.out

style:
	clang-format -n *.c *.h
	clang-format -i *.c *.h

checks: style
	gcc $(FLAGS) $(CODE_FILES) $(TEST_FILES)
	cppcheck *.c *.h

clean:
	rm -rf report *.a *.o *.gcda *.gcno *.gcov *.info test ./a.out

test: clean s21_matrix.a
	gcc $(TEST_FILES) -o test s21_matrix.a -lcheck
	./test
	rm ./test

main:
	gcc $(CODE_FILES)
	./a.out
	rm ./a.out

s21_matrix.a:
	gcc -c $(CODE_FILES)
	ar rcs s21_matrix.a s21_*.o
	ranlib s21_matrix.a

gcov_report: s21_matrix.a
	gcc --coverage $(CODE_FILES) $(TEST_FILES) $(LIB_FLAGS) -o test
	./test
	lcov -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
