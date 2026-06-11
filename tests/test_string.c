/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Tests unitaires Criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <string.h>
#include "bistromatic.h"

Test(addition, simple)
{
    char a[] = "3";
    char b[] = "5";

    char *res = calc_addition(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "8", "3 + 5 must equal 8");
    free(res);
}

Test(addition, with_carry)
{
    char a[] = "9";
    char b[] = "1";

    char *res = calc_addition(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "10", "9 + 1 must equal 10");
    free(res);
}

Test(addition, bigger_numbers)
{
    char a[] = "123";
    char b[] = "456";

    char *res = calc_addition(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "579", "123 + 456 must equal 579");
    free(res);
}

Test(addition, different_length)
{
    char a[] = "9";
    char b[] = "100";

    char *res = calc_addition(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "109", "9 + 100 must equal 109");
    free(res);
}

Test(substraction, simple)
{
    char a[] = "8";
    char b[] = "3";

    char *res = calc_substraction(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "5", "8 - 3 must equal 5");
    free(res);
}

Test(substraction, zero_as_result)
{
    char a[] = "7";
    char b[] = "7";

    char *res = calc_substraction(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "0", "7 - 7 must equal 0");
    free(res);
}


Test(multiplication, simple)
{
    char a[] = "3";
    char b[] = "4";

    char *res = calc_multiplication(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "12", "3 * 4 must equal 12");
    free(res);
}

Test(multiplication, by_zero)
{
    char a[] = "42";
    char b[] = "0";

    char *res = calc_multiplication(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "0", "42 * 0 must equal 0");
    free(res);
}

Test(multiplication, by_one)
{
    char a[] = "7";
    char b[] = "1";

    char *res = calc_multiplication(a, b);

    cr_assert_not_null(res, "Result must not be NULL");
    cr_assert_str_eq(res, "7", "7 * 1 must equal 7");
    free(res);
}
