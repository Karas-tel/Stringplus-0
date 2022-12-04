#include <check.h>
//#include "check.h"
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "sscanf.h"
//#include "test_data.h"

START_TEST(sscanf_test_e) {
  float e1 = 0, e2 = 0;
  int r1 = 0, r2 = 0;

  r1 = sscanf("123e34", "%e", &e1);
  r2 = s21_sscanf("123e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e34", "%e", &e1);
  r2 = s21_sscanf("12e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.345e-34", "%9e", &e1);
  r2 = s21_sscanf("123.345e-34", "%9e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.345e34", "%8e", &e1);
  r2 = s21_sscanf("123.345e34", "%8e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_l) {
  int r1 = 0, r2 = 0;
  unsigned long lu1 = 0, lu2 = 0;
  long ld1 = 0, ld2 = 0;
  // wchar_t lc1, lc2, ls1[100], ls2[100];

  //   r1 = sscanf("a", "%lc", &lc1);
  //   r2 = s21_sscanf("a", "%lc", &lc2);
  //   ck_assert_int_eq(lc1, lc2);
  //   ck_assert_int_eq(r1, r2);

  //   r1 = sscanf("ab", "%*c%lc", &lc1);
  //   r2 = s21_sscanf("ab", "%*c%lc", &lc2);
  //   ck_assert_int_eq(lc1, lc2);
  //   ck_assert_int_eq(r1, r2);

  r1 = sscanf("12345", "%lu", &lu1);
  r2 = s21_sscanf("12345", "%lu", &lu2);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12345", "%ld", &ld1);
  r2 = s21_sscanf("12345", "%ld", &ld2);
  ck_assert_int_eq(ld1, ld2);
  ck_assert_int_eq(r1, r2);

  //   r1 = sscanf("kraken", "%9ls", ls1);
  //   r2 = s21_sscanf("kraken", "%9ls", ls2);
  //   ck_assert_int_eq(wcscmp(ls1, ls2), 0);
  //   ck_assert_int_eq(r1, r2);

  //   r1 = sscanf("kraken", "%ls", ls1);
  //   r2 = s21_sscanf("kraken", "%ls", ls2);
  //   ck_assert_int_eq(wcscmp(ls1, ls2), 0);
  //   ck_assert_int_eq(r1, r2);

  //   r1 = sscanf("kraken", "%2ls", ls1);
  //   r2 = s21_sscanf("kraken", "%2ls", ls2);
  //   ck_assert_int_eq(wcscmp(ls1, ls2), 0);
  //   ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_L) {
  int r1 = 0, r2 = 0;
  long double Lf1 = 0, Lf2 = 0;

  r1 = sscanf("123.45", "%Lf", &Lf1);
  r2 = s21_sscanf("123.45", "%Lf", &Lf2);
  ck_assert_msg((int)Lf1 == (int)Lf2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_u) {
  int r1 = 0, r2 = 0;
  unsigned u1 = 0, u2 = 0;

  r1 = sscanf("", "%u", &u1);
  r2 = s21_sscanf("", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0x123", "%u", &u1);
  r2 = s21_sscanf("-0x123", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+0x123", "%2u", &u1);
  r2 = s21_sscanf("+0x123", "%2u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+123", "%u", &u1);
  r2 = s21_sscanf("+123", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+z123", "%u", &u1);
  r2 = s21_sscanf("+z123", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x12345", "%2u", &u1);
  r2 = s21_sscanf("0x12345", "%2u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%u", &u1);
  r2 = s21_sscanf("123.456", "%u", &u2);
  ck_assert_msg(u1 == u2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_h) {
  int r1 = 0, r2 = 0;
  unsigned short hu1 = 0, hu2 = 0;

  r1 = sscanf("12345", "%hu", &hu1);
  r2 = s21_sscanf("12345", "%hu", &hu2);
  ck_assert_int_eq(hu1, hu2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_s) {
  int r1 = 0, r2 = 0;
  char s1[100], s2[100];

  r1 = sscanf("werty kraken", "%*s%2s", s1);
  r2 = s21_sscanf("werty kraken", "%*s%2s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("\nwerty kraken", "%*s%10s", s1);
  r2 = s21_sscanf("\nwerty kraken", "%*s%10s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("   werty kraken", "%*s%s", s1);
  r2 = s21_sscanf("   werty kraken", "%*s%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("", "%s", s1);
  r2 = s21_sscanf("", "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("\0", "%s", s1);
  r2 = s21_sscanf("\0", "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("   weartewrsthxffdtsrhdfghdfghdfghdfghdfghdfghfdgпывапывапывапы",
              "%s", s1);
  r2 = s21_sscanf(
      "   weartewrsthxffdtsrhdfghdfghdfghdfghdfghdfghfdgпывапывапывапы", "%s",
      s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_f) {
  int r1 = 0, r2 = 0;
  float f1 = 0, f2 = 0;

  r1 = sscanf("12e-3", "%f", &f1);
  r2 = s21_sscanf("12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e11", "%5f", &f1);
  r2 = s21_sscanf("12e11", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12e-3", "%f", &f1);
  r2 = s21_sscanf("-12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12e-11", "%f", &f1);
  r2 = s21_sscanf("-12e-11", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e-111", "%5f", &f1);
  r2 = s21_sscanf("12e-111", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e-111", "%6f", &f1);
  r2 = s21_sscanf("12e-111", "%6f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+12e-3", "%f", &f1);
  r2 = s21_sscanf("+12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e+3", "%f", &f1);
  r2 = s21_sscanf("12e+3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e3", "%4f", &f1);
  r2 = s21_sscanf("12e3", "%f4", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e3", "%3f", &f1);
  r2 = s21_sscanf("12e3", "%3f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("2 12e3", "1 %4f", &f1);
  r2 = s21_sscanf("2 12e3", "1 %4f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123.45", "%f", &f1);
  r2 = s21_sscanf("-123.45", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12.345", "%5f", &f1);
  r2 = s21_sscanf("-12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12.345", "%5f", &f1);
  r2 = s21_sscanf("12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  int i1 = -1, i2 = -1;
  char c1, c2;
  f1 = 0;
  f2 = 0;
  r1 = sscanf("z 21", "%f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf("z 21", "%f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(".z 21", "%f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf(".z 21", "%f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(".z 21", "%3f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf(".z 21", "%3f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0.z 21", "%3f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf("0.z 21", "%3f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  // double d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
  // r1 = sscanf("12.345 -12.345 12e3", "%5lf %5lf %3lf", &d1, &d3, &d5);
  // r2 = s21_sscanf("12.345 -12.345 12e3", "%5lf %5lf %3lf", &d2, &d4, &d6);
  // ck_assert_double_eq(d1, d2);
  // ck_assert_double_eq(d3, d4);
  // ck_assert_double_eq(d5, d6);
  // ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_o) {
  int r1 = 0, r2 = 0;
  unsigned o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0;
  long unsigned int o7 = 0, o8 = 0, o9 = 0, o10 = 0;
  short unsigned int o11 = 0, o12 = 0;

  r1 = sscanf("12345678", "%3o", &o1);
  r2 = s21_sscanf("12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+12345678", "%3o", &o1);
  r2 = s21_sscanf("+12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("012345678", "%3o", &o1);
  r2 = s21_sscanf("012345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12345678", "%3o", &o1);
  r2 = s21_sscanf("-12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%o", &o1);
  r2 = s21_sscanf("123.456", "%o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("45 011 000 041", "%o%*o %o%o", &o1, &o3, &o5);
  r2 = s21_sscanf("45 011 000 041", "%o%*o %o%o", &o2, &o4, &o6);
  ck_assert_uint_eq(o1, o2);
  ck_assert_uint_eq(o3, o4);
  ck_assert_uint_eq(o5, o6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+36 -0123 -59", "%o %o %o", &o1, &o3, &o5);
  r2 = s21_sscanf("+36 -0123 -59", "%o %o %o", &o2, &o4, &o6);
  ck_assert_uint_eq(o1, o2);
  ck_assert_uint_eq(o3, o4);
  ck_assert_uint_eq(o5, o6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("34 -123456 055", "%2o -%3o 456%02o", &o1, &o3, &o5);
  r2 = s21_sscanf("34 -123456 055", "%2o -%3o 456%02o", &o2, &o4, &o6);
  ck_assert_uint_eq(o1, o2);
  ck_assert_uint_eq(o3, o4);
  ck_assert_uint_eq(o5, o6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x9 -0xa2 0xBa1", "%ho %lo %lo", &o11, &o7, &o9);
  r2 = s21_sscanf("0x9 -0xa2 0xBa1", "%ho %lo %lo", &o12, &o8, &o10);
  ck_assert_uint_eq(o11, o12);
  ck_assert_uint_eq(o7, o8);
  ck_assert_uint_eq(o9, o10);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("10 12345678", "%ho %lo", &o11, &o7);
  r2 = s21_sscanf("10 12345678", "%ho %lo", &o12, &o8);
  ck_assert_uint_eq(o11, o12);
  ck_assert_uint_eq(o7, o8);
  ck_assert_uint_eq(o9, o10);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_x) {
  int r1 = 0, r2 = 0;
  unsigned x1 = 0, x2 = 0;
  unsigned x3 = 0, x4 = 0;
  unsigned short x5 = 0, x6 = 0;
  unsigned long x7 = 0, x8 = 0;

  r1 = sscanf("0x12345", "%2x", &x1);
  r2 = s21_sscanf("0x12345", "%2x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("abcdef", "%x", &x1);
  r2 = s21_sscanf("abcdef", "%x", &x2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("abcdef", "%hx", &x5);
  r2 = s21_sscanf("abcdef", "%hx", &x6);
  ck_assert_int_eq(x5, x6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("abcdef", "%lx", &x7);
  r2 = s21_sscanf("abcdef", "%lx", &x8);
  ck_assert_int_eq(x7, x8);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0gabcdef", "%hx", &x5);
  r2 = s21_sscanf("0gabcdef", "%hx", &x6);
  ck_assert_int_eq(x5, x6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0gabcdef", "%lx", &x7);
  r2 = s21_sscanf("0gabcdef", "%lx", &x8);
  ck_assert_int_eq(x7, x8);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("KRAKEN", "%X", &x1);
  r2 = s21_sscanf("KRAKEN", "%X", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("kraken", "%x", &x1);
  r2 = s21_sscanf("kraken", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x1234567890123456", "%x", &x1);
  r2 = s21_sscanf("0x1234567890123456", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%x", &x1);
  r2 = s21_sscanf("0x123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  char t1 = '0', t2 = '0';
  r1 = sscanf("0y923", "%x%c", &x1, &t1);
  r2 = s21_sscanf("0y923", "%x%c", &x2, &t2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(t1, t2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("y123", "%x", &x1);
  r2 = s21_sscanf("y123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0xy123", "%x", &x1);
  r2 = s21_sscanf("0xy123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+123456", "%x", &x1);
  r2 = s21_sscanf("+123456", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123456 0x12345", "%X %x", &x1, &x3);
  r2 = s21_sscanf("-123456 0x12345", "%X %x", &x2, &x4);
  ck_assert_uint_eq(x1, x2);
  ck_assert_uint_eq(x3, x4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("bcdef", "      %x", &x1);
  r2 = s21_sscanf("bcdef", "      %x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-bcdef", "%x", &x1);
  r2 = s21_sscanf("-bcdef", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("1 2 3 0123", "1 2 3 %x", &x1);
  r2 = s21_sscanf("1 2 3 0123", "1 2 3 %x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_i) {
  int r1 = 0, r2 = 0;
  int i1 = -1, i2 = -1, i3 = 0, i4 = 0, i5 = 0, i6 = 0;
  short int i7, i8, i9, i10, i11, i12;
  long int i20, i21, i22, i23, i24, i25;

  // short int
  r1 = sscanf("0x9 001  777", "%hi %hi %hi", &i7, &i9, &i11);
  r2 = s21_sscanf("0x9 001  777", "%hi %hi %hi", &i8, &i10, &i12);
  ck_assert_int_eq(i7, i8);
  ck_assert_int_eq(i9, i10);
  ck_assert_int_eq(i11, i12);
  ck_assert_int_eq(r1, r2);

  // long int
  r1 = sscanf("-0x80000001 017777777777 2234234234234", "%li %li %li", &i20,
              &i22, &i24);
  r2 = s21_sscanf("-0x80000001 017777777777 2234234234234", "%li %li %li", &i21,
                  &i23, &i25);
  ck_assert_int_eq(i20, i21);
  ck_assert_int_eq(i22, i23);
  ck_assert_int_eq(i24, i25);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0z123", "%hi", &i7);
  r2 = s21_sscanf("0z123", "%hi", &i8);
  ck_assert_int_eq(i7, i8);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0z123", "%li", &i20);
  r2 = s21_sscanf("0z123", "%li", &i21);
  ck_assert_int_eq(i20, i21);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0123", "%i", &i1);
  r2 = s21_sscanf("0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("09", "%i", &i1);
  r2 = s21_sscanf("09", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("s0123", "%i", &i1);
  r2 = s21_sscanf("s0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0s123", "%i", &i1);
  r2 = s21_sscanf("0s123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0xs123", "%i", &i1);
  r2 = s21_sscanf("0xs123", "%i", &i2);

  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0123", "%i", &i1);
  r2 = s21_sscanf("-0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%i", &i1);
  r2 = s21_sscanf("0x123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%4i", &i1);
  r2 = s21_sscanf("0x123", "%4i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%6i", &i1);
  r2 = s21_sscanf("0x123", "%6i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%2i", &i1);
  r2 = s21_sscanf("0x123", "%2i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123 5.     -0", "%i%2i %i", &i1, &i3, &i5);
  r2 = s21_sscanf("-123 5.     -0", "%i%2i %i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12 -10+3.5", "%3i %*i %i", &i1, &i3);
  r2 = s21_sscanf("-12 -10+3.5", "%3i %*i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-21474836481 2147483648", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-21474836481 2147483648", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-2147483648 -000", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-2147483648 -000", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("077 -034      089", "%i%i%i", &i1, &i3, &i5);
  r2 = s21_sscanf("077 -034      089", "%i%i%i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("077 -0234 01", "%2i 7 %i%*i", &i1, &i3);
  r2 = s21_sscanf("077 -0234 01", "%2i 7 %i%*i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("017777777777 020000000000", "%i %i", &i1, &i3);
  r2 = s21_sscanf("017777777777 020000000000", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-020000000000 -020000000001", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-020000000000 -020000000001", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i1, &i3);
  r2 = s21_sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x0 -0x3K0x02", "%i %i K %i", &i1, &i3, &i5);
  r2 = s21_sscanf("0x0 -0x3K0x02", "%i %i K %i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x7fffffff 0x80000000", "%i %i", &i1, &i3);
  r2 = s21_sscanf("0x7fffffff 0x80000000", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0x80000000 -0x80000001", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-0x80000000 -0x80000001", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("056 y 67", "%i %i %i", &i1, &i3, &i5);
  r2 = s21_sscanf("056 y 67", "%i %i %i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0xa2 y 02", "%i %*i %i", &i1, &i3);
  r2 = s21_sscanf("-0xa2 y 02", "%i %*i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_proc) {
  int r1 = 0, r2 = 0;
  char proc1[100] = {0}, proc2[100] = {0};

  r1 = sscanf("%123.456", "%%%9s", proc1);
  r2 = s21_sscanf("%123.456", "%%%9s", proc2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%%%9s", proc1);
  r2 = s21_sscanf("123.456", "%%%9s", proc2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_p) {
  int r1 = 0, r2 = 0;
  void *p1 = 0, *p2 = 0;

  r1 = sscanf("0x123", "%4p", &p1);
  r2 = s21_sscanf("0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0xz123", "%4p", &p1);
  r2 = s21_sscanf("0xz123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0zx123", "%4p", &p1);
  r2 = s21_sscanf("0zx123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("z0x123", "%4p", &p1);
  r2 = s21_sscanf("z0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-z0x123", "%4p", &p1);
  r2 = s21_sscanf("-z0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0x123", "%4p", &p1);
  r2 = s21_sscanf("-0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123", "%4p", &p1);
  r2 = s21_sscanf("123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x12345", "%p", &p1);
  r2 = s21_sscanf("0x12345", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%p", &p1);
  r2 = s21_sscanf("123.456", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_n) {
  int n1 = 0, n2 = 0, r1 = 0, r2 = 0;
  short int n3 = 0, n4 = 0;
  long int n5 = 0, n6 = 0;

  r1 = sscanf("123.456", "123%hn", &n3);
  r2 = s21_sscanf("123.456", "123%hn", &n4);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123123.456", "123%ln", &n5);
  r2 = s21_sscanf("123123.456", "123%ln", &n6);
  ck_assert_int_eq(n5, n6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%n", &n1);
  r2 = s21_sscanf("123.456", "%n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123123.456", "123%n", &n1);
  r2 = s21_sscanf("123123.456", "123%n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 123.456", "123 %n", &n1);
  r2 = s21_sscanf("123 123.456", "123 %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 123.456", "123 %n", &n1);
  r2 = s21_sscanf("123 123.456", "123 %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 123.456", "123 %n", &n1);
  r2 = s21_sscanf("123 123.456", "123 %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_d) {
  int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, res1 = 0, res2 = 0;
  short int d7 = 0, d8 = 0, d9 = 0, d10 = 0;
  long int d11 = 0, d12 = 0, d13 = 0, d14 = 0;

  //  test %d 1
  res1 = s21_sscanf("0123 456 789", "%d %*d %002d", &d1, &d2);
  res2 = sscanf("0123 456 789", "%d %*d %002d", &d3, &d4);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d3);
  ck_assert_int_eq(d2, d4);

  //  test %d 2
  d1 = 0;
  d2 = 0;
  d3 = 0;
  d4 = 0;
  res1 = 0;
  res2 = 0;
  res1 = s21_sscanf("+1234567", "%3d%d", &d1, &d2);
  res2 = sscanf("+1234567", "%3d%d", &d3, &d4);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d3);
  ck_assert_int_eq(d2, d4);

  //  test %d 3
  d1 = 0;
  d2 = 0;
  d3 = 0;
  d4 = 0;
  res1 = 0;
  res2 = 0;
  res1 = s21_sscanf("1234567", "123%3d%d", &d1, &d2);
  res2 = sscanf("1234567", "123%3d%d", &d3, &d4);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d3);
  ck_assert_int_eq(d2, d4);

  // test %d 4
  d1 = 0;
  d2 = 0;
  d3 = 0;
  d4 = 0;
  d5 = 0;
  d6 = 0;
  res1 = 0;
  res2 = 0;
  res1 = s21_sscanf("-123 -4", "%3d%d %3d", &d1, &d2, &d3);
  res2 = sscanf("-123 -4", "%3d%d %3d", &d4, &d5, &d6);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d4);
  ck_assert_int_eq(d2, d5);
  ck_assert_int_eq(d3, d6);

  // test %d 5
  d1 = 0;
  d2 = 0;
  d3 = 0;
  d4 = 0;
  res1 = 0;
  res2 = 0;
  res1 = s21_sscanf("-21474836481 2147483648", "%d %d", &d1, &d2);
  res2 = sscanf("-21474836481 2147483648", "%d %d", &d3, &d4);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d3);
  ck_assert_int_eq(d2, d4);

  // test %d 6
  d1 = 0;
  d2 = 0;
  d3 = 0;
  d4 = 0;
  res1 = 0;
  res2 = 0;
  res1 = s21_sscanf("-2147483648      -000", "%d %d", &d1, &d2);
  res2 = sscanf("-2147483648      -000", "%d %d", &d3, &d4);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d3);
  ck_assert_int_eq(d2, d4);

  // test %d 7
  d1 = 0;
  d2 = 0;
  d3 = 0;
  d4 = 0;
  res1 = 0;
  res2 = 0;
  res1 = s21_sscanf("1 hi", "%d %d", &d1, &d2);
  res2 = sscanf("1 hi", "%d %d", &d3, &d4);
  ck_assert_int_eq(d1, d3);
  ck_assert_int_eq(d2, d4);
  ck_assert_int_eq(res1, res2);

  // short int
  res1 = s21_sscanf("12 +123", "%hd %3hd", &d7, &d9);
  res2 = sscanf("12 +123", "%hd %3hd", &d8, &d10);
  ck_assert_int_eq(d7, d8);
  ck_assert_int_eq(d9, d10);
  ck_assert_int_eq(res1, res2);

  // long int
  res1 = s21_sscanf("123456678 +1231234567", "%ld %8ld", &d11, &d13);
  res2 = sscanf("123456678 +1231234567", "%ld %8ld", &d12, &d14);
  ck_assert_int_eq(d11, d12);
  ck_assert_int_eq(d13, d14);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_all) {
  int d1 = 0, d2 = 0, i1 = 0, i2 = 0, n1 = 0, n2 = 0, r1 = 0, r2 = 0;
  float e1 = 0, e2 = 0, E1 = 0, E2 = 0, f1 = 0, f2 = 0, g1 = 0, g2 = 0, G1 = 0,
        G2 = 0;
  unsigned o1 = 0, o2 = 0,  x1 = 0, x2 = 0, X1 = 0, X2 = 0;// u1 = 0, u2 = 0;
  void *p1 = 0, *p2 = 0;
  char s1[100], s2[100], c1, c2, proc1[100] = {0}, proc2[100] = {0};
  short hi1 = 0, hi2 = 0, hd1 = 0, hd2 = 0;
  unsigned long lo1 = 0, lo2 = 0, lu1 = 0, lu2 = 0;
  long double Le1 = 0, Le2 = 0, LE1 = 0, LE2 = 0, Lg1 = 0, Lg2 = 0, LG1 = 0,
              LG2 = 0;

  r1 = sscanf("123", "%d", &d1);
  r2 = s21_sscanf("123", "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 amogus", "%d%9s", &d1, s1);
  r2 = s21_sscanf("123 amogus", "%d%9s", &d2, s2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 amogus q", "%d %9s %c", &d1, s1, &c1);
  r2 = s21_sscanf("123 amogus q", "%d %9s %c", &d2, s2, &c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q", "%i %d %9s %c", &i1, &d1, s1, &c1);
  r2 = s21_sscanf("4 123 amogus q", "%i %d %9s %c", &i2, &d2, s2, &c2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34", "%i %d %9s %c %e", &i1, &d1, s1, &c1, &e1);
  r2 =
      s21_sscanf("4 123 amogus q 12e34", "%i %d %9s %c %e", &i2, &d2, s2, &c2, &e2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21", "%i %d %9s %c %e %E", &i1, &d1, s1, &c1,
              &e1, &E1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21", "%i %d %9s %c %e %E", &i2, &d2, s2,
                  &c2, &e2, &E2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  // r1 = sscanf("4 123 amogus q 12e34 43e21 13.37", "%i %d %9s %c %e %E %f", &i1, &d1,
  //             s1, &c1, &e1, &E1, &f1);
  // r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13,37", "%i %d %9s %c %e %E %f", &i2,
  //                 &d2, s2, &c2, &e2, &E2, &f2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28", "%i %d %9s %c %e %E %f %g", &i1,
              &d1, s1, &c1, &e1, &E1, &f1, &g1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28", "%i %d %9s %c %e %E %f %g",
                  &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 =
      sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
             "%i %d %9s %c %e %E %f %g %G", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                  "%i %d %9s %c %e %E %f %g %G", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
                  &G2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 =
      sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
             "%i %d %9s %c %e %E %f %g %G", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                  "%i %d %9s %c %e %E %f %g %G", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
                  &G2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101",
              "%i %d %9s %c %e %E %f %g %G %o", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
              &G1, &o1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101",
                  "%i %d %9s %c %e %E %f %g %G %o", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                  &g2, &G2, &o2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  // r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854",
  //             "%i%d%9s%c%e%E%f%g%G%o%u", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
  //             &G1, &o1, &u1);
  // r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854",
  //                 "%i%d%9s%c%e%E%f%g%G%o%u", &i2, &d2, s2, &c2, &e2, &E2, &f2,
  //                 &g2, &G2, &o2, &u2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(r1, r2);

  // r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab",
  //             "%i%d%9s%c%e%E%f%g%G%o%u%x", &i1, &d1, s1, &c1, &e1, &E1, &f1,
  //             &g1, &G1, &o1, &u1, &x1);
  // r2 =
  //     s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab",
  //                "%i%d%9s%c%e%E%f%g%G%o%u%x", &i2, &d2, s2, &c2, &e2, &E2, &f2,
  //                &g2, &G2, &o2, &u2, &x2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(x1, x2);
  // ck_assert_int_eq(r1, r2);

  // r1 = sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1,
  //     &o1, &u1, &x1, &X1);
  // r2 = s21_sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2, &G2,
  //     &o2, &u2, &x2, &X2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(x1, x2);
  // ck_assert_int_eq(X1, X2);
  // ck_assert_int_eq(r1, r2);

  // r1 = sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p1", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
  //     &G1, &o1, &u1, &x1, &X1, &p1);
  // r2 = s21_sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p2", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
  //     &G2, &o2, &u2, &x2, &X2, &p2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(x1, x2);
  // ck_assert_int_eq(X1, X2);
  // ck_assert_ptr_eq(p1, p2);
  // ck_assert_int_eq(r1, r2);

  // r1 = sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //     "shrek "
  //     "& amogus is sus?",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%%", &i1, &d1, s1, &c1, &e1, &E1, &f1,
  //     &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1);
  // r2 = s21_sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%%", &i2, &d2, s2, &c2, &e2, &E2, &f2,
  //     &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(x1, x2);
  // ck_assert_int_eq(X1, X2);
  // ck_assert_ptr_eq(p1, p2);
  // ck_assert_int_eq(n1, n2);
  // ck_assert_int_eq(r1, r2);

  // r1 = sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //     "shrek "
  //     "& amogus is sus?",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%9s%%", &i1, &d1, s1, &c1, &e1, &E1, &f1,
  //     &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1, proc1);
  // r2 = s21_sscanf(
  //     "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //     "shrek "
  //     "& amogus is sus?",
  //     "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%9s%%", &i2, &d2, s2, &c2, &e2, &E2, &f2,
  //     &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2, proc2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(x1, x2);
  // ck_assert_int_eq(X1, X2);
  // ck_assert_ptr_eq(p1, p2);
  // ck_assert_int_eq(n1, n2);
  // ck_assert_str_eq(proc1, proc2);
  // ck_assert_int_eq(r1, r2);

  // r1 = sscanf(
  //     "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //     "shrek "
  //     "& amogus is sus?",
  //     "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%", &i1,
  //     &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1,
  //     proc1);
  // r2 = s21_sscanf(
  //     "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
  //     "shrek "
  //     "& amogus is sus?",
  //     "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%", &i2,
  //     &d2, s2, &c2, &e2, &E2, &f2, &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2,
  //     proc2);
  // ck_assert_int_eq(i1, i2);
  // ck_assert_int_eq(d1, d2);
  // ck_assert_str_eq(s1, s2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_msg(e1 == e2, "floats not equals");
  // ck_assert_msg(E1 == E2, "floats not equals");
  // ck_assert_msg(f1 == f2, "floats not equals");
  // ck_assert_msg(g1 == g2, "floats not equals");
  // ck_assert_msg(G1 == G2, "floats not equals");
  // ck_assert_int_eq(o1, o2);
  // ck_assert_int_eq(u1, u2);
  // ck_assert_int_eq(x1, x2);
  // ck_assert_int_eq(X1, X2);
  // ck_assert_ptr_eq(p1, p2);
  // ck_assert_int_eq(n1, n2);
  // ck_assert_str_eq(proc1, proc2);
  // ck_assert_int_eq(r1, r2);

  r1 = sscanf(
      "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
      "shrek "
      "& amogus is sus?",
      "%*i %12hi %4hd %20s %c %3Le %7LE %*i %1f %9Lg %5LG %6lo %12lu %*x %11x %2X %10p %n %21s %"
      "%",
      &hi1, &hd1, s1, &c1, &Le1, &LE1, &f1, &Lg1, &LG1, &lo1, &lu1, &x1, &X1,
      &p1, &n1, proc1);
  r2 = s21_sscanf(
      "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
      "shrek "
      "& amogus is sus?",
      "%*i %12hi %4hd %20s %c %3Le %7LE %*i %1f %9Lg %5LG %6lo %12lu %*x %11x %2X %10p %n %21s %"
      "%",
      &hi2, &hd2, s2, &c2, &Le2, &LE2, &f2, &Lg2, &LG2, &lo2, &lu2, &x2, &X2,
      &p2, &n2, proc2);
  ck_assert_int_eq(hi1, hi2);
  ck_assert_int_eq(hd1, hd2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(lo1, lo2);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("String s21 test cases");

  //  sscanf
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s, tc1_1);
  tcase_add_test(tc1_1, sscanf_test_l);
  tcase_add_test(tc1_1, sscanf_test_L);
  tcase_add_test(tc1_1, sscanf_test_h);
  tcase_add_test(tc1_1, sscanf_test_n);
  tcase_add_test(tc1_1, sscanf_test_d);
  tcase_add_test(tc1_1, sscanf_test_i);
  tcase_add_test(tc1_1, sscanf_test_e);  //
  tcase_add_test(tc1_1, sscanf_test_f);  //
  tcase_add_test(tc1_1, sscanf_test_o);
  tcase_add_test(tc1_1, sscanf_test_x);
  tcase_add_test(tc1_1, sscanf_test_u);
  tcase_add_test(tc1_1, sscanf_test_s);
  tcase_add_test(tc1_1, sscanf_test_p);
  tcase_add_test(tc1_1, sscanf_test_proc);
  tcase_add_test(tc1_1, sscanf_test_all);  //

  return s;
}
int main(void) {
  Suite *s;
  SRunner *sr;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  return 0;
}
