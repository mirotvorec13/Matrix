#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (A->matrix == NULL) {
    err = ERROR;
  } else if (A->rows != A->columns) {
    err = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    s21_determinant_two(A, result);
  } else if (A->rows == 3) {
    s21_determinant_three(A, result);
  } else {
    err = s21_gaus_determin(A, result);
  }
  return err;
}

int s21_gaus_determin(matrix_t *A, double *result) {
  int count = 0, err = OK;
  int A_length = A->rows * A->columns;
  double determinant = 1.0, koef = 0.0;
  matrix_t temp, res_sub, copy_A;
  s21_create_matrix(A->rows, A->columns, &copy_A);
  s21_copy_matrix(A, &copy_A);
  for (int index = 0; index < copy_A.rows; index++) {
    if (copy_A.matrix[index][index] == 0) {
      swap_rows(&copy_A, index, &determinant);
    } else {
      for (int i = index + 1; i < copy_A.rows; i++) {
        count = 0;
        double *ptr_copy_A = copy_A.matrix[0];

        if ((koef = copy_A.matrix[i][index]) != 0) {
          s21_create_matrix(copy_A.rows, copy_A.columns, &temp);
          koef /= copy_A.matrix[index][index];

          for (int j = index; j < copy_A.columns; j++) {
            temp.matrix[i][j] = copy_A.matrix[index][j] * koef;
          }

          s21_sub_matrix(&copy_A, &temp, &res_sub);
          s21_remove_matrix(&temp);
          double *ptr_sub = res_sub.matrix[0];

          while (count < A_length) {
            *ptr_copy_A++ = *ptr_sub++;
            count++;
          }

          s21_remove_matrix(&res_sub);
        }
      }
    }
  }

  *result = determinant;
  if (result != 0) {
    for (int i = 0; i < copy_A.rows; i++) {
      *result *= copy_A.matrix[i][i];
    }
  }
  s21_remove_matrix(&copy_A);
  return err;
}

void s21_copy_matrix(matrix_t *A, matrix_t *res) {
  int count = 0;
  int A_length = A->rows * A->columns;
  double *ptr_A = A->matrix[0];
  double *ptr_res = res->matrix[0];
  while (count < A_length) {
    *ptr_res++ = *ptr_A++;
    count++;
  }
}

void swap_rows(matrix_t *copy_A, int index, double *determinant) {
  int found = 0;
  for (int i = index + 1; i < copy_A->rows && !found; i++) {
    if (copy_A->matrix[i][index] != 0) {
      for (int j = 0; j < copy_A->columns; j++) {
        double temp = copy_A->matrix[index][j];
        copy_A->matrix[index][j] = copy_A->matrix[i][j];
        copy_A->matrix[i][j] = temp;
      }
      *determinant *= -1.0;
      found = 1;
    }
  }
  if (!found) {
    *determinant = 0.0;
  }
}

void s21_determinant_two(matrix_t *A, double *result) {
  *result =
      A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

void s21_determinant_three(matrix_t *A, double *result) {
  *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] -
            A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1] -
            A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2] +
            A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
            A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1] -
            A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0];
}
