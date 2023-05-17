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
}
END_TEST

START_TEST(compare_2) {  // - bc size
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));
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
}
END_TEST

START_TEST(sum_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &b);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2;
      b.matrix[i][j] = 3;
      true_result.matrix[i][j] = 6;
    }
    ck_assert_int_eq(0, s21_sum_matrix(&a, &b, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
}
END_TEST

START_TEST(sum_2) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &b);
  ck_assert_int_eq(2, s21_sum_matrix(&a, &b, &result));
}
END_TEST

START_TEST(sum_3) {
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
}
END_TEST

Suite *test_suite(void) {
  Suite *s;

  TCase *tc_create;
  TCase *tc_compare;

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
  suite_add_tcase(s, tc_sum);

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
