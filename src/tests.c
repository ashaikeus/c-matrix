#include <check.h>

#include "s21_matrix.h"

START_TEST(create) {
  matrix_t m = {0};
  for (int k = 0; k < 50; k++) {
    int rows = k, cols = k;
    ck_assert_int_eq(0, s21_create_matrix(rows, cols, &m));
    ck_assert_int_eq(m.rows, rows);
    ck_assert_int_eq(m.columns, cols);
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) {
        ck_assert_ldouble_eq_tol(0, m.matrix[i][j], S21_EPS);
      }
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(compare_1) {  // +
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  ck_assert_int_eq(1, s21_eq_matrix(&a, &b));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
}
END_TEST

START_TEST(compare_2) {  // - bc size
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
}
END_TEST

START_TEST(compare_3) {  // - bc values
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2;
      b.matrix[i][j] = 3;
    }
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      b.matrix[i][j] = 3.3431413598;
      true_result.matrix[i][j] = 2.13243422 + 3.3431413598;
    }
  ck_assert_int_eq(0, s21_sum_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(sum_2) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(2, s21_sum_matrix(&a, &b, &result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_3) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = j * 2 + i;
      true_result.matrix[i][j] = i + j + j * 2 + i;
    }
  ck_assert_int_eq(0, s21_sum_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(sum_4) {
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(1, s21_sum_matrix(NULL, NULL, &result));
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      b.matrix[i][j] = 3.3431413598;
      true_result.matrix[i][j] = 2.13243422 - 3.3431413598;
    }
  ck_assert_int_eq(0, s21_sub_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(sub_2) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(2, s21_sub_matrix(&a, &b, &result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_3) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = j * 2 + i;
      true_result.matrix[i][j] = i + j - j * 2 - i;
    }
  ck_assert_int_eq(0, s21_sub_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(sub_4) {
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(1, s21_sub_matrix(NULL, NULL, &result));
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      true_result.matrix[i][j] = 2.13243422 * 3.3431413598;
    }
  ck_assert_int_eq(0, s21_mult_number(&a, 3.3431413598, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(mul_num_2) {
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(1, s21_mult_number(NULL, 2342, &result));
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_3) {
  matrix_t a = {0};
  s21_create_matrix(9, 7, &a);
  matrix_t result = {0};
  s21_create_matrix(9, 7, &result);
  matrix_t true_result = {0};
  s21_create_matrix(9, 7, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i * 19.124981 * -1;
      true_result.matrix[i][j] = a.matrix[i][j] * 3.3431413598;
    }
  ck_assert_int_eq(0, s21_mult_number(&a, 3.3431413598, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(mul_mat_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(3, 2, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243;
      b.matrix[j][i] = 3.34314;
      true_result.matrix[i][j] = 21.3870360906;
    }
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(mul_mat_2) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(2, s21_mult_matrix(&a, &b, &result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_mat_3) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(3, 2, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[j][i] = j * 2 + i;
    }
  true_result.matrix[0][0] = 10;
  true_result.matrix[0][1] = 13;
  true_result.matrix[1][0] = 16;
  true_result.matrix[1][1] = 22;
  ck_assert_int_eq(0, s21_mult_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(mul_mat_4) {
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  ck_assert_int_eq(1, s21_mult_matrix(NULL, NULL, &result));
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(3, 2, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      true_result.matrix[j][i] = i + j;
    }
  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(complements_1) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(3, 3, &true_result);
  int c = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = c++;
    }
  true_result.matrix[0][0] = -3;
  true_result.matrix[0][1] = -6;
  true_result.matrix[0][2] = -3;
  true_result.matrix[1][0] = -6;
  true_result.matrix[1][1] = -12;
  true_result.matrix[1][2] = -6;
  true_result.matrix[2][0] = -3;
  true_result.matrix[2][1] = -6;
  true_result.matrix[2][2] = -3;
  ck_assert_int_eq(0, s21_calc_complements(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

START_TEST(det_1) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = c++;
    }
  }
  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_2) {
  matrix_t a = {0};
  s21_create_matrix(4, 4, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a.matrix[i][j] = i;
    }
  }
  a.matrix[0][0] = 3;
  a.matrix[2][2] = 14;
  a.matrix[3][3] = 2;
  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, -36, S21_EPS);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_3) {
  matrix_t a = {0};
  s21_create_matrix(7, 7, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      a.matrix[i][j] = c++;
    }
  }
  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_4) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = c++;
    }
  }
  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, -2, S21_EPS);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(inv_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 2, &result);
  ck_assert_int_eq(1, s21_inverse_matrix(&a, &result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(inv_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 3, &result);
  int c = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = c++;
    }
  ck_assert_int_eq(2, s21_inverse_matrix(&a, &result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(inv_3) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  int c = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = c++;
    }
  true_result.matrix[0][0] = -2;
  true_result.matrix[0][1] = 1;
  true_result.matrix[1][0] = 1.5;
  true_result.matrix[1][1] = -0.5;
  ck_assert_int_eq(0, s21_inverse_matrix(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
    s21_remove_matrix(&true_result);
}
END_TEST

Suite *test_suite(void) {
  Suite *s;

  TCase *tc_create;
  TCase *tc_compare;
  TCase *tc_sum;
  TCase *tc_sub;
  TCase *tc_mul_num;
  TCase *tc_mul_mat;
  TCase *tc_transpose;
  TCase *tc_complements;
  TCase *tc_det;
  TCase *tc_inv;

  s = suite_create("Matrix tests");

  tc_create = tcase_create("creating matrices\n");
  tcase_add_test(tc_create, create);
  suite_add_tcase(s, tc_create);

  tc_compare = tcase_create("is equal\n");
  tcase_add_test(tc_compare, compare_1);
  tcase_add_test(tc_compare, compare_2);
  tcase_add_test(tc_compare, compare_3);
  suite_add_tcase(s, tc_compare);
  
  tc_sum = tcase_create("sum\n");
  tcase_add_test(tc_sum, sum_1);
  tcase_add_test(tc_sum, sum_2);
  tcase_add_test(tc_sum, sum_3);
  tcase_add_test(tc_sum, sum_4);
  suite_add_tcase(s, tc_sum);

  tc_sub = tcase_create("sub\n");
  tcase_add_test(tc_sub, sub_1);
  tcase_add_test(tc_sub, sub_2);
  tcase_add_test(tc_sub, sub_3);
  tcase_add_test(tc_sub, sub_4);
  suite_add_tcase(s, tc_sub);

  tc_mul_num = tcase_create("mult by num\n");
  tcase_add_test(tc_mul_num, mul_num_1);
  tcase_add_test(tc_mul_num, mul_num_2);
  tcase_add_test(tc_mul_num, mul_num_3);
  suite_add_tcase(s, tc_mul_num);

  tc_mul_mat = tcase_create("mult by matrix\n");
  tcase_add_test(tc_mul_mat, mul_mat_1);
  tcase_add_test(tc_mul_mat, mul_mat_2);
  tcase_add_test(tc_mul_mat, mul_mat_3);
  tcase_add_test(tc_mul_mat, mul_mat_4);
  suite_add_tcase(s, tc_mul_mat);

  tc_transpose = tcase_create("transpose\n");
  tcase_add_test(tc_transpose, transpose_1);
  suite_add_tcase(s, tc_transpose);

  tc_complements = tcase_create("complements\n");
  tcase_add_test(tc_complements, complements_1);
  suite_add_tcase(s, tc_complements);

  tc_det = tcase_create("determinant\n");
  tcase_add_test(tc_det, det_1);
  tcase_add_test(tc_det, det_2);
  tcase_add_test(tc_det, det_3);
  tcase_add_test(tc_det, det_4);
  suite_add_tcase(s, tc_det);

  tc_inv = tcase_create("inverse matrix\n");
  tcase_add_test(tc_inv, inv_1);
  tcase_add_test(tc_inv, inv_2);
  tcase_add_test(tc_inv, inv_3);
  suite_add_tcase(s, tc_inv);

  return s;
}

int main() {
  int success = 0;
  Suite *s;
  SRunner *runner;
  s = test_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  //   return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
