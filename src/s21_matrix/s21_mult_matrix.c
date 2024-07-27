#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->matrix == NULL || B->matrix == NULL) {
    res = ERROR;
  } else if (A->columns != B->rows) {
    res = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        int count = A->columns, k = 0;
        while (count > 0) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          k++;
          count--;
        }
      }
    }
  }
  return res;
}
