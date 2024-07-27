#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix[0] != NULL) free(A->matrix[0]);
  if (A->matrix != NULL) free(A->matrix);
}
