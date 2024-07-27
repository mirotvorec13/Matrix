#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;

  if (rows < 1 || columns < 1) {
    err = ERROR;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    result->matrix[0] = (double *)calloc(rows * columns, sizeof(double));
    for (int i = 1; i < rows; i++) {
      result->matrix[i] = result->matrix[0] + i * columns;
    }
    result->rows = rows;
    result->columns = columns;
  }
  return err;
}
