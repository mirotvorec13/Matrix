#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  double determinant = 0.0;
  matrix_t temp, res;
  if (A->matrix == NULL) {
    err = ERROR;
  } else {
    s21_determinant(A, &determinant);
    if (fabs(determinant) < EPS) {
      err = ERROR;
    } else {
      s21_calc_complements(A, &res);
      s21_transpose(&res, &temp);
      s21_remove_matrix(&res);
      s21_mult_number(&temp, (1 / determinant), result);
      s21_remove_matrix(&temp);
    }
  }
  return err;
}
