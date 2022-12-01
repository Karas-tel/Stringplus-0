#include "sscanf.h"

#include <stdio.h>

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

_bool is_digit(char c) { return c <= '9' && c >= '0' ? TRUE : FALSE; }

int s21_skip(const char *string, const char *format) {
  int count = 0;
  while (*string == *format) {
    string++;
    format++;
    count++;
  }
  return count;
}

int skip_space(const char *str) {
  int count = 0;
  while (*str == ' ') {
    count++;
  }
  return count;
}

void print_pattern(struct Pattern patt) {
  printf("record: %s\n", patt.recording == TRUE ? "TRUE" : "FALSE");
  printf("width: %d\n", patt.width);
  printf("size_var: ");
  switch (patt.size_var) {
    case L_SIZE:
      printf("l\n");
      break;
    case L_BIG_SIZE:
      printf("L\n");
      break;
    case H_SIZE:
      printf("h\n");
      break;
    case NO_SIZE:
      printf("no\n");
      break;
    default:
      printf("ERROR\n");
      break;
  }
  printf("spec: ");
  switch (patt.spec) {
    case C_SPEC:
      printf("c\n");
      break;
    case D_SPEC:
      printf("d\n");
      break;
    case I_SPEC:
      printf("i\n");
      break;
    case E_SPEC:
      printf("e\n");
      break;
    case E_BIG_SPEC:
      printf("E\n");
      break;
    case F_SPEC:
      printf("f\n");
      break;
    case G_SPEC:
      printf("g\n");
      break;
    case G_BIG_SPEC:
      printf("G\n");
      break;
    case O_SPEC:
      printf("o\n");
      break;
    case S_SPEC:
      printf("s\n");
      break;
    case U_SPEC:
      printf("u\n");
      break;
    case X_SPEC:
      printf("x\n");
      break;
    case X_BIG_SPEC:
      printf("X\n");
      break;
    case P_SPEC:
      printf("p\n");
      break;
    case N_SPEC:
      printf("n\n");
      break;
    case DEF_SPEC:
      printf("%%\n");
      break;
    case ERROR_SPEC:
      printf("no specifier\n");
      break;
    default:
      printf("ERROR\n");
      break;
  }
}

int get_pattern(const char *format, struct Pattern *patt) {
  int displacement = 0;
  // displacement += skip_space(format);
  // format += displacement;
  if (*format == '%') {
    format++;
    displacement++;
    if (*format == '%') {
      patt->spec = DEF_SPEC;
      displacement++;
    } else {
      if (*format == '*') {
        patt->recording = FALSE;
        format++;
        displacement++;
      } else {
        patt->recording = TRUE;
      }
      if (is_digit(*format) == TRUE) {
        int size = 0;
        while (is_digit(*format) == TRUE) {
          size = *format - '0' + size * 10;
          format++;
          displacement++;
        }
        patt->width = size;
      } else {
        patt->width = 0;
      }
      switch (*format) {
        case 'l':
          patt->size_var = L_SIZE;
          format++;
          displacement++;
          break;
        case 'L':
          patt->size_var = L_BIG_SIZE;
          format++;
          displacement++;
          break;
        case 'h':
          patt->size_var = H_SIZE;
          format++;
          displacement++;
          break;
        default:
          patt->size_var = NO_SIZE;
          break;
      }
      switch (*format) {
        case 'c':
          patt->spec = C_SPEC;
          displacement++;
          break;
        case 'd':
          patt->spec = D_SPEC;
          displacement++;
          break;
        case 'i':
          patt->spec = I_SPEC;
          displacement++;
          break;
        case 'e':
          patt->spec = E_SPEC;
          displacement++;
          break;
        case 'E':
          patt->spec = E_BIG_SPEC;
          displacement++;
          break;
        case 'f':
          patt->spec = F_SPEC;
          displacement++;
          break;
        case 'g':
          patt->spec = G_SPEC;
          displacement++;
          break;
        case 'G':
          patt->spec = G_BIG_SPEC;
          displacement++;
          break;
        case 'o':
          patt->spec = O_SPEC;
          displacement++;
          break;
        case 's':
          patt->spec = S_SPEC;
          displacement++;
          break;
        case 'u':
          patt->spec = U_SPEC;
          displacement++;
          break;
        case 'x':
          patt->spec = X_SPEC;
          displacement++;
          break;
        case 'X':
          patt->spec = X_BIG_SPEC;
          displacement++;
          break;
        case 'p':
          patt->spec = P_SPEC;
          displacement++;
          break;
        case 'n':
          patt->spec = N_SPEC;
          displacement++;
          break;
        default:
          displacement = 0;
          patt->spec = ERROR_SPEC;
          break;
      }
    }
  }
  return displacement;
}

int s21_sscanf(const char *string, const char *format, ...) {
  va_list scanf_arg;
  va_start(scanf_arg, format);
  int scanf_argc = va_s21_sscanf(string, format, scanf_arg);
  va_end(scanf_arg);
  return scanf_argc;
}

int read_double(const char *string, struct Pattern patt, long double *d) {
  int displacement = 6;
  displacement += patt.width;  //
  sscanf(string, "%Lf", d);
  return displacement;
}

int read_char(const char *string, char *c) {
  int displacement = 1;
  *c = *string;
  return displacement;
}

int read_string(const char *string, struct Pattern patt, struct Buffer *buff) {
  int displacement = 0;
  switch (patt.spec) {
    case C_SPEC:
      char c;
      displacement = read_char(string, &c);
      buff->b_char = c;
      break;
    case D_SPEC:

      break;
    case E_SPEC:
    case E_BIG_SPEC:
    case F_SPEC:
    case G_SPEC:
    case G_BIG_SPEC:
      switch (patt.size_var) {
        case L_SIZE:
          long double d;  // double
          displacement = read_double(string, patt, &d);
          buff->b_double = d;
          break;
        case L_BIG_SIZE:
          long double ld;
          displacement = read_double(string, patt, &ld);
          buff->b_long_double = ld;
          break;
        default:
          long double f;  // float
          displacement = read_double(string, patt, &f);
          buff->b_float = f;
          break;
      }
      break;
    default:
      break;
  }
  return displacement;
}

int va_s21_sscanf(const char *string, const char *format, va_list scanf_arg) {
  int counter = 0;
  int form_diss = 0;
  int str_diss = 0;
  struct Pattern patt;
  struct Buffer buff;

  int skip = s21_skip(string, format);
  int form_diss_global = skip;  // + skip_space(format);
  int str_diss_global = skip;   // + skip_space(string);

  while ((form_diss = get_pattern(format + form_diss_global, &patt)) > 0 &&
         (str_diss = read_string(string + str_diss_global, patt, &buff)) > 0) {
    form_diss_global += form_diss;  // + skip_space(format);
    str_diss_global += str_diss;    // + skip_space(string);
    skip = s21_skip(string + str_diss_global, format + form_diss_global);
    form_diss_global += skip;  // + skip_space(format);
    str_diss_global += skip;   // + skip_space(string);
    if (patt.recording == TRUE) {
      switch (patt.spec) {
        case C_SPEC:
          char *c = (char *)va_arg(scanf_arg, char *);
          *c = buff.b_char;
          break;
        case D_SPEC:
          int *i = (int *)va_arg(scanf_arg, int *);
          *i = buff.b_int;
          switch (patt.size_var) {
            case L_SIZE:
              long int *li = (long int *)va_arg(scanf_arg, long int *);
              *li = buff.b_long_int;
              break;
            case H_SIZE:
              short int *si = (short int *)va_arg(scanf_arg, short int *);
              *si = buff.b_short_int;
              break;
            case NO_SIZE:
              int *i = (int *)va_arg(scanf_arg, int *);
              *i = buff.b_int;
              break;
            default:
              break;
          }
          break;
        case E_SPEC:
        case E_BIG_SPEC:
        case F_SPEC:
        case G_SPEC:
        case G_BIG_SPEC:
          switch (patt.size_var) {
            case L_SIZE:
              double *d = (double *)va_arg(scanf_arg, double *);
              *d = buff.b_double;
              break;
            case L_BIG_SIZE:
              long double *ld = (long double *)va_arg(scanf_arg, long double *);
              *ld = buff.b_long_double;
              break;
            case NO_SIZE:
              float *f = (float *)va_arg(scanf_arg, float *);
              *f = buff.b_float;
              break;
            default:
              break;
          }
          break;
        default:
          break;
      }
    }
  }
  va_end(scanf_arg);
  return counter;
}

int main(void) {
  // int age = 0, wei = 0;
  // double lf = 9.9;
  long double llf = 9.9;
  float f = 9.9;
  float ff = 9.9;
  char c = 't';
  s21_sscanf("Age:-85E-2 Age:-86E-2 Age:-87E-2i", "Age:%lf Age:%Lf Age:%f%c",
             &ff, &llf, &f, &c);
  printf("%f %Lf %f %c\n", ff, llf, f, c);
  // struct Pattern patt;
  // // print_pattern(patt);
  // const char *str = "%l%";

  // get_pattern(str, &patt);
  // print_pattern(patt);
  // while (*str != '\0') {
  //   printf("%c", *str++);
  // }
  return 0;
}
