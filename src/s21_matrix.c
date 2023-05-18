#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;

  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);

  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = 1;
  if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 0;
  else
    for (int i = 0; i < A->rows && ret; i++)
      for (int j = 0; j < A->columns && ret; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > S21_EPS) ret = 0;
      }
  return ret;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(B) || is_incorrect(result)) ret = 1;
  else if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 2;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
  }
  return ret;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(B) || is_incorrect(result)) ret = 1;
  else if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 2;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
  return ret;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(result)) ret = 1;
  else for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  return ret;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(B) || is_incorrect(result)) ret = 1;
  else if (A->rows != B->columns)
    ret = 2;
  else for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < B->rows; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
  return ret;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A)) ret = 1;
  // else if (A->rows != result->columns || A->columns != result->rows) ret = 2;
  else for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
  return ret;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A)) ret = 1;
  // else if (A->rows != result->columns || A->columns != result->rows) ret = 2;
  else for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        get_minor_matrix(A, i, j, &minor);
        double minor_det = 0.0;
        s21_determinant(&minor, &minor_det);
        result->matrix[i][j] = pow(-1, i + j) * minor_det;
      }
  return ret;
}

int s21_determinant(matrix_t *A, double *result) {
  int ret = 0;
  double temp = 0.0;
  // *result = 0.0;
  if (is_incorrect(A)) ret = 1;
  else if (A->rows != A->columns) ret = 2;
  else {
    *result = det_processing(A, result);
  }
  return ret;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret = 0;
  double det = 0.0;
  s21_determinant(A, &det);
  if (is_incorrect(A) || is_incorrect(result) || A->columns != A->rows) ret = 1;
  else if (fabs(det) < S21_EPS) ret = 2;
  else {
    matrix_t temp;
    s21_create_matrix(A->rows, A->columns, &temp);
    // s21_transpose(A, &temp);
    s21_calc_complements(A, &temp);
    s21_transpose(&temp, &temp);
    s21_mult_number(&temp, 1 / det, result);
    s21_remove_matrix(&temp);
  }
  return ret;
}

// helpers

int is_incorrect(matrix_t *M) {
  return (M && M->columns > 0 && M->rows > 0) ? 0 : 1;
}

void print_matrix(matrix_t M) {
  for (int i = 0; i < M.rows; i++) {
    for (int j = 0; j < M.columns; j++) printf("%lf ", M.matrix[i][j]);
    printf("\n");
  }
}

void get_minor_matrix(matrix_t *M, int row, int col, matrix_t *result) {
  s21_create_matrix(M->rows - 1, M->columns - 1, result);
  for (int r = 0, i = 0; r < M->rows - 1; r++) {
    for (int c = 0, j = 0; c < M->columns - 1; c++) {
      if (r == row) i = 1;
      if (c == col) j = 1;
      result->matrix[r][c] = M->matrix[r + i][c + j];
    }
  }
}

double det_processing(matrix_t *A, double *result) {
    int sign = 1;
    double temp = 0.0;
    if (A->rows == 1) return A->matrix[0][0];
    if (A->rows == 2) return (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
    for (int j = 0; j < A->columns; j++) {
      matrix_t minored = {0};
      get_minor_matrix(A, 0, j, &minored);
      temp += det_processing(&minored, &temp) * sign;
      sign = -sign;
    }
    return temp;
}

// int main() {
//   matrix_t a = {0};
//   s21_create_matrix(3, 3, &a);
//   double result = 0.0;
//   int c = 1;
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       a.matrix[i][j] = c++;
//     }
//   }
//       printf("\n");
//   print_matrix(a);
//   s21_determinant(&a, &result);
//       printf("\n");
//   printf("%lf\n", result);
// }