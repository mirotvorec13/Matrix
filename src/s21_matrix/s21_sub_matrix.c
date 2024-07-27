#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->matrix == NULL || B->matrix == NULL) {
    res = ERROR;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = (A->matrix[i][j] - B->matrix[i][j]);
      }
    }
  }
  return res;
}
