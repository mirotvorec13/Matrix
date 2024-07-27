CC= gcc
SAN=-g -fsanitize=undefined
CFLAGS= -Wall -Wextra -Werror -std=c11
MAIN_FILES= s21_matrix/*.c
TEST_FILES= unit_test/
CHEK_LINK= $(shell pkg-config --libs --cflags check)
GCOVFLAGS= -fprofile-arcs -ftest-coverage
PROJECT_NAME= s21_matrix
GLFLAGS= --coverage
LIBS= -lcheck -lsubunit -lm -lgcov

all: s21_matrix.a

object:
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(MAIN_FILES)

lib:
	ar rcs s21_matrix.a *.o

s21_matrix.a:
	$(CC) $(CFLAGS) -c $(MAIN_FILES)
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	checkmk $(TEST_FILES)$(PROJECT_NAME).check > $(PROJECT_NAME)_test.c
	$(CC) $(CFLAGS) $(PROJECT_NAME)_test.c $(MAIN_FILES) -L. $(PROJECT_NAME).a -o s21_matrix_test $(CHEK_LINK) $(GLFLAGS) $(SAN)
	./s21_matrix_test

gcov_report: object $(PROJECT_NAME).a test
	gcov *.gcno *.gcda
	~/.local/bin/gcovr -r . --html-details -e s21_matrix/s21_print_matr.c -o s21_matrix.html
	open s21_matrix.html

clean:
	rm -f *.o
	rm -f *.a
	rm -f $(PROJECT_NAME)_test.c
	rm -f test_$(PROJECT_NAME).log
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -f ./s21_matrix_test

valgrind:
	valgrind --tool=memcheck --leak-check=yes --log-file=test_s21_matrix.log ./s21_matrix_test
