#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK, k = 0, z = 0, count = 0;
  if (A->matrix == NULL) {
    err = ERROR;
  } else if (A->rows != A->columns) {
    err = CALCULATION_ERROR;
  } else if (A->rows < 2) {
    err = CALCULATION_ERROR;
  } else {
    matrix_t M, temp;
    int A_length = A->rows * A->columns;
    s21_create_matrix(A->rows, A->columns, &temp);
    s21_create_matrix(A->rows, A->columns, result);
    double *ptr_temp = temp.matrix[0];
    double *ptr_res = result->matrix[0];

    while (count < A_length) {
      s21_create_matrix(A->rows - 1, A->columns - 1, &M);
      double *ptr_M = M.matrix[0];
      double res = 0.0;
      int i = 0, j = 0, count_1 = 0;
      while (count_1 < A_length) {
        if (i != k && j != z) {
          *ptr_M++ = A->matrix[i][j];
        }
        if (j < A->columns - 1) {
          j++;
        } else {
          j = 0;
          i++;
        }
        count_1++;
      }
      s21_determinant(&M, &res);
      s21_remove_matrix(&M);
      *ptr_temp++ = res;
      if (z < temp.columns - 1) {
        z++;
      } else {
        z = 0;
        k++;
      }
      count++;
    }
    ptr_temp = temp.matrix[0];
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        *ptr_res++ = *ptr_temp++ * pow(-1.0, (i + j));
      }
    }
    s21_remove_matrix(&temp);
  }
  return err;
}
