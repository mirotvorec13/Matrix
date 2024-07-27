#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->matrix == NULL || B->matrix == NULL) {
    res = ERROR;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = FAILURE;
  } else {
    for (int i = 0; i < A->rows && res; i++) {
      for (int j = 0; j < B->columns && res; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          res = FAILURE;
        }
      }
    }
  }
  return res;
}
