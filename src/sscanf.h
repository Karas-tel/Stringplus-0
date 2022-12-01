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

typedef enum { TRUE, FALSE } _bool;
typedef enum { L_SIZE, L_BIG_SIZE, H_SIZE, NO_SIZE } size_variable;

struct Pattern {
  _bool recording;
  int width;
  size_variable size_var;
  specifier spec;
};

int s21_sscanf(const char *string, const char *format, ...);
int va_s21_sscanf(const char *string, const char *format, va_list scanf_arg);
int s21_skip(const char *string, const char *format);
int skip_space(const char *str);

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