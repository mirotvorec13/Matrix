#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define ERROR 1
#define CALCULATION_ERROR 2
#define EPS 0.0000001
#define EPS_TEST 1e-6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

void s21_print_matr(matrix_t);
int s21_create_matrix(int, int, matrix_t *); // создание матриц
void s21_remove_matrix(matrix_t *); // Отчистка матриц
int s21_eq_matrix(matrix_t *, matrix_t *); // Сравнение матриц
int s21_sum_matrix(matrix_t *, matrix_t *, matrix_t *); // сложение матриц
int s21_sub_matrix(matrix_t *, matrix_t *, matrix_t *); // вычитание матриц
int s21_mult_number(matrix_t *, double, matrix_t *); // умножение матрицы на число
int s21_mult_matrix(matrix_t *, matrix_t *, matrix_t *); // умножение двух матриц
int s21_transpose(matrix_t *, matrix_t *); // транспонирование матрицы
int s21_calc_complements(matrix_t *, matrix_t *); // минор матрицы и матрица алгебраических дополнений
int s21_determinant(matrix_t *, double *); // определитель матрицы
void s21_determinant_three(matrix_t *, double *);
void s21_determinant_two(matrix_t *, double *);
int s21_gaus_determin(matrix_t *, double *);
void swap_rows(matrix_t *, int, double *);
int s21_inverse_matrix(matrix_t *, matrix_t *);
void s21_copy_matrix(matrix_t *, matrix_t *);
#endif
