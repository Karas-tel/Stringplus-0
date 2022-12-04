//
//  main.c
//  21_test
//
//  Created by mcbk on 09.11.2022.
//

#include <check.h>
#include <stdio.h>

#include "s21_sprintf.h"
#include "s21_string.h"
#include "test_data.h"

//----------------------TEST SPRINTF----------------------
START_TEST(s21_chars_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n',
              test2, '-', test3, test4, test5, test6, test7);
  sprintf(buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n', test2,
          '-', test3, test4, test5, test6, test7);
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
  sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
          -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
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
  s21_sprintf(s21_buffer2, "%f %f %f %f %f %f", 0.0 / 0.0, 1.0 / 0.0, 0.0 / 1.0,
              1.0 / 0.0, -1.0 / 0.0, -0.0 / 1.0);
  sprintf(buffer2, "%f %f %f %f %f %f", 0.0 / 0.0, 1.0 / 0.0, 0.0 / 1.0,
          1.0 / 0.0, -1.0 / 0.0, -0.0 / 1.0);
  ck_assert_str_eq(s21_buffer2, buffer2);

  char s21_buffer3[256] = {0};
  char buffer3[256] = {0};
  s21_sprintf(s21_buffer3, "%lg %lG %#lg %le", 234243.234, 8427348.234, 123.0,
              155.2);
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
  f = s21_sprintf(buff2, "%+.5d %+6.5d %+.5d %+6.5d %-2d %-2.5d %-4.d", 10, 10,
                  -10, -10, 1, 10, 0);
  s = sprintf(buff, "%+.5d %+6.5d %+.5d %+6.5d %-2d %-2.5d %-4.d", 10, 10, -10,
              -10, 1, 10, 0);
  ck_assert_int_eq(f, s);
  ck_assert_str_eq(buff, buff2);
  f = s21_sprintf(buff2, "blblbblblc%c%+*.*d", '$', 2, 5, 10);
  s = sprintf(buff, "blblbblblc%c%+*.*d", '$', 2, 5, 10);
  ck_assert_int_eq(f, s);
  ck_assert_str_eq(buff, buff2);
  f = s21_sprintf(buff2, "%hd %hd", 32768, -10000000);
  s = sprintf(buff, "%hd %hd", (short)32768, (short)-10000000);
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
}
END_TEST

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
  int f3 = s21_sprintf(buff2, "%+.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0,
                       -1.0, 5.54454545, 5.54454545, 5.54454545);
  int s3 = sprintf(buff, "%+.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0,
                   5.54454545, 5.54454545, 5.54454545);
  ck_assert_int_eq(f3, s3);
  ck_assert_str_eq(buff, buff2);
  int f5 = s21_sprintf(buff2, "%+010.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0,
                       -1.0, 5.54454545, 5.9999999999, 5.54454545);
  int s5 = sprintf(buff, "%+010.f % .f %+0.f %- 4.5f %-+5.4f ", -10000.0, -1.0,
                   5.54454545, 5.9999999999, 5.54454545);
  ck_assert_int_eq(f5, s5);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_printf_e) {
  char buff[200];
  char buff2[200];

  int f1 = s21_sprintf(buff2, "%4.4e %-3.5e %07e %+-.e ", 1000.0, -0.0000002,
                       0.0, 200e+100);
  int s1 = sprintf(buff, "%4.4e %-3.5e %07e %+-.e ", 1000.0, -0.0000002, 0.0,
                   200e+100);
  ck_assert_int_eq(f1, s1);
  ck_assert_str_eq(buff, buff2);
  int f2 = s21_sprintf(buff2, "%4.4E %-3.5E %07E %+-.E", 1000.0, -0.0000002,
                       0.0, 200e+100);
  int s2 = sprintf(buff, "%4.4E %-3.5E %07E %+-.E", 1000.0, -0.0000002, 0.0,
                   200e+100);
  ck_assert_int_eq(f2, s2);
  ck_assert_str_eq(buff, buff2);

  //   int f3 = s21_sprintf(buff2, "%LE %-E %E % E", (long double)0.0/0.0,
  //   0.0/0.0, -1.0/0.0, 1.0/0.0);
  //  int s3 = sprintf(buff, "%LE %-E %E % E", (long double)0.0/0.0, 0.0/0.0,
  //  -1.0/0.0, 1.0/0.0);
  //   ck_assert_int_eq(f3, s3);
  //   ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_printf_g) {
  char buff[200];
  char buff2[200];
  int f3 = s21_sprintf(buff2, "%#.0lg %lG %#lg %lg", 234243.234, 8427348.234,
                       123.0, 155.2);
  int s3 = sprintf(buff, "%#.0lg %lG %#lg %lg", 234243.234, 8427348.234, 123.0,
                   155.2);
  ck_assert_int_eq(f3, s3);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_printf_o) {
  char buff[100];
  char buff2[100];

  int f1 = s21_sprintf(buff2, "%o %5o %-20lo %10.20lo %#10.20lo %-#20.10lo",
                       21341324, 0, (long)1234341, (long)123423141,
                       (long)1234123, (long)1234341);
  int s1 =
      sprintf(buff, "%o %5o %-20lo %10.20lo %#10.20lo %-#20.10lo", 21341324, 0,
              (long)1234341, (long)123423141, (long)1234123, (long)1234341);
  ck_assert_int_eq(f1, s1);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_printf_x) {
  char buff[200];
  char buff2[200];

  int f1 = s21_sprintf(
      buff2, "%x %5x %-20lx %10.20lx %#10.20lx %-#20.10lx %#10.20lX %-#20.10lX",
      21341324, 0, (long)1234341, (long)123423141, (long)1234123, (long)1234341,
      (long)1234123, (long)1234341);
  int s1 = sprintf(
      buff, "%x %5x %-20lx %10.20lx %#10.20lx %-#20.10lx %#10.20lX %-#20.10lX",
      21341324, 0, (long)1234341, (long)123423141, (long)1234123, (long)1234341,
      (long)1234123, (long)1234341);
  ck_assert_int_eq(f1, s1);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_printf_p_n) {
  char buff[200];
  char buff2[200];
  int val1 = 10;
  int val2, val3;
  int f1 = s21_sprintf(buff2, "%-20p %n", &val1, &val2);
  int s1 = sprintf(buff, "%-20p %n", &val1, &val3);
  ck_assert_int_eq(f1, s1);
  ck_assert_int_eq(val2, val3);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

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
  sprintf(data, "%ls", L"assasdsad");
  s21_sprintf(data1, "%ls", L"assasdsad");
  ck_assert_str_eq(data, data1);
}
END_TEST

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
}
END_TEST

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
}
END_TEST

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
}
END_TEST

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

START_TEST(test_memchr) {
  const char* buff = "ASDFGHJK1234!@#$";
  char* buff2 = s21_memchr(buff, 'G', 5);
  char* buff3 = memchr(buff, 'G', 5);
  ck_assert_ptr_eq(buff2, buff3);
  ck_assert_str_eq(buff2, buff3);
  buff2 = s21_memchr(buff, 'G', 4);
  ck_assert_ptr_null(buff2);
  buff2 = s21_memchr("", 'G', 5);
  ck_assert_ptr_null(buff2);
  buff2 = s21_memchr(buff, '\0', 25);
  buff3 = memchr(buff, '\0', 25);
  ck_assert_ptr_eq(buff2, buff3);
  ck_assert_str_eq(buff2, buff3);
}
END_TEST

START_TEST(test_memcmp) {
  const char* buff = "ASDFGHJK1234!@#$";
  const char* buff1 = "ASDFGHJK1234!@#$";
  ck_assert_int_eq(memcmp(buff, buff1, 0), s21_memcmp(buff, buff1, 0));
  ck_assert_int_eq(memcmp(buff, buff1, 10), s21_memcmp(buff, buff1, 10));
  buff = " ";
  buff1 = "ASDFGHJK1234!@#$";
  ck_assert_int_eq(memcmp(buff, buff1, 0), s21_memcmp(buff, buff1, 0));
  ck_assert_int_eq(memcmp(buff, buff1, 10), s21_memcmp(buff, buff1, 10));
  buff = "";
  buff1 = "";
  ck_assert_int_eq(memcmp(buff, buff1, 0), s21_memcmp(buff, buff1, 0));
  ck_assert_int_eq(memcmp(buff, buff1, 10), s21_memcmp(buff, buff1, 10));

  buff = "ASDFGHJK1234!@#$/0asd";
  buff1 = "A/0SDFGHJK1234!@#$";
  ck_assert_int_eq(memcmp(buff, buff1, 100), s21_memcmp(buff, buff1, 100));
}
END_TEST

START_TEST(test_memcpy) {
  char str1[20] = "1112151ergergfg515";
  char str2[20] = "                    ";
  char str3[20] = "%hf*-5";
  char str4[20] = "                    ";
  char str5[30] = "";
  char str6[] = "4444";
  char str7[] = "123\0123";
  ck_assert_str_eq(s21_memcpy(str1, str2, 4), memcpy(str1, str2, 4));
  ck_assert_str_eq(s21_memcpy(str3, str4, 5), memcpy(str3, str4, 5));
  ck_assert_str_eq(s21_memcpy(str5, str6, 4), memcpy(str5, str6, 4));
  ck_assert_str_eq(s21_memcpy(str5, str7, 5), memcpy(str5, str7, 5));
}
END_TEST

START_TEST(test_memmove) {
  char str1[] = "11werwer15";
  char str2[s21_strlen(str1)];
  char str3[] = "s_21\n\t";
  char str4[s21_strlen(str3)];
  ck_assert_str_eq(s21_memmove(str2, str1, s21_strlen(str1)),
                   memmove(str2, str1, s21_strlen(str1)));
  ck_assert_str_eq(s21_memmove(str3, str4, s21_strlen(str3)),
                   memmove(str3, str4, s21_strlen(str3)));
}
END_TEST

START_TEST(test_memset) {
  char str[16] = "ASDFGHJK1234";
  ck_assert_str_eq(memset(str, 'a', 1), s21_memset(str, 'a', 1));
  ck_assert_str_eq(memset(str, '\0', 10), s21_memset(str, '\0', 10));
  ck_assert_str_eq(memset(str, 'k', 5), s21_memset(str, 'k', 5));
}
END_TEST

START_TEST(test_strcat) {
  char str1[30] = "what's go";
  char str11[30] = "ing on";
  char str2[30] = "Car";
  char str12[30] = "aaamba";
  ck_assert_str_eq(strcat(str1, str11), s21_strcat(str1, str11));
  ck_assert_str_eq(strcat(str2, str12), s21_strcat(str2, str12));
  char str001[30] = "opa";
  char str0011[30] = "popa";
  ck_assert_str_eq(strcat(str001, str0011), s21_strcat(str001, str0011));
}
END_TEST

START_TEST(test_strncat) {
  char str14[30] = "what's go";
  char str15[30] = "ing on";
  char str16[30] = "Car";
  char str17[30] = "aaamba";
  ck_assert_str_eq(strncat(str14, str15, 5), s21_strncat(str14, str15, 5));
  ck_assert_str_eq(strncat(str16, str17, 3), s21_strncat(str16, str17, 4));
}
END_TEST

START_TEST(test_strchr) {
  char str24[30] = "what's going on";
  ck_assert_str_eq(strchr(str24, 't'), s21_strchr(str24, 't'));
}
END_TEST

START_TEST(test_strcmp) {
  char str25[50] = "1112151515";
  char str26[50] = "11121sdfsdf";
  char str27[50] = "1112dasdasda12312sdas5";
  char str28[50] = "1112dasdasda12312sdas5";
  ck_assert_int_eq(strcmp(str25, str26), s21_strcmp(str25, str26));
  ck_assert_int_eq(strcmp(str27, str28), s21_strcmp(str27, str28));
}
END_TEST

START_TEST(test_strncmp) {
  char str29[50] = "1112151515";
  char str30[50] = "11121sdfsdf";
  char str31[50] = "1112d&*&a12312sdas5";
  char str32[50] = "1112d&*&a12312sdas5";
  ck_assert_int_eq(strncmp(str29, str30, 10), s21_strncmp(str29, str30, 10));
  ck_assert_int_eq(strncmp(str29, str30, 3), s21_strncmp(str29, str30, 3));
  ck_assert_int_eq(strncmp(str31, str32, 10), s21_strncmp(str31, str32, 10));
}
END_TEST

START_TEST(test_strcpy) {
  char str33[50] = "1112151ergergfg515";
  char str34[s21_strlen(str33)];
  ck_assert_str_eq(strcpy(str34, str33), s21_strcpy(str34, str33));
  char str333[50] = "1112151\0";
  char str344[50] = "ssssdddddfffffggggg1231231231231";
  ck_assert_str_eq(strcpy(str344, str333), s21_strcpy(str344, str333));
}
END_TEST

START_TEST(test_strncpy) {
  char str35[50] = "1112151ergergfg515";
  char str36[s21_strlen(str35)];
  ck_assert_str_eq(strncpy(str36, str35, 5), s21_strncpy(str36, str35, 5));
  char str351[50] = "1112151\0";
  char str361[50] = "ssssdddddfffffggggg1231231231231";
  ck_assert_str_eq(strncpy(str361, str351, 4), s21_strncpy(str361, str351, 4));
}
END_TEST

START_TEST(test_strcspn) {
  char str37[50] = "11121s5151s5";
  char str38[50] = "ddds";
  ck_assert_int_eq(strcspn(str37, str38), s21_strcspn(str37, str38));
  char str39[50] = "11121s5151s5";
  char str40[50] = "ddd";
  ck_assert_int_eq(strcspn(str39, str40), s21_strcspn(str39, str40));
}
END_TEST

START_TEST(test_strerror) {
  ck_assert_str_eq(strerror(0), s21_strerror(0));
  ck_assert_str_eq(strerror(55), s21_strerror(55));
  ck_assert_str_eq(strerror(-55), s21_strerror(-55));
}
END_TEST

START_TEST(test_strpbrk) {
  char str41[50] = "11121s5151s5";
  char str42[50] = "ddds";
  ck_assert_ptr_eq(strpbrk(str41, str42), s21_strpbrk(str41, str42));
  char str43[50] = "11121s5151s5";
  char str44[50] = "ddd";
  ck_assert_ptr_eq(strpbrk(str43, str44), s21_strpbrk(str43, str44));
}
END_TEST

START_TEST(test_strrchr) {
  char str45[50] = "what's going on";
  ck_assert_ptr_eq(strrchr(str45, 't'), s21_strrchr(str45, 't'));
  ck_assert_ptr_eq(strrchr(str45, 'c'), s21_strrchr(str45, 'c'));
}
END_TEST

START_TEST(test_strspn) {
  char str46[50] = "11121sssss1111110000111111111111111111111111111111";
  char str47[50] = "11121s";
  ck_assert_int_eq(strspn(str46, str47), s21_strspn(str46, str47));
  char str48[50] = "11121s5151s5";
  char str49[50] = "1dd";
  ck_assert_int_eq(strspn(str48, str49), s21_strspn(str48, str49));
  char str50[50] = "11121s5151s5";
  char str51[50] = "ddd";
  ck_assert_int_eq(strspn(str50, str51), s21_strspn(str50, str51));
}
END_TEST

START_TEST(test_strlen) {
  char str52[50] = "11121s5151s5";
  ck_assert_int_eq(strlen(str52), s21_strlen(str52));
}
END_TEST

START_TEST(test_strstr) {
  char str53[50] = "11121s5151s5";
  char str54[50] = "5151s";
  ck_assert_ptr_eq(strstr(str53, str54), s21_strstr(str53, str54));
  ck_assert_str_eq(strstr(str53, str54), s21_strstr(str53, str54));
  char str55[50] = "11121s5151s5";
  char str56[50] = "111";
  ck_assert_ptr_eq(strstr(str55, str56), s21_strstr(str55, str56));
  ck_assert_str_eq(strstr(str55, str56), s21_strstr(str55, str56));
}
END_TEST

START_TEST(test_strtok) {
  char str57[100] = "It's       not a     bug, it's a feature.";
  char str58[100] = "It's       not a     bug, it's a feature.";
  char* parser = " ,.";
  char* strOrigin = strtok(str57, parser);
  char* st21 = s21_strtok(str58, parser);
  while (strOrigin != NULL) {
    strOrigin = strtok(NULL, parser);
    st21 = s21_strtok(NULL, parser);
    ck_assert_pstr_eq(strOrigin, st21);
  }
}
END_TEST

Suite* main_func_suite(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("main_func");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_memchr);
  tcase_add_test(tc_core, test_memcmp);
  tcase_add_test(tc_core, test_memcpy);
  tcase_add_test(tc_core, test_memmove);
  tcase_add_test(tc_core, test_memset);
  tcase_add_test(tc_core, test_strcat);
  tcase_add_test(tc_core, test_strncat);
  tcase_add_test(tc_core, test_strchr);
  tcase_add_test(tc_core, test_strcmp);
  tcase_add_test(tc_core, test_strncmp);
  tcase_add_test(tc_core, test_strcpy);
  tcase_add_test(tc_core, test_strncpy);
  tcase_add_test(tc_core, test_strcspn);
  tcase_add_test(tc_core, test_strerror);
  tcase_add_test(tc_core, test_strpbrk);
  tcase_add_test(tc_core, test_strrchr);
  tcase_add_test(tc_core, test_strspn);
  tcase_add_test(tc_core, test_strlen);
  tcase_add_test(tc_core, test_strstr);
  tcase_add_test(tc_core, test_strtok);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  Suite* tests[] = {sprintf_suite(), additional_func_suite(), main_func_suite(),
                    NULL};
  int no_failed = 0;
  for (int i = 0; tests[i]; ++i) {
    SRunner* runner;
    runner = srunner_create(tests[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  if (no_failed == 0) printf("TEST OK\n");

  return 0;
}
