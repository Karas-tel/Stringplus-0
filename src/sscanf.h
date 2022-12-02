#ifndef SRC_SSCANF_H_
#define SRC_SSCANF_H_

#include <stdarg.h>

typedef enum {
  C_SPEC,
  D_SPEC,
  I_SPEC,
  E_SPEC,
  E_BIG_SPEC,
  F_SPEC,
  G_SPEC,
  G_BIG_SPEC,
  O_SPEC,
  S_SPEC,
  U_SPEC,
  X_SPEC,
  X_BIG_SPEC,
  P_SPEC,
  N_SPEC,
  DEF_SPEC,  // %
  ERROR_SPEC
} specifier;

typedef enum _bool { FALSE, TRUE } _bool;
typedef enum { L_SIZE, L_BIG_SIZE, H_SIZE, NO_SIZE } size_variable;

struct Pattern {
  _bool recording;
  int width;
  size_variable size_var;
  specifier spec;
};

struct Buffer {
  int b_int;
  char b_char;
  short int b_short_int;
  long int b_long_int;
  long double b_long_double;
  float b_float;
  double b_double;

  unsigned int b_u_int;
  unsigned short int b_u_short_int;
  unsigned long int b_u_long_int;
};

int s21_sscanf(const char *string, const char *format, ...);
int va_s21_sscanf(const char *string, const char *format, va_list scanf_arg);
int s21_skip(const char *string, const char *format);
int skip_space(const char *str);

int read_double(const char *string, struct Pattern patt, long double *d);
int read_char(const char *string, char *c);
int read_int(const char *string, long int *i);
int read_u_int8(const char *string, unsigned long int *i);
int read_u_int10(const char *string, unsigned long int *i);
int read_u_int16(const char *string, unsigned long int *i);
int read_string(const char *string, struct Pattern patt, struct Buffer *buff);

int get_pattern(const char *format, struct Pattern *patt);
void print_pattern(struct Pattern patt);
_bool is_digit(char c);
#endif  // SRC_SSCANF_H_

// Спецификатор формата
// "%c %d %i %e %E %f %g %G %o %s %u %x %X %p %n %%"

// Спецификатор формата для сканирующих функций следует прототипу:
// %[*][ширина][длина]спецификатор.

// Должно поддерживаться полное форматирование
// c учетом флагов, ширины, точности, модификаторов и типов преобразования.

// Спецификатор формата для печатающих функций следует прототипу:
// %[флаги][ширина][.точность][длина]спецификатор