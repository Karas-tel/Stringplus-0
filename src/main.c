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
//----------------------TEST SPRINTF----------------------
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
    s21_sprintf(s21_buffer2, "%f %f %f %f %f %f", 0.0/0.0,  1.0/0.0, 0.0/1.0, 1.0/0.0, -1.0/0.0, -0.0/1.0);
    sprintf(buffer2, "%f %f %f %f %f %f", 0.0/0.0,  1.0/0.0, 0.0/1.0,
                     1.0/0.0, -1.0/0.0, -0.0/1.0);
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

    int f = s21_sprintf(buff2, "blblbblblc%c%+4d%+.0d", '$', 10000, 0);
    int s = sprintf(buff, "blblbblblc%c%+4d%+.0d", '$', 10000, 0);
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
    f = s21_sprintf(buff2, "blblbblblc%c%+2.5d", '$', 10);
    s = sprintf(buff, "blblbblblc%c%+2.5d", '$', 10);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2,"%+.5d %+6.5d %+.5d %+6.5d %-2d %-2.5d %-4.d", 10, 10, -10, -10, 1, 10, 0);
    s = sprintf(buff,"%+.5d %+6.5d %+.5d %+6.5d %-2d %-2.5d %-4.d", 10, 10, -10, -10, 1, 10, 0);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "blblbblblc%c%+*.*d", '$', 2, 5, 10);
    s = sprintf(buff, "blblbblblc%c%+*.*d", '$', 2, 5, 10);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "%hd %hd", 32768, -10000000);
    s = sprintf(buff, "%hd %hd", (short) 32768, (short)-10000000);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "%d %d", 2147483648, -21474836480);
    s = sprintf(buff, "%d %d", (int)2147483648, (int)-21474836480);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "%d %d", 2147483648, -21474836480);
    s = sprintf(buff, "%d %d", (int)2147483648, (int)-21474836480);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
    f = s21_sprintf(buff2, "%hu %hu", 65536, -65536);
    s = sprintf(buff, "%hu %hu", (unsigned short)65536, (unsigned short)-65536);
    ck_assert_int_eq(f, s);
    ck_assert_str_eq(buff, buff2);
//    f = s21_sprintf(buff2, "%lu", (long unsigned int) 18446744073709551615);
//    s = sprintf(buff, "%lu", (long unsigned int) 18446744073709551615);
//    ck_assert_int_eq(f, s);
//    ck_assert_str_eq(buff, buff2);
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
    char buff[200];
    char buff2[200];

    int f1 = s21_sprintf(buff2, "%4.4e %-3.5e %07e %+-.e ", 1000.0, -0.0000002, 0.0, 200e+100);
    int s1 = sprintf(buff, "%4.4e %-3.5e %07e %+-.e ", 1000.0, -0.0000002, 0.0, 200e+100);
    ck_assert_int_eq(f1, s1);
    ck_assert_str_eq(buff, buff2);
    int f2 = s21_sprintf(buff2, "%4.4E %-3.5E %07E %+-.E", 1000.0, -0.0000002, 0.0, 200e+100);
    int s2 = sprintf(buff, "%4.4E %-3.5E %07E %+-.E", 1000.0, -0.0000002, 0.0, 200e+100);
    ck_assert_int_eq(f2, s2);
    ck_assert_str_eq(buff, buff2);

//   int f3 = s21_sprintf(buff2, "%LE %-E %E % E", (long double)0.0/0.0, 0.0/0.0, -1.0/0.0, 1.0/0.0);
//  int s3 = sprintf(buff, "%LE %-E %E % E", (long double)0.0/0.0, 0.0/0.0, -1.0/0.0, 1.0/0.0);
//   ck_assert_int_eq(f3, s3);
//   ck_assert_str_eq(buff, buff2);
} END_TEST

START_TEST(test_printf_g) {
    char buff[200];
    char buff2[200];
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

START_TEST(test_printf_s_c) {
    char data[100];
    char data1[100];
    sprintf(data, "|%32s|\n", "111");
    s21_sprintf(data1, "|%32s|\n", "111");
    ck_assert_str_eq(data, data1);
    sprintf(data, "%10c %-10c", 'a', 'b');
    s21_sprintf(data1, "%10c %-10c", 'a', 'b');
    ck_assert_str_eq(data, data1);
    sprintf(data, "|%32s|\n", "abc");
        s21_sprintf(data1, "|%32s|\n", "abc");
        ck_assert_str_eq(data, data1);
        int c = s21_sprintf(data, "|%.03s|\n", "hello");
        int d = sprintf(data1, "|%.03s|\n", "hello");
        ck_assert_int_eq(c, d);
} END_TEST

Suite* sprintf_suite(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("sprintf");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_printf_d);


    tcase_add_test(tc_core, test_printf_f);

    tcase_add_test(tc_core, test_printf_e);

    tcase_add_test(tc_core, test_printf_g);

    tcase_add_test(tc_core, s21_chars_f);

    tcase_add_test(tc_core, s21_nums_f);

    tcase_add_test(tc_core, s21_nums2_f);

    tcase_add_test(tc_core, test_printf_o);

    tcase_add_test(tc_core, test_printf_x);

    tcase_add_test(tc_core, test_printf_p_n);

    tcase_add_test(tc_core, s21_nums3_f);
    tcase_add_test(tc_core, test_printf_s_c);
    suite_add_tcase(s, tc_core);
    return s;
}
//-----------------TEST to_upper(lower) trim insert---------------
START_TEST(test_upper_lower) {
    char* buff = "ASDFGHJK1234!@#$";
    char* buff2 = "asdfghjk1234!@#$";
    char* buff3 = to_lower(buff);
    ck_assert_str_eq(buff2, buff3);
    free(buff3);
    buff3 = to_upper(buff2);
    ck_assert_str_eq(buff, buff3);
    free(buff3);
    buff2 = NULL;
    buff3 = to_upper(buff2);
    ck_assert_ptr_null(buff3);
    buff2 = NULL;
    buff3 = to_lower(buff2);
    ck_assert_ptr_null(buff3);
    buff3 = to_upper("");
    ck_assert_str_eq("", buff3);
    free(buff3);
    buff3 = to_lower("");
    ck_assert_str_eq("", buff3);
    free(buff3);
} END_TEST

START_TEST(test_insert) {
    char* buff = "0123456789";
    char* buff2 = "9999";
    char* buff3 = insert(buff, buff2, 0);
    ck_assert_str_eq("99990123456789", buff3);
    free(buff3);
    buff3 = insert(buff, buff2, 2);
    ck_assert_str_eq("01999923456789", buff3);
    free(buff3);
    buff3 = insert(buff, buff2, 25);
    ck_assert_ptr_null(buff3);

} END_TEST

START_TEST(test_trim) {
    char* buff = "     ''''asdfADASSA5522 ASasdaspqp112212''''";
    char* buff2 = " '2";
    char* buff3 = trim(buff, buff2);
    ck_assert_str_eq("asdfADASSA5522 ASasdaspqp11221", buff3);
    free(buff3);
    buff = "                   ";
    buff2 = " ";
    buff3 = trim(buff, buff2);
    ck_assert_str_eq("", buff3);
    free(buff3);
    buff = NULL;
    buff2 = " ";
    buff3 = trim(buff, buff2);
    ck_assert_ptr_null(buff3);

} END_TEST

Suite* additional_func_suite(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("additional_func");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_upper_lower);
    tcase_add_test(tc_core, test_insert);
    tcase_add_test(tc_core, test_trim);
    suite_add_tcase(s, tc_core);
    return s;
}

////------------TEST STRING.H-----------------------------
//START_TEST(test_memchr) {
//    const char* buff = "ASDFGHJK1234!@#$";
//    char* buff2 = s21_memchr(buff, 'G', 5);
//    char* buff3 = memchr(buff, 'G', 5);
//    ck_assert_str_eq(buff2, buff3);
//    buff2 = s21_memchr(buff, 'G', 4);
//    ck_assert_ptr_null(buff2);
//    buff2 = s21_memchr("", 'G', 5);
//    ck_assert_ptr_null(buff2);
//    buff2 = s21_memchr(buff, '\0', 25);
//    buff3 = memchr(buff, '\0', 25);
//    ck_assert_str_eq(buff2, buff3);
//} END_TEST
//
//START_TEST(test_memcmp) {
//    const char* buff = "ASDFGHJK1234!@#$";
//    const char* buff1 = "ASDFGHJK1234!@#$";
//    ck_assert_int_eq(memcmp(buff, buff1, 0), s21_memcmp(buff, buff1, 0));
//    ck_assert_int_eq(memcmp(buff, buff1, 10), s21_memcmp(buff, buff1, 10));
//    buff = " ";
//    buff1 = "ASDFGHJK1234!@#$";
//    ck_assert_int_eq(memcmp(buff, buff1, 0), s21_memcmp(buff, buff1, 0));
//    ck_assert_int_eq(memcmp(buff, buff1, 10), s21_memcmp(buff, buff1, 10));
//    buff = "";
//    buff1 = "";
//    ck_assert_int_eq(memcmp(buff, buff1, 0), s21_memcmp(buff, buff1, 0));
//    ck_assert_int_eq(memcmp(buff, buff1, 10), s21_memcmp(buff, buff1, 10));
//
//    buff = "ASDFGHJK1234!@#$/0asd";
//    buff1 = "A/0SDFGHJK1234!@#$";
//    ck_assert_int_eq(memcmp(buff, buff1, 100), s21_memcmp(buff, buff1, 100));
//
//} END_TEST
//
//START_TEST(test_memcpy) {
//    const char* src = "ASDFGHJK1234!@#$";
//    char* dest1[16];
//    char* dest2[16];
//   // ck_assert_str_eq(memcpy(dest, src, 100), s21_memcpy(dest, src, 100));
//    char* res1 = memcpy(dest1, src, 5);
//    char* res2 = s21_memcpy(dest2, src, 5);
//    res1 = memcpy(dest1, src, 100);
//    res2 = s21_memcpy(dest2, src, 100);
//    ck_assert_str_eq(res1, res2);
//
//} END_TEST
//
//START_TEST(test_memmove) {
//    const char* src = "ASDFGHJK1234!@#$";
//    char* dest1[16];
//    char* dest2[16];
//
//    char* res1 = memmove(dest1, src, 5);
//    char* res2 = s21_memmove(dest2, src, 5);
//    ck_assert_str_eq(res1, res2);
//    res1 = memmove(dest1, src, 100);
//    res2 = s21_memmove(dest2, src, 100);
//    ck_assert_str_eq(res1, res2);
//} END_TEST
//
//
//START_TEST(test_memset) {
//    char str[16] = "ASDFGHJK1234";
//    ck_assert_str_eq(memset(str, 'a', 0), s21_memset(str, 'a', 0));
//    ck_assert_str_eq(memset(str, '\0', 10), s21_memset(str, '\0', 10));
//} END_TEST
//
//
//Suite* main_func_suite(void) {
//    Suite* s;
//    TCase* tc_core;
//    s = suite_create("main_func");
//    tc_core = tcase_create("core");
//    tcase_add_test(tc_core, test_memchr);
//    tcase_add_test(tc_core, test_memcmp);
//    tcase_add_test(tc_core, test_memcpy);
//    tcase_add_test(tc_core, test_memmove);
//    tcase_add_test(tc_core, test_memset);
//    suite_add_tcase(s, tc_core);
//    return s;
//}


int main() {
//    //char ch = 'c';
//    int g = 298837248;
//    while (g >= 10)
//        g /= 10;
////    printf("g = %d\n", g);
//    char *memcpy_res;
//     char str5[] = "1112151ergergfg515";
//     size_t n_cpy = s21_strlen(str5);
//     char str6[n_cpy];
////     memcpy_res = s21_memcpy(memcpy_res, str5, 100);
////     printf("memcpy_res = %s\n", memcpy_res);
//     memcpy_res = memcpy(memcpy_res, str5, 100);
//     printf("strcpy ORIGINAL = %s\n", memcpy_res);
//     printf("\n");

//    char buff[200];
//    char buff2[200];
//    s21_sprintf(buff, "%+010.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0, 5.54454545, 5.9999999999, 5.54454545);
//    sprintf(buff2, "%+010.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0, 5.54454545, 5.9999999999, 5.54454545);
//    printf("|%s|\n", buff);
//    printf("|%s|\n", buff2);
//    wchar_t* w_temp = L"прLLO";
//    //unsigned long w = L'森';
//    char* temp = calloc(1024, sizeof(char));
//    int s = wctomb(temp, *(w_temp + 1));
//    
//    printf("%d=|%s|\n",s, temp);
//        char str1[512];
//        char str2[512];
//    
//        char *format = "This is a simple wide char %-10ls";
//     
//        int a = s21_sprintf(str1, format, w_temp);
//       int b = sprintf(str2, format, w_temp);
//    printf("%d = |%s|\n", a, str1);
//    printf("%d = |%s|\n", b, str2);
//    
    //printf("%d\n", INT_MAX);
    //double d = 5.0;
//    int d = 10;
//    int e;

//    const char* src = "ASDFGHJK1234!@#$";
//    char* dest = "ASDFGHJK1234!@#$";
//    memcpy(dest, src, 100);
//    printf("dest = %s|\n", dest);
//    int f = s21_sprintf(buff2,  "blblbblblc%c%+4d%+.0d", '$', 10000, 0);
//    int ss = sprintf(buff, "blblbblblc%c%+4d%+.0d", '$', 10000, 0);
//    printf("%s- %d\n", buff,ss);
//    printf("%s- %d\n", buff2,f);
//
//    char* str = "        ";
//    char* str1 = "99999999";
//    char* str2 = to_upper(str);
//    char* str3 = insert(str, str1, 50);
//    printf("%s\n", str2);
//    free(str2);
//
//
//    printf("str3 = %s\n", str3);
//    free(str3);
//    char* str4 = trim(str, " '2");
//    printf("|%s|\n", str4);
//    free(str4);
//    char* str_null = NULL;
//
//   // strlen(str_null);
//
//  // free(str2);
//
//
////    long double temp = 100e-99;
////    int counter = 0, flag_plus = 0;
////    if (temp < 1) {
////        flag_plus = 0;
////        while (temp < 1) {
////            temp*= 10;
////            ++counter;
////        }
////
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
   // printf("%s\n" ,data1.buffer);
    //size_t l = strlen(NULL);
    Suite* tests[] = {
        sprintf_suite(),
        additional_func_suite(),
      //  main_func_suite(),
        NULL
    };
    int no_failed = 0;
    for (int i = 0; tests[i]; ++i) {
        SRunner *runner;
        runner = srunner_create(tests[i]);
        srunner_set_fork_status(runner, CK_NOFORK);
        srunner_run_all(runner, CK_NORMAL);
        no_failed += srunner_ntests_failed(runner);
        srunner_free(runner);
    }
    if (no_failed == 0)
        printf("TEST OK\n");

    return 0;
}
