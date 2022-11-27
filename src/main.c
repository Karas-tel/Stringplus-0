//
//  main.c
//  21_test
//
//  Created by mcbk on 09.11.2022.
//

#include <stdio.h>
#include "s21_sprintf.h"
#include <check.h>
#include "test_data.h"
#include "s21_string.h"

START_TEST(s21_chars_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1,
                '\n', test2, '-', test3, test4, test5, test6, test7);
    sprintf(buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n',
            test2, '-', test3, test4, test5, test6, test7);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer,
                "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
                -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
                (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
    sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u",
            101, -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
            (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums2_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};

    s21_sprintf(s21_buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
                (long int)125123123123, (short int)160, (unsigned short)101,
                (unsigned long)210, (short int)0, (long int)0, (short int)-25,
                (long int)-51);
    sprintf(buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
            (long int)125123123123, (short int)160, (unsigned short)101,
            (unsigned long)210, (short int)0, (long int)0, (short int)-25,
            (long int)-51);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums3_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer, "%-+6.4f %-2.2lf %5.5f %f %f", 100.0, 0.01, 0.10,
                -12.0, 0.00001);
    sprintf(buffer, "%-+6.4f %-2.2f %5.5f %f %f", 100.0, 0.01, 0.10, -12.0,
            0.00001);
    ck_assert_str_eq(s21_buffer, buffer);

    char s21_buffer2[256] = {0};
    char buffer2[256] = {0};
    s21_sprintf(s21_buffer2, "%f %f %f %f %f %f", 0.0/0.0,  1.0/0.0, 0.0/1.0,
                         -0.0/0.0, -1.0/0.0, -0.0/1.0);
    sprintf(buffer2, "%f %f %f %f %f %f", 0.0/0.0,  1.0/0.0, 0.0/1.0,
                     -0.0/0.0, -1.0/0.0, -0.0/1.0);
    ck_assert_str_eq(s21_buffer2, buffer2);

    char s21_buffer3[256] = {0};
    char buffer3[256] = {0};
    s21_sprintf(s21_buffer3, "%lg %lG %#lg %le", 234243.234, 8427348.234, 123.0, 155.2);
    sprintf(buffer3, "%lg %lG %#lg %le", 234243.234, 8427348.234, 123.0, 155.2);
    ck_assert_str_eq(s21_buffer3, buffer3);
}
END_TEST

START_TEST(test_printf_d) {
    char buff[100];
    char buff2[100];

    int f = s21_sprintf(buff2, "blblbblblc%c%+4d", '$', 10000);
    int s = sprintf(buff, "blblbblblc%c%+4d", '$', 10000);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "blblbblblc%c%+04d", '$', 10);
    s = sprintf(buff, "blblbblblc%c%+04d", '$', 10);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "blblbblblc%c%+-010d", '$', 10);
    s = sprintf(buff, "blblbblblc%c%+-10d", '$', 10);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "blblbblblc%c%+010d%5d%+5d", '$', 10, 0, -1);
    s = sprintf(buff, "blblbblblc%c%+010d%5d%+5d", '$', 10, 0, -1);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "blblbblblc%c%+02.5d", '$', 10);
    s = sprintf(buff, "blblbblblc%c%+02.5d", '$', 10);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2,  "%0+.5d %0+6.5d %0+.5d %0+6.5d %-2d %-2.5d %-4.d", 10, 10, -10, -10, 1, 10, 0);
    s = sprintf(buff,  "%0+.5d %0+6.5d %0+.5d %0+6.5d %-2d %-2.5d %-4.d", 10, 10, -10, -10, 1, 10, 0);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "blblbblblc%c%+0*.*d", '$', 2, 5, 10);
    s = sprintf(buff, "blblbblblc%c%+0*.*d", '$', 2, 5, 10);
} END_TEST

START_TEST(test_printf_f) {
    char buff[100];
    char buff2[100];

    int f1 = s21_sprintf(buff2, "blblbblblc%c%+4f", '$', 10000.0);
    int s1 = sprintf(buff, "blblbblblc%c%+4f", '$', 10000.0);
    ck_assert_int_eq(f1, s1);
    ck_assert_str_eq(buff, buff2);
    int f2 = s21_sprintf(buff2, "%+4.f", 10000.0);
    int s2 = sprintf(buff, "%+4.f", 10000.0);
    ck_assert_int_eq(f2, s2);
    ck_assert_str_eq(buff, buff2);
    int f3 = s21_sprintf(buff2, "%+.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0, 5.54454545, 5.54454545, 5.54454545);
    int s3 = sprintf(buff, "%+.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0, 5.54454545, 5.54454545, 5.54454545);
    ck_assert_int_eq(f3, s3);
    ck_assert_str_eq(buff, buff2);
    int f5 = s21_sprintf(buff2, "%+010.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0, 5.54454545, 5.9999999999, 5.54454545);
    int s5 = sprintf(buff, "%+010.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0, 5.54454545, 5.9999999999, 5.54454545);
    ck_assert_int_eq(f5, s5);
    ck_assert_str_eq(buff, buff2);

} END_TEST

START_TEST(test_printf_e) {
    char buff[100];
    char buff2[100];

    int f1 = s21_sprintf(buff2, "%4.4e %-3.5e %07e %+-.e %+010e %+010e %+010e % 010e", 1000.0, -0.0000002, 0.0, 200e+100, -0.0/0.0, 1.0/0.0, -1.0/0.0, 1.0/0.0);
    int s1 = sprintf(buff, "%4.4e %-3.5e %07e %+-.e %+010e %+010e %+010e % 010e", 1000.0, -0.0000002, 0.0, 200e+100, -0.0/0.0, 1.0/0.0, -1.0/0.0, 1.0/0.0);
    ck_assert_int_eq(f1, s1);
    ck_assert_str_eq(buff, buff2);
    int f2 = s21_sprintf(buff2, "%4.4E %-3.5E %07E %+-.E %+010E %+010E %+010E % 010E", 1000.0, -0.0000002, 0.0, 200e+100, -0.0/0.0, 1.0/0.0, -1.0/0.0, 1.0/0.0);
    int s2 = sprintf(buff, "%4.4E %-3.5E %07E %+-.E %+010E %+010E %+010E % 010E", 1000.0, -0.0000002, 0.0, 200e+100, -0.0/0.0, 1.0/0.0, -1.0/0.0, 1.0/0.0);
    ck_assert_int_eq(f2, s2);
    ck_assert_str_eq(buff, buff2);
    int f3 = s21_sprintf(buff2, "%#.0lg %lG %#lg %lg", 234243.234, 8427348.234, 123.0, 155.2);
    int s3 = sprintf(buff, "%#.0lg %lG %#lg %lg", 234243.234, 8427348.234, 123.0, 155.2);
    ck_assert_int_eq(f3, s3);
    ck_assert_str_eq(buff, buff2);
} END_TEST

START_TEST(test_printf_o) {
    char buff[100];
    char buff2[100];

    int f1 = s21_sprintf(buff2, "%o %5o %-20lo %10.20lo %#10.20lo %-#20.10lo", 21341324, 0, (long)1234341, (long) 123423141, (long)1234123, (long)1234341);
    int s1 = sprintf(buff, "%o %5o %-20lo %10.20lo %#10.20lo %-#20.10lo", 21341324, 0, (long)1234341, (long) 123423141, (long)1234123, (long)1234341);
    ck_assert_int_eq(f1, s1);
    ck_assert_str_eq(buff, buff2);
} END_TEST

START_TEST(test_printf_x) {
    char buff[200];
    char buff2[200];

    int f1 = s21_sprintf(buff2, "%x %5x %-20lx %10.20lx %#10.20lx %-#20.10lx %#10.20lX %-#20.10lX", 21341324, 0, (long)1234341, (long) 123423141, (long)1234123, (long)1234341, (long)1234123, (long)1234341);
    int s1 = sprintf(buff, "%x %5x %-20lx %10.20lx %#10.20lx %-#20.10lx %#10.20lX %-#20.10lX", 21341324, 0, (long)1234341, (long) 123423141, (long)1234123, (long)1234341, (long)1234123, (long)1234341);
    ck_assert_int_eq(f1, s1);
    ck_assert_str_eq(buff, buff2);
} END_TEST

START_TEST(test_printf_p_n) {
    char buff[200];
    char buff2[200];
    int val1 = 10;
    int val2, val3;
    int f1 = s21_sprintf(buff2,"%-20p %n", &val1, &val2);
    int s1 = sprintf(buff, "%-20p %n", &val1, &val3);
    ck_assert_int_eq(f1, s1);
    ck_assert_int_eq(val2, val3);
    ck_assert_str_eq(buff, buff2);
} END_TEST



Suite* sprintf_suite(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("sprintf");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_printf_d);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_printf_f);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_printf_e);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, s21_chars_f);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, s21_nums_f);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, s21_nums2_f);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_printf_o);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_printf_x);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_printf_p_n);
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, s21_nums3_f);
    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
//    //char ch = 'c';
//    int g = 298837248;
//    while (g >= 10)
//        g /= 10;
//    printf("g = %d\n", g);
    char buff[200];
    char buff2[200];
    //double d = 5.0;
//    int d = 10;
//    int e;
//    int f = s21_sprintf(buff2,  "%lc %lc %lc",1, 130, 200);
//    int ss = sprintf(buff, "%lc %lc %lc",'1', 130, 200);
//    printf("%s- %d\n", buff,ss);
//    printf("%s- %d\n", buff2,f);
    
    char* str = "     ''''asdfADASSA5522 ASasdaspqp112212''''";
    char* str1 = "99999999";
    char* str2 = to_lower(str);
    char* str3 = insert(str, str1, 3);
    printf("%s\n", str2);
    free(str2);
   

    printf("%s\n", str3);
    free(str3);
    char* str4 = trim(str, " '2");
    printf("%s\n", str4);
    free(str4);
    
//
   //free(str2);
    

//    long double temp = 100e-99;
//    int counter = 0, flag_plus = 0;
//    if (temp < 1) {
//        flag_plus = 0;
//        while (temp < 1) {
//            temp*= 10;
//            ++counter;
//        }
//
//    }
//    printf("t = %Lf, e = %d\n", temp, counter);
//    printf("%lf\n", 0.0/0.0);

//    _string data1;
//    _string_init(&data1);
//    double d = -5.898765;
//    double float_part, o;
//    float_part = modf(d, &o);
//    int temp = 0;
//    float_part < 0 ? float_part *= -1 : 1;
//    for (int i = 0; i < 5; ++i) {
//        float_part *= 10;
//        printf("fp = %f ", float_part);
//       // temp += (((int)(float_part / 10)) * pow(10, i));
//        //float_part /= 10;
//    }
//    temp = (int) float_part;
//    printf("test = %d\n", temp);
//
//
//
//    printf("%d", (int)o);
//    data1.pos = 6;
//    shuffle_str(&data1);
//    printf("%s\n" ,data1.buffer);
      int no_failed = 0;
      Suite *s;
      SRunner *runner;

      s = sprintf_suite();
      runner = srunner_create(s);

      srunner_run_all(runner, CK_NORMAL);
      no_failed = srunner_ntests_failed(runner);
      srunner_free(runner);
      return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

    return 0;
}
